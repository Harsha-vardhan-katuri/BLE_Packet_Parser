#ifndef BLE_PARSER_H
#define BLE_PARSER_H

#include "ble_types.h"

BLEStatus_t parse_ble_packet(const char *packet,
                             AccelerometerData_t *accel);

BLEStatus_t validate_packet(const char *packet);

PacketType_t detect_packet_type(const char *packet);

#endif