#include "LPC17xx.h"
#include "../GLCD/GLCD.h" 
#include "drawing.h"

void draw_instructions(const DrawInstruction* insns, uint32_t size) {
	DrawInstruction curr_insn;
	uint32_t i;
	for (i = 0; i < size; ++i) {
		curr_insn = insns[i];
		if (curr_insn.type == Point) {
			LCD_SetPoint(curr_insn.from.x, curr_insn.from.y, Black);
		} else if (curr_insn.type == Line) {
			LCD_DrawLine(curr_insn.from.x, curr_insn.from.y, curr_insn.to.x, curr_insn.to.y, Black);
		}
	}
}

#define PX_RT 5

void draw_color_at(int x, int y, uint16_t color) {
	// map a single pixel to a 4x4 area
	int real_x = x * PX_RT;
	int real_y = y * PX_RT;
	int i;
	for (i = 0; i < PX_RT; ++i) {
		LCD_DrawLine(real_x, real_y + i, real_x + PX_RT, real_y + i, color);
	}
}

void draw_image(int width, int height, const uint16_t* image_data) {
	Coords center = {(LCD_WIDTH / PX_RT) / 2, (LCD_HEIGHT / PX_RT) / 2};
	int i, j;
	center.x -= width / 2;
	center.y -= height / 2;
	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			draw_color_at(center.x + j, center.y + i, image_data[i*width+j]);
		}
	}
}

void draw_rect(Coords origin, int width, int height, int border_thickness, uint16_t color, uint16_t* bg_color) {
	int i = 0;
	for (i = 0; i < border_thickness; ++i) {
		LCD_DrawLine(origin.x, origin.y, origin.x + width, origin.y, color); // top line
		LCD_DrawLine(origin.x, origin.y + height, origin.x + width, origin.y + height, color); // bottom line
		LCD_DrawLine(origin.x, origin.y, origin.x, origin.y + height, color); // left line
		LCD_DrawLine(origin.x + width, origin.y, origin.x + width, origin.y + height, color); // right line
		origin.x++;
		origin.y++;
		width -= 2;
		height -= 2;
	}
	if (bg_color) {
		// TODO: bg
	}
}
