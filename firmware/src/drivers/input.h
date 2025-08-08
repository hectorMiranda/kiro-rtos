#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>

// Button definitions
#define BTN_UP    0
#define BTN_DOWN  1
#define BTN_LEFT  2
#define BTN_RIGHT 3
#define BTN_A     4
#define BTN_B     5
#define BTN_COUNT 6

// Potentiometer
#define POT_PIN A0

typedef struct {
    uint8_t current;
    uint8_t previous;
    uint8_t pressed;
    uint8_t released;
} button_state_t;

// Input system functions
void input_init(void);
void input_update(void);

// Button functions
uint8_t button_is_pressed(uint8_t button);
uint8_t button_just_pressed(uint8_t button);
uint8_t button_just_released(uint8_t button);

// Potentiometer functions
uint16_t pot_read_raw(void);
uint8_t pot_read_scaled(uint8_t max_value);

// Input state
extern button_state_t buttons[BTN_COUNT];

#endif // INPUT_H