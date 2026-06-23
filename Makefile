# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Iinclude

# Source Files
SRC = src/main.c \
      src/ble_parser.c \
      src/ble_utils.c \
      src/ble_logger.c

# Test Sources
TEST_SRC = test/test_packets.c \
           src/ble_parser.c \
           src/ble_utils.c \
           src/ble_logger.c

# Output Files
TARGET = BLEParser.exe
TEST_TARGET = BLEParser_Test.exe

# Libraries
LIBS = -lm

# Always execute these targets
.PHONY: all run test clean rebuild

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run: all
	./$(TARGET)

test:
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_TARGET) $(LIBS)
	./$(TEST_TARGET)

clean:
	del /Q $(TARGET) $(TEST_TARGET)

rebuild: clean all