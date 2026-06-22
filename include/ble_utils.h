#ifndef BLE_UTILS_H
#define BLE_UTILS_H

#include "ble_types.h"

int is_ibeacon(const char *packet);

const char *is_moving(const AccelerometerData_t *accel);

#endif