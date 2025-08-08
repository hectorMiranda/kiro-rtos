#include "../sdk/minuxstation.h"

#define MAX_SNAKE_LENGTH 50
#define GRID_SIZE 4

typedef struct {
    uint8_t x, y;
} point_t;

// Game state
static point_t snake[MAX_SNAKE_LENGTH];
static uint8_t snake_length;
static point_t food;
static int8_t dx, dy;
static uint16_t score;
static uint8_t game_over;

void game_init(void) {
    // Initialize snake
    snake_length = 3;
    snake[0] = {64, 32}; // Head
    snake[1] = {60, 32};
    snake[2] = {56, 32};
    
    // Initial direction
    dx = GRID_SIZE;
    dy = 0;
    
    // Place first food
    food = {32, 16};
    score = 0;
    game_over = 0;
}

void game_update(float delta_time) {
    if (game_over) {
        if (is_button_just_pressed(BTN_A)) {
            game_init(); // Restart
        }
        return;
    }
    
    // Handle input
    if (is_button_just_pressed(BTN_UP) && dy == 0) {
        dx = 0; dy = -GRID_SIZE;
    }
    if (is_button_just_pressed(BTN_DOWN) && dy == 0) {
        dx = 0; dy = GRID_SIZE;
    }
    if (is_button_just_pressed(BTN_LEFT) && dx == 0) {
        dx = -GRID_SIZE; dy = 0;
    }
    if (is_button_just_pressed(BTN_RIGHT) && dx == 0) {
        dx = GRID_SIZE; dy = 0;
    }
    
    // Move snake
    static uint32_t last_move = 0;
    if (get_time_ms() - last_move > 200) {
        // Move body
        for (int i = snake_length - 1; i > 0; i--) {
            snake[i] = snake[i - 1];
        }
        
        // Move head
        snake[0].x += dx;
        snake[0].y += dy;
        
        // Wrap around screen
        if (snake[0].x >= SCREEN_WIDTH) snake[0].x = 0;
        if (snake[0].x < 0) snake[0].x = SCREEN_WIDTH - GRID_SIZE;
        if (snake[0].y >= SCREEN_HEIGHT) snake[0].y = 0;
        if (snake[0].y < 0) snake[0].y = SCREEN_HEIGHT - GRID_SIZE;
        
        // Check food collision
        if (snake[0].x == food.x && snake[0].y == food.y) {
            snake_length++;
            score += 10;
            
            // Generate new food
            food.x = (get_time_ms() % (SCREEN_WIDTH / GRID_SIZE)) * GRID_SIZE;
            food.y = (get_time_ms() % (SCREEN_HEIGHT / GRID_SIZE)) * GRID_SIZE;
            
            play_tone(800, 100);
        }
        
        // Check self collision
        for (int i = 1; i < snake_length; i++) {
            if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                game_over = 1;
                play_tone(200, 500);
                break;
            }
        }
        
        last_move = get_time_ms();
    }
}

void game_render(void) {
    clear_screen();
    
    if (game_over) {
        draw_text(32, 20, "GAME OVER", COLOR_WHITE);
        draw_text(32, 35, "Press A", COLOR_WHITE);
        return;
    }
    
    // Draw snake
    for (int i = 0; i < snake_length; i++) {
        draw_filled_rect(snake[i].x, snake[i].y, GRID_SIZE, GRID_SIZE, COLOR_WHITE);
    }
    
    // Draw food
    draw_filled_rect(food.x, food.y, GRID_SIZE, GRID_SIZE, COLOR_WHITE);
    
    // Draw score
    char score_text[16];
    // Simple integer to string conversion
    uint8_t digits = 0;
    uint16_t temp = score;
    do {
        score_text[digits++] = '0' + (temp % 10);
        temp /= 10;
    } while (temp > 0);
    score_text[digits] = '\0';
    
    // Reverse string
    for (int i = 0; i < digits / 2; i++) {
        char c = score_text[i];
        score_text[i] = score_text[digits - 1 - i];
        score_text[digits - 1 - i] = c;
    }
    
    draw_text(0, 0, score_text, COLOR_WHITE);
}

void game_cleanup(void) {
    // Nothing to clean up
}

// Game registration
static const game_callbacks_t snake_game = {
    .init = game_init,
    .update = game_update,
    .render = game_render,
    .cleanup = game_cleanup
};

// Entry point
int main(void) {
    register_game(&snake_game);
    return 0;
}