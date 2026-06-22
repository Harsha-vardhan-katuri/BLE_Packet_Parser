#ifndef BLE_LOGGER_H
#define BLE_LOGGER_H

#include <stdio.h>

#define LOG_INFO(...) \
    printf("[INFO] " __VA_ARGS__)

#define LOG_WARNING(...) \
    printf("[WARNING] " __VA_ARGS__)

#define LOG_ERROR(...) \
    printf("[ERROR] " __VA_ARGS__)

#endif