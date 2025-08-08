# Spirit of Kiro - Games

Sample games and development SDK for the Spirit of Kiro platform.

## Game Development Kit (SDK)

The SDK provides everything needed to create games for the platform:

- **Graphics API**: 2D rendering functions
- **Input API**: Button and potentiometer handling
- **Audio API**: Sound generation and music
- **Memory Management**: Efficient resource allocation
- **Build Tools**: Compilation and packaging

## Sample Games

### 1. Snake Classic
- **Description**: Classic snake game with modern touches
- **Features**: Progressive difficulty, high scores
- **Memory Usage**: ~6KB flash, ~400B RAM

### 2. Pong Arcade
- **Description**: Two-player pong with AI opponent
- **Features**: Variable ball speed, score tracking
- **Memory Usage**: ~5KB flash, ~300B RAM

### 3. Space Invaders Mini
- **Description**: Simplified space shooter
- **Features**: Multiple enemy types, power-ups
- **Memory Usage**: ~7KB flash, ~500B RAM

### 4. Tetris Nano
- **Description**: Compact tetris implementation
- **Features**: Line clearing, level progression
- **Memory Usage**: ~8KB flash, ~600B RAM

## Game Structure

```
game-name/
├── src/
│   ├── main.cpp       # Game entry point
│   ├── game_logic.cpp # Core game mechanics
│   ├── graphics.cpp   # Rendering code
│   └── audio.cpp      # Sound effects
├── assets/
│   ├── sprites.h      # Sprite data
│   └── sounds.h       # Audio data
├── Makefile          # Build configuration
└── README.md         # Game documentation
```

## Development Guidelines

- **Memory Constraints**: Max 8KB flash, 512B RAM
- **Performance**: 60 FPS target on 16MHz Arduino
- **Graphics**: 1-bit monochrome, 128x64 resolution
- **Audio**: Single channel PWM sound