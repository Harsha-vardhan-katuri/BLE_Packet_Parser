#ifndef BLE_PARSER_H
#define BLE_PARSER_H

#include "ble_types.h"

BLEStatus_t parse_ble_packet(const char *packet,
                             AccelerometerData_t *accel);

#endif