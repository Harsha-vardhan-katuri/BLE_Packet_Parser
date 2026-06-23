#ifndef BLE_TYPES_H
#define BLE_TYPES_H

#include <stdint.h>

/* Accelerometer Data */
typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;

} AccelerometerData_t;

/* Motion Status */
typedef enum
{
    STATIONARY = 0,
    MOVING

} MotionState_t;

/* BLE Status */
typedef enum
{
    BLE_OK = 0,
    BLE_NULL_PACKET,
    BLE_INVALID_LENGTH,
    BLE_INVALID_DATA,
    BLE_IBEACON

} BLEStatus_t;

/* Packet Types */
typedef enum
{
    SENSOR_PACKET = 0,
    IBEACON_PACKET,
    UNKNOWN_PACKET

} PacketType_t;

#endif