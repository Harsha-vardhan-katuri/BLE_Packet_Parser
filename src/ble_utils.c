#include <stdio.h>
#include <string.h>
#include <math.h>

#include "ble_utils.h"
#include "ble_config.h"

int is_ibeacon(const char *packet)
{
    return (strncmp(packet, "0201061A", 8) == 0);
}

const char *is_moving(const AccelerometerData_t *accel)
{
    double magnitude =
        sqrt(accel->x * accel->x +
             accel->y * accel->y +
             accel->z * accel->z);

    double magnitude_in_g =
        magnitude / ACCEL_SCALE;

    return (magnitude_in_g > MOTION_THRESHOLD)
               ? "Moving"
               : "Stationary";
}