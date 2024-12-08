BLE Packet Parser
This program parses BLE (Bluetooth Low Energy) packets to extract accelerometer data and determines motion status (moving or stationary).

Prerequisites
To run this program, you need:

A C compiler (e.g., gcc for Linux/macOS, MinGW for Windows).
How to Compile and Run
Linux/macOS
Open a terminal and navigate to the directory containing the files.

Compile the program:

bash
Copy code
gcc -o ble_packet_parser ble_packet_parser.c -lm
Run the program:

bash
Copy code
./ble_packet_parser
The program will display the BLE packet data and the motion status (either "Moving" or "Stationary").



