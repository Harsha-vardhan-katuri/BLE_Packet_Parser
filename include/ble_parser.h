#ifndef BLE_PARSER_H
#define BLE_PARSER_H

#include "ble_types.h"

/**
 * @brief Validates a BLE advertisement packet.
 *
 * This function checks whether the packet is valid by
 * verifying:
 * - NULL pointer
 * - Minimum packet length
 * - Valid hexadecimal characters
 *
 * @param packet Pointer to the raw BLE advertisement packet.
 *
 * @return BLEStatus_t
 * @retval BLE_OK Packet is valid.
 * @retval BLE_NULL_PACKET Packet pointer is NULL.
 * @retval BLE_INVALID_LENGTH Packet length is too short.
 * @retval BLE_INVALID_DATA Packet contains invalid hexadecimal data.
 */
BLEStatus_t validate_packet(const char *packet);

/**
 * @brief Detects the BLE advertisement packet type.
 *
 * Determines whether the received packet is:
 * - Sensor Packet
 * - iBeacon Packet
 * - Unknown Packet
 *
 * @param packet Pointer to the raw BLE advertisement packet.
 *
 * @return PacketType_t
 */
PacketType_t detect_packet_type(const char *packet);

/**
 * @brief Parses BLE advertisement packet.
 *
 * Extracts X, Y and Z accelerometer values from the BLE
 * advertisement payload.
 *
 * @param packet Pointer to the raw BLE advertisement packet.
 * @param accel Pointer to output accelerometer structure.
 *
 * @return BLEStatus_t
 */
BLEStatus_t parse_ble_packet(const char *packet,
                             AccelerometerData_t *accel);

#endif