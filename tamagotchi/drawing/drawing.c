#include "LPC17xx.h"
#include "../GLCD/GLCD.h" 
#include "drawing.h"
#include "../GLCD/AsciiLib.h"
#include <string.h>

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
	// map a single pixel to a 5x5 area
	int real_x = x * PX_RT;
	int real_y = y * PX_RT;
	int i;
	for (i = 0; i < PX_RT; ++i) {
		LCD_DrawLine(real_x, real_y + i, real_x + PX_RT, real_y + i, color);
	}
}

void draw_image(int width, int height, const uint16_t* image_data) {
	Coords center = {0, 0};
	int i, j;
	center_rect_in_rect(&center, LCD_WIDTH / PX_RT, LCD_HEIGHT / PX_RT, width, height);
	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			draw_color_at(center.x + j, center.y + i, image_data[i*width+j]);
		}
	}
}

void draw_rect(Coords origin, int width, int height, int border_thickness, uint16_t color, const uint16_t* bg_color) {
	int i = 0;
	uint16_t bg_color_value = 0;
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
		bg_color_value = *bg_color;
		for (i = origin.y; i <= origin.y + height; ++i) {
			LCD_DrawLine(origin.x, i, origin.x + width, i, bg_color_value);
		} 
	}

}

void draw_char_expanded(uint16_t x, uint16_t y, char c, uint16_t charColor) {
	uint16_t i, j;
	uint8_t buffer[16], tmp_char;
	GetASCIICode(buffer,c);
	for(i=0; i<32; i += 2) {
		tmp_char = buffer[i / 2];
		for(j=0; j<16; j+=2) {
			if(((tmp_char >> (7 - (j / 2))) & 0x01) == 0x01) {
				LCD_SetPoint(x + j, y + i, charColor);
				LCD_SetPoint(x + j + 1, y + i, charColor);
				LCD_SetPoint(x + j, y + i + 1, charColor);
				LCD_SetPoint(x + j + 1, y + i + 1, charColor);
			}
		}
	}
}

#define FONT_WIDTH 16
#define FONT_HEIGHT 32

void draw_text(int x, int y, const char* text, uint16_t color) {
	char TempChar;
	do {
		TempChar = *text++;  
		draw_char_expanded(x, y, TempChar, color);    
		if(x < MAX_X - FONT_WIDTH) {
			x += FONT_WIDTH;
		} else if (y < MAX_Y - FONT_HEIGHT) {
			x = 0;
			y += FONT_HEIGHT;
		} else {
			x = 0;
			y = 0;
		}    
	} while (*text != 0);
}

void center_rect_in_rect(Coords* origin, uint32_t width, uint32_t height, uint32_t o_width, uint32_t o_height) {
	origin->x = origin->x + (width / 2) - (o_width / 2);
	origin->y = origin->y + (height / 2) - (o_height / 2);
}

void center_text_in_rect(Coords* origin, uint32_t width, uint32_t height, uint32_t text_len) {
	const uint32_t pixel_text_width = (text_len * FONT_WIDTH);
	const uint32_t pixel_text_height = FONT_HEIGHT;
	
	center_rect_in_rect(origin, width, height, pixel_text_width, pixel_text_height);
}
