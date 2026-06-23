#ifndef BLE_LOGGER_H
#define BLE_LOGGER_H

#include <stdio.h>

/**
 * @brief Prints informational messages.
 */
#define LOG_INFO(fmt, ...) \
    printf("[INFO] " fmt "\n", ##__VA_ARGS__)

/**
 * @brief Prints warning messages.
 */
#define LOG_WARNING(fmt, ...) \
    printf("[WARNING] " fmt "\n", ##__VA_ARGS__)

/**
 * @brief Prints error messages.
 */
#define LOG_ERROR(fmt, ...) \
    printf("[ERROR] " fmt "\n", ##__VA_ARGS__)

/**
 * @brief Prints debug messages.
 */
#define LOG_DEBUG(fmt, ...) \
    printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)

#endif