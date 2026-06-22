#ifndef BLE_PARSER_H
#define BLE_PARSER_H

int parse_ble_packet(const char *packet,
                     int *x,
                     int *y,
                     int *z);

#endif