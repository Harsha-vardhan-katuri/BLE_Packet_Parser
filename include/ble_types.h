#ifndef BLE_TYPES_H
#define BLE_TYPES_H

#include <stdint.h>

/**
 * @brief Stores accelerometer data.
 */
typedef struct
{
    int16_t x;   /**< X-axis acceleration */
    int16_t y;   /**< Y-axis acceleration */
    int16_t z;   /**< Z-axis acceleration */

} AccelerometerData_t;

/**
 * @brief Motion state.
 */
typedef enum
{
    STATIONARY = 0,
    MOVING

} MotionState_t;

/**
 * @brief BLE parser status.
 */
typedef enum
{
    BLE_OK = 0,
    BLE_NULL_PACKET,
    BLE_INVALID_LENGTH,
    BLE_INVALID_DATA,
    BLE_IBEACON

} BLEStatus_t;

/**
 * @brief Supported BLE packet types.
 */
typedef enum
{
    SENSOR_PACKET = 0,
    IBEACON_PACKET,
    UNKNOWN_PACKET

} PacketType_t;

#endif