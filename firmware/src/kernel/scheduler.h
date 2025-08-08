#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

#define MAX_TASKS 4
#define STACK_SIZE 128

typedef enum {
    TASK_READY,
    TASK_RUNNING,
    TASK_BLOCKED,
    TASK_SUSPENDED
} task_state_t;

typedef struct {
    uint8_t id;
    task_state_t state;
    uint8_t priority;
    uint8_t* stack_ptr;
    uint8_t stack[STACK_SIZE];
    void (*task_func)(void);
} task_t;

// Scheduler functions
void scheduler_init(void);
uint8_t task_create(void (*func)(void), uint8_t priority);
void task_yield(void);
void task_delay(uint16_t ms);
void scheduler_start(void);

// Internal functions
void context_switch(void);
task_t* get_next_task(void);

#endif // SCHEDULER_H