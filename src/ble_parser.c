#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ble_parser.h"
#include "ble_utils.h"
#include "ble_config.h"
#include "ble_logger.h"

static int is_hex_string(const char *packet)
{
    while (*packet)
    {
        if (!isxdigit((unsigned char)*packet))
            return 0;

        packet++;
    }

    return 1;
}

/**
 * @brief Validates a BLE advertisement packet.
 *
 * @param packet Raw BLE packet.
 *
 * @return BLEStatus_t
 */

BLEStatus_t validate_packet(const char *packet)
{
    if (packet == NULL)
    {
        LOG_ERROR("NULL Packet");
        return BLE_NULL_PACKET;
    }

    if (strlen(packet) < MIN_PACKET_LENGTH)
    {
        LOG_ERROR("Invalid Packet Length");
        return BLE_INVALID_LENGTH;
    }

    if (!is_hex_string(packet))
    {
        LOG_ERROR("Invalid Hex Packet");
        return BLE_INVALID_DATA;
    }

    return BLE_OK;
}

/**
 * @brief Detects BLE advertisement packet type.
 *
 * @param packet Raw BLE packet.
 *
 * @return PacketType_t
 */

PacketType_t detect_packet_type(const char *packet)
{
    if (is_ibeacon(packet))
        return IBEACON_PACKET;

    if (strncmp(packet, "02010603", 8) == 0)
        return SENSOR_PACKET;

    return UNKNOWN_PACKET;
}

/**
 * @brief Extracts accelerometer values from BLE advertisement.
 *
 * @param packet Raw BLE advertisement packet.
 * @param accel Output accelerometer structure.
 *
 * @return BLEStatus_t
 */

BLEStatus_t parse_ble_packet(const char *packet,
                             AccelerometerData_t *accel)
{
    BLEStatus_t status;

    PacketType_t packetType;

    status = validate_packet(packet);

    if (status != BLE_OK)
        return status;

    packetType = detect_packet_type(packet);

    switch(packetType)
    {
        case SENSOR_PACKET:

            LOG_INFO("Sensor Packet");

            break;

        case IBEACON_PACKET:

            LOG_WARNING("iBeacon Packet");

            return BLE_IBEACON;

        case UNKNOWN_PACKET:

            LOG_ERROR("Unknown Packet");

            return BLE_INVALID_DATA;

        default:

            return BLE_INVALID_DATA;
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

    LOG_INFO("Accelerometer Extracted");

    return BLE_OK;
}