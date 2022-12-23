#include <stdint.h>

#define LCD_HEIGHT 320
#define LCD_WIDTH 240

#define PASS_TO_DRAWING(m) ((const uint16_t*)m)

struct Coords {
	uint8_t x;
	uint16_t y : 9;
} __attribute__((packed)) typedef Coords;

void draw_image(int width, int height, const uint16_t* image_data);
void draw_image_diff(int width, int height, const uint16_t* on_screen, const uint16_t* to_draw);
void draw_rect(Coords origin, int width, int height, int border_thickness, uint16_t color, const uint16_t* bg_color);
void center_rect_in_rect(Coords* origin, uint32_t width, uint32_t height, uint32_t o_width, uint32_t o_height);
void center_text_in_rect(Coords* origin, uint32_t width, uint32_t height, uint32_t text_len, uint8_t text_scale);
void draw_text(int x, int y, const char* text, uint16_t color, uint8_t scale);
void draw_batteries(uint8_t tot_bars, uint8_t full_bars);
void draw_battery_bars(Coords origin, uint8_t tot_bars, uint8_t full_bars);
