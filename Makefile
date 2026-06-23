# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Iinclude

# Source Files
SRC = src/main.c \
      src/ble_parser.c \
      src/ble_utils.c \
      src/ble_logger.c

# Output Executable
TARGET = BLEParser.exe

# Math Library
LIBS = -lm

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run: all
	./$(TARGET)

clean:
	del /Q $(TARGET)

rebuild: clean all