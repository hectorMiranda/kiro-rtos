#ifndef SPIRIT_KIRO_H
#define SPIRIT_KIRO_H

#include <stdint.h>

// Game lifecycle callbacks
typedef struct {
    void (*init)(void);
    void (*update)(float delta_time);
    void (*render)(void);
    void (*cleanup)(void);
} game_callbacks_t;

// Register game with the system
void register_game(const game_callbacks_t* callbacks);

// Graphics API
void draw_pixel(uint8_t x, uint8_t y, uint8_t color);
void draw_line(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color);
void draw_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color);
void draw_filled_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color);
void draw_circle(uint8_t x, uint8_t y, uint8_t r, uint8_t color);
void draw_sprite(uint8_t x, uint8_t y, const uint8_t* sprite, uint8_t w, uint8_t h);
void draw_text(uint8_t x, uint8_t y, const char* text, uint8_t color);
void clear_screen(void);

// Input API
uint8_t is_button_pressed(uint8_t button);
uint8_t is_button_just_pressed(uint8_t button);
uint8_t is_button_just_released(uint8_t button);
uint16_t get_potentiometer_value(void);

// Audio API
void play_tone(uint16_t frequency, uint16_t duration);
void play_note(uint8_t note, uint16_t duration);
void stop_audio(void);

// System API
uint32_t get_time_ms(void);
void delay_ms(uint16_t ms);
uint16_t get_free_memory(void);

// Button constants
#define BTN_UP    0
#define BTN_DOWN  1
#define BTN_LEFT  2
#define BTN_RIGHT 3
#define BTN_A     4
#define BTN_B     5

// Screen constants
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64

// Color constants
#define COLOR_BLACK 0
#define COLOR_WHITE 1

#endif // SPIRIT_KIRO_H