# BLE Accelerometer Data Parser

## Overview
This program processes raw BLE (Bluetooth Low Energy) packets containing accelerometer data. It determines whether a BLE tag is **moving** or **stationary** based on accelerometer readings.

## Features
- Parses BLE packets to extract accelerometer data (X, Y, Z values)
- Identifies and skips iBeacon packets
- Calculates movement status based on accelerometer magnitude
- Prints parsed accelerometer data and motion status
- Works on Linux (Ubuntu) systems
- Implements error handling for invalid BLE packets

## Prerequisites
- A Linux-based system (Ubuntu recommended)
- GCC compiler installed
- Bluetooth adapter enabled on the system

## Installation
1. Clone the repository:
   ```sh
   git clone <repository-url>
   cd <repository-folder>
   ```
2. Compile the C program:
   ```sh
   gcc -o ble_scanner ble_scanner.c -lm
   ```

## Usage
Run the compiled executable:
```sh
./ble_scanner
```

## How It Works
1. The program reads BLE packets that contain accelerometer data.
2. It checks whether the packet is an **iBeacon**; if so, it ignores the packet.
3. If the packet contains accelerometer data, it extracts **X, Y, Z** values.
4. The acceleration magnitude is computed using:
   ```
   magnitude = sqrt(x * x + y * y + z * z);
   magnitude_in_g = magnitude / 16384;
   ```
5. If the magnitude is greater than **1.0g**, the tag is **Moving**, else it is **Stationary**.

## Expected Output
```
BLE Packet: 0201060303E1FF1216E1FFA10364FFF4000FFF003772A33F23AC
Parsed Data: x=-12, y=15, z=0
Motion Status: Moving

BLE Packet: 0201061AFF4C00021553594F4F4B534F4349414C444953544500000000E8
Cannot find accelerometer data in the packet (iBeacon).

BLE Packet: 0201060303E1FF1216E1FFA10364FFF60011FF003772A33F23AC
Parsed Data: x=3, y=7, z=-2
Motion Status: Stationary
```

## Error Handling
- **Invalid Packets**: The program checks if the packet matches expected formats.
- **iBeacon Packets**: These are ignored as they do not contain accelerometer data.
- **String Parsing Errors**: Ensures proper extraction of X, Y, Z values.

## Future Enhancements
- **Real-time BLE scanning support**
- **Logging system for accelerometer readings**
- **GUI-based motion status display**
- **Docker container support for portability**

## License
This project is released under the MIT License.

## Contributors
- Harsha Vardhan Katuri
