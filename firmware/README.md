# MinuxStation - Firmware

Custom RTOS implementation for Arduino Nano optimized for gaming applications.

## Architecture

- **Kernel**: Preemptive multitasking scheduler
- **Display Driver**: Optimized SSD1306 OLED driver
- **Input System**: Button debouncing and potentiometer handling
- **Audio System**: PWM-based sound generation
- **Game Engine**: Lightweight 2D graphics and physics
- **Memory Management**: Efficient allocation for 2KB RAM

## Components

- `src/kernel/` - RTOS core functionality
- `src/drivers/` - Hardware abstraction layer
- `src/engine/` - Game engine components
- `src/bootloader/` - Custom bootloader for game loading
- `examples/` - Sample applications and games

## Building

[Placeholder for build instructions]

## Memory Layout

```
Flash (32KB):
├── Bootloader (4KB)
├── RTOS Kernel (8KB)
├── Game Engine (12KB)
└── User Game (8KB)

RAM (2KB):
├── Kernel Stack (512B)
├── Display Buffer (1KB)
├── Game Memory (512B)
```