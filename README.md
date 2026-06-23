# BLE Packet Parser

A modular **Embedded C** project that parses BLE (Bluetooth Low Energy) advertisement packets, validates packet integrity, identifies packet types, extracts accelerometer data, and determines device motion. The project demonstrates professional firmware development practices such as modular architecture, packet validation, logging, unit testing, build automation, and API documentation.

---

# Project Overview

BLE advertisement packets contain information broadcast by BLE devices. This project demonstrates how a firmware application can:

- Validate incoming BLE packets
- Detect packet type
- Extract accelerometer values (X, Y, Z)
- Calculate motion status
- Log parser activities
- Perform automated unit testing
- Generate API documentation using Doxygen

This project was developed using **Embedded C**, **GCC (MinGW)**, **VS Code**, **Makefile**, and **Doxygen**.

---

# Features

- Parse BLE Advertisement Packets
- Detect Sensor Packets
- Detect iBeacon Packets
- Packet Validation
- Packet Type Detection
- Extract Accelerometer Data (X, Y, Z)
- Motion Detection using Acceleration Magnitude
- Modular Software Architecture
- Logging Framework
- Unit Testing
- Makefile-based Build System
- Doxygen API Documentation

---

# Project Workflow

```text
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
             Accelerometer Data Extraction
                          │
                          ▼
                 Motion Detection
                          │
                          ▼
                   Logger Output
```

---

# Software Architecture

```text
                      main.c
                         │
                         ▼
                  ble_parser.c
              ┌──────────┼──────────┐
              │          │          │
              ▼          ▼          ▼
      validate_packet() detect_packet_type() parse_ble_packet()
                         │
                         ▼
                    ble_utils.c
              ┌──────────┼──────────┐
              │          │          │
              ▼          ▼          ▼
        is_ibeacon() is_moving() motion_to_string()
                         │
                         ▼
                    ble_logger.h
                         │
                         ▼
                     Console Log
```

---

# Folder Structure

```text
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
│   ├── ble_parser.c
│   ├── ble_utils.c
│   └── ble_logger.c
│
├── test
│   └── test_packets.c
│
├── docs
│
├── html
│
├── latex
│
├── Doxyfile
├── Makefile
├── README.md
├── LICENSE
└── .gitignore
```

---

# BLE Packet Format

Example Sensor Packet

```text
0201060303E1FF1216E1FFA10364FFF4000FFF003772A33F23AC
```

Example iBeacon Packet

```text
0201061AFF4C00021553594F4F4B534F4349414C444953544500000000E8
```

The parser identifies the packet type before extracting sensor information.

---

# Supported Packet Types

| Packet Type | Status |
|-------------|--------|
| Sensor Packet | Supported |
| iBeacon Packet | Supported |
| Unknown Packet | Supported |

---

# Motion Detection

Acceleration magnitude is calculated using:

```text
Magnitude = √(X² + Y² + Z²)
```

Converted into **g**:

```text
Magnitude(g) = Magnitude / 16384
```

If

```text
Magnitude(g) > Motion Threshold
```

Device Status:

```text
Moving
```

Otherwise

```text
Stationary
```

---

# Logging Framework

The project uses logging macros instead of directly calling `printf()`.

Available log levels:

```c
LOG_INFO()

LOG_WARNING()

LOG_ERROR()

LOG_DEBUG()
```

Example Output

```text
[INFO] Sensor Packet

[INFO] Accelerometer Extracted

[WARNING] iBeacon Packet

[ERROR] Invalid Packet Length
```

---

# Build Instructions

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

Rebuild

```bash
mingw32-make rebuild
```

---

# Unit Testing

The project includes automated unit tests covering:

- Valid Sensor Packet
- iBeacon Packet
- Invalid Packet Length
- NULL Packet
- Invalid Packet Data

Run tests:

```bash
mingw32-make test
```

Example Output

```text
[PASS] Test 1

[PASS] Test 2

[PASS] Test 3

[PASS] Test 4

[PASS] Test 5

Passed 5/5 Tests
```

---

# Doxygen Documentation

Generate API documentation

```bash
doxygen Doxyfile
```

Generated documentation can be viewed from:

```text
html/index.html
```

The documentation includes:

- File Documentation
- Function Documentation
- Data Structures
- Enums
- Macros
- Call Graphs (if Graphviz is installed)

---

# Sample Output

```text
[INFO] BLE Packet Parser Started

[INFO] Sensor Packet

[INFO] Accelerometer Extracted

Parsed Data

X = -12

Y = 15

Z = -256

Motion : Stationary

---------------------------------

[WARNING] iBeacon Packet

---------------------------------

[INFO] Parsing Completed
```

---

# Technologies Used

- Embedded C
- GCC (MinGW)
- Visual Studio Code
- Git
- GitHub
- Makefile
- Doxygen

---

# Future Improvements

- Support Eddystone Packets
- Parse Manufacturer Specific Data
- Binary BLE Packet Parsing
- UART Logging
- File Logging
- JSON Output Support
- BLE CRC Verification
- Unity Test Framework
- Continuous Integration using GitHub Actions

---

# Screenshots

Add your screenshots inside an **images/** folder.

Example:

```text
images/
├── project_structure.png
├── parser_output.png
├── unit_test_output.png
├── doxygen_output.png
```

Then display them like this:

```markdown
## Project Structure

![Project Structure](images/project_structure.png)

## Parser Output

![Parser Output](images/parser_output.png)

## Unit Test Results

![Unit Test](images/unit_test_output.png)

## Doxygen Documentation

![Doxygen](images/doxygen_output.png)
```

---

# Learning Outcomes

This project demonstrates:

- Modular Embedded C Programming
- BLE Advertisement Packet Parsing
- Packet Validation
- Packet Type Detection
- Data Extraction
- Motion Detection Algorithm
- Logging Framework
- Unit Testing
- Build Automation using Makefile
- API Documentation using Doxygen
- Git Version Control
- Professional Project Organization

---

# Author

**Katuri Harsha Vardhan**

Firmware Engineer

GitHub: https://github.com/harsha-vardhan-katuri

---

# License

This project is licensed under the **MIT License**.