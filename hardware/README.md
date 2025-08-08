# Spirit of Kiro - Hardware Design

PCB design and 3D-printable enclosure for the Spirit of Kiro gaming platform.

## PCB Specifications

- **Size**: 60mm x 40mm (compact handheld form factor)
- **Layers**: 2-layer PCB for cost efficiency
- **Components**: Through-hole and SMD mixed design
- **Power**: USB-C connector with battery option

## Component Layout

```
┌─────────────────────────────┐
│  [OLED]     [Arduino Nano]  │
│                             │
│ [BTN1] [BTN2]    [POT]     │
│ [BTN3] [BTN4]              │
│ [BTN5] [BTN6]    [BUZZER]  │
│                             │
│ [GPIO PINS]    [USB-C]     │
└─────────────────────────────┘
```

## Files

- `pcb/` - KiCad project files
- `enclosure/` - 3D printable case design
- `assembly/` - Assembly instructions and BOM
- `gerbers/` - Production files

## Bill of Materials

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Nano | 1 | Microcontroller board |
| SSD1306 OLED | 1 | 128x64 I2C display |
| Tactile Buttons | 6 | 6x6mm momentary switches |
| Potentiometer | 1 | 10kΩ rotary pot |
| Piezo Buzzer | 1 | 5V active buzzer |
| USB-C Connector | 1 | Power and programming |
| Pin Headers | 1 set | GPIO expansion |

## Enclosure Design

- **Material**: PLA/PETG 3D printing
- **Design**: Ergonomic handheld form factor
- **Features**: Button cutouts, screen window, port access
- **Assembly**: Snap-fit design with optional screws