#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BUFFER_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 8)

// Display initialization and control
void display_init(void);
void display_clear(void);
void display_update(void);
void display_power(uint8_t on);

// Drawing functions
void display_pixel(uint8_t x, uint8_t y, uint8_t color);
void display_line(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color);
void display_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color);
void display_circle(uint8_t x, uint8_t y, uint8_t r, uint8_t color);

// Text rendering
void display_char(uint8_t x, uint8_t y, char c, uint8_t color);
void display_string(uint8_t x, uint8_t y, const char* str, uint8_t color);

// Sprite rendering
void display_sprite(uint8_t x, uint8_t y, const uint8_t* sprite, uint8_t w, uint8_t h);

// Buffer access
uint8_t* get_display_buffer(void);

#endif // DISPLAY_H