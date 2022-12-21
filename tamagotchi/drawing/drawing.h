#include <stdint.h>

#define LCD_HEIGHT 320
#define LCD_WIDTH 240

#define PASS_TO_DRAWING(m) ((const uint16_t*)m)

enum DrawType {
	Point = 0,
	Line = 1
} typedef DrawType;

struct Coords {
	uint8_t x;
	uint16_t y : 9;
} __attribute__((packed)) typedef Coords;

struct DrawInstruction {
	Coords from;
	Coords to;
	DrawType type : 1;
} __attribute__((packed)) typedef DrawInstruction;

void draw_instructions(const DrawInstruction* insns, uint32_t size);
void draw_image(int width, int height, const uint16_t* image_data);
void draw_rect(Coords origin, int width, int height, int border_thickness, uint16_t color, uint16_t* bg_color);
