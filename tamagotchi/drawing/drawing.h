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
void draw_rect(Coords origin, int width, int height, int border_thickness, uint16_t color, const uint16_t* bg_color);
void center_rect_in_rect(Coords* origin, uint32_t width, uint32_t height, uint32_t o_width, uint32_t o_height);
void center_text_in_rect(Coords* origin, uint32_t width, uint32_t height, uint32_t text_len);
void draw_text(int x, int y, const char* text, uint16_t color);