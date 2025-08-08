# MinuxStation - Windows Client

C++ desktop application for flashing games and managing the MinuxStation device.

## Features

- **Game Flashing**: Upload games to Arduino Nano
- **Device Management**: Monitor device status and memory
- **Game Library**: Local game collection management
- **Serial Communication**: Direct device interaction
- **Firmware Updates**: RTOS and bootloader updates

## Technology Stack

- **Language**: C++17
- **GUI Framework**: Qt6 or Dear ImGui
- **Serial Communication**: libserial or Windows API
- **Build System**: CMake
- **Compiler**: MSVC or MinGW

## Architecture

```
windows-client/
├── src/
│   ├── core/          # Core application logic
│   ├── ui/            # User interface components
│   ├── serial/        # Serial communication
│   ├── flash/         # Flashing algorithms
│   └── utils/         # Utility functions
├── include/           # Header files
├── resources/         # UI resources and assets
└── tests/            # Unit tests
```

## Key Components

- **FlashManager**: Handles game uploading process
- **SerialPort**: Arduino communication interface
- **GameLibrary**: Local game management
- **DeviceMonitor**: Real-time device status
- **UpdateManager**: Firmware update handling

## Building

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

## Requirements

- Windows 10/11
- Visual Studio 2019+ or MinGW
- Qt6 (if using Qt GUI)
- CMake 3.16+