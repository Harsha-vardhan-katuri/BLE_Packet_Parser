#include <stdio.h>
#include <string.h>
#include <math.h>

#include "ble_utils.h"
#include "ble_config.h"

/**
 * @brief Checks if the packet is an iBeacon packet.
 */

int is_ibeacon(const char *packet)
{
    return (strncmp(packet, "0201061A", 8) == 0);
}

/**
 * @brief Calculates motion state.
 */
MotionState_t is_moving(const AccelerometerData_t *accel)
{
    double magnitude =
        sqrt(accel->x * accel->x +
             accel->y * accel->y +
             accel->z * accel->z);

    double magnitude_in_g =
        magnitude / ACCEL_SCALE;

    if (magnitude_in_g > MOTION_THRESHOLD)
        return MOVING;

    return STATIONARY;
}

/**
 * @brief Converts motion enum to string.
 */
const char *motion_to_string(MotionState_t state)
{
    switch (state)
    {
        case MOVING:
            return "Moving";

        case STATIONARY:
            return "Stationary";

        default:
            return "Unknown";
    }
}