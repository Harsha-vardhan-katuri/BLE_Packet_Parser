#ifndef BLE_LOGGER_H
#define BLE_LOGGER_H

#include <stdio.h>

#define LOG_INFO(fmt, ...) \
    printf("[INFO] " fmt "\n", ##__VA_ARGS__)

#define LOG_WARNING(fmt, ...) \
    printf("[WARNING] " fmt "\n", ##__VA_ARGS__)

#define LOG_ERROR(fmt, ...) \
    printf("[ERROR] " fmt "\n", ##__VA_ARGS__)

#define LOG_DEBUG(fmt, ...) \
    printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)

#endif