# BLE Packet Parser

This program parses BLE (Bluetooth Low Energy) packets to extract accelerometer data and determines motion status (moving or stationary).

## Prerequisites

To run this program, you need:
- A C compiler (e.g., `gcc` for Linux/macOS, MinGW for Windows).

---

## How to Compile and Run

### Linux/macOS
1. Open a terminal and navigate to the directory containing the files.
2. Compile the program:
   ```bash
   gcc -o ble_packet_parser ble_packet_parser.c -lm
3. Run the program:
   ```bash
   ./ble_packet_parser
