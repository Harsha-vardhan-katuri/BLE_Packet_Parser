# BLE Packet Parser

## Overview

BLE Packet Parser is a modular Embedded C project that parses BLE advertisement packets and extracts accelerometer data from custom sensor packets while identifying unsupported packet types such as iBeacon.

The project demonstrates professional firmware development practices including modular architecture, packet validation, logging, unit testing, and build automation.

---

## Features

- Parse BLE advertisement packets
- Detect iBeacon packets
- Extract X, Y, Z accelerometer values
- Motion detection using acceleration magnitude
- Packet validation
- Packet type detection
- Logging framework
- Unit testing
- Doxygen API documentation
- Makefile-based build system

---

## Folder Structure

```
BLE_Packet_Parser
│
├── include
│   ├── ble_config.h
│   ├── ble_logger.h
│   ├── ble_parser.h
│   ├── ble_types.h
│   └── ble_utils.h
│
├── src
│   ├── main.c
│   ├── ble_logger.c
│   ├── ble_parser.c
│   └── ble_utils.c
│
├── test
│   └── test_packets.c
│
├── docs
│
├── Doxyfile
├── Makefile
└── README.md
```

---

## Architecture

```
BLE Advertisement Packet

        │

        ▼

 Packet Validation

        │

        ▼

 Packet Type Detection

        │

        ▼

 BLE Packet Parser

        │

        ▼

 Accelerometer Data

        │

        ▼

 Motion Detection

        │

        ▼

 Console Output
```

---

## Supported Packet Types

| Packet Type | Supported |
|-------------|-----------|
| Sensor Packet | Yes |
| iBeacon | Yes |
| Unknown Packet | Yes |

---

## Build

Compile

```bash
mingw32-make
```

Run

```bash
mingw32-make run
```

Run Unit Tests

```bash
mingw32-make test
```

Clean

```bash
mingw32-make clean
```

---

## Sample Output

```
[INFO] BLE Packet Parser Started

[INFO] Sensor Packet

Parsed Data

X = -12

Y = 15

Z = -256

Motion : Stationary
```

---

## Unit Testing

Current test coverage includes:

- Valid packet
- Invalid packet
- Invalid length
- Invalid hex data
- NULL packet
- iBeacon packet

Example:

```
PASS Test 1

PASS Test 2

PASS Test 3

PASS Test 4

PASS Test 5

Passed 5/5 Tests
```

---

## Technologies Used

- Embedded C
- GCC (MinGW)
- VS Code
- Git
- GitHub
- Makefile
- Doxygen

---

## Future Improvements

- Support Eddystone packets
- Parse Manufacturer Specific Data
- BLE CRC validation
- Binary packet parser
- UART logging
- File logging
- Continuous Integration (GitHub Actions)

---

## Author

Katuri Harsha Vardhan

Firmware Engineer