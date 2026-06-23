#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ble_parser.h"
#include "ble_utils.h"
#include "ble_config.h"

BLEStatus_t parse_ble_packet(const char *packet,
                     AccelerometerData_t *accel)
{
    if (is_ibeacon(packet))
    {
        printf("Cannot find accelerometer data in the packet (iBeacon).\n\n");
        return BLE_IBEACON;
    }

    char x_str[5];
    char y_str[5];
    char z_str[5];

    strncpy(x_str, packet + X_OFFSET, 4);
    x_str[4] = '\0';

    strncpy(y_str, packet + Y_OFFSET, 4);
    y_str[4] = '\0';

    strncpy(z_str, packet + Z_OFFSET, 4);
    z_str[4] = '\0';

    accel->x = (short)strtol(x_str, NULL, 16);
    accel->y = (short)strtol(y_str, NULL, 16);
    accel->z = (short)strtol(z_str, NULL, 16);

    return BLE_OK;
}