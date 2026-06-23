#ifndef BLE_UTILS_H
#define BLE_UTILS_H

#include "ble_types.h"

int is_ibeacon(const char *packet);

MotionState_t is_moving(const AccelerometerData_t *accel);

const char *motion_to_string(MotionState_t state);

#endif