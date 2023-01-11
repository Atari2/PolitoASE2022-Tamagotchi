from PIL import Image
import os
import glob
import argparse

# the LCD should be rgb565 but using rgb555 for the conversion makes it yield better color accuracy.
# so either the emulator is wrong or the LCD specification is wrong.
# once I can try it on the actual board I'll see which one is right.

parser = argparse.ArgumentParser(description='Convert images to C arrays.')
parser.add_argument('-b', '--board', action='store_true', help='Generate code for the board.', default=False)
args = parser.parse_args()

def round_to_white(v):
    if v >= 240:
        return 0xFF
    return v

def make_rgb_555(r, g, b):
    r = ((round_to_white(r) & 0xFF) >> 3)
    g = ((round_to_white(g) & 0xFF) >> 3)
    b = ((round_to_white(b) & 0xFF) >> 3)
    return f'0x{((r << 11) | (g << 5) | b):04X}'

def make_rgb_565(r, g, b):
    r = ((round_to_white(r) & 0xFF) >> 3)
    g = ((round_to_white(g) & 0xFF) >> 2)
    b = ((round_to_white(b) & 0xFF) >> 3)
    return f'0x{((r << 11) | (g << 5) | b):04X}'

with open('tamagotchi/images/imagedata.h', 'w') as h:
    h.write('#include <stdint.h>\n')
    for filename in glob.glob('images/*.jpg'):
        basename, _ = os.path.splitext(filename)
        basename = os.path.split(basename)[-1]
        with open(f'tamagotchi/images/{basename}.c', 'w') as f:
            f.write('#include <stdint.h>\n')
            with Image.open(filename) as im:
                w, z = im.size
                matrix_str = f'const uint16_t {basename}Matrix[{z}][{w}] = {{\n'
                h.write(f'#define {basename.upper()}_WIDTH {w}\n')
                h.write(f'#define {basename.upper()}_HEIGHT {z}\n')
                h.write(f'extern const uint16_t {basename}Matrix[{basename.upper()}_HEIGHT][{basename.upper()}_WIDTH];\n')
                for i in range(z):
                    matrix_str += '\t{'
                    for j in range(w):
                        r,g,b = im.getpixel((j, i))
                        matrix_str += f'{make_rgb_565(r, g, b) if args.board else make_rgb_555(r, g, b)}{", " if j < w - 1 else " "}'
                    matrix_str += '},\n'
                matrix_str += '};\n'
                f.write(matrix_str)
