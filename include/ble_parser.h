#ifndef BLE_PARSER_H
#define BLE_PARSER_H

#include "ble_types.h"

int parse_ble_packet(const char *packet,
                     AccelerometerData_t *accel);

#endif