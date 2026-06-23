#ifndef BLE_UTILS_H
#define BLE_UTILS_H

#include "ble_types.h"

/**
 * @brief Checks whether the received packet is an iBeacon.
 *
 * @param packet Pointer to raw BLE advertisement packet.
 *
 * @return int
 * @retval 1 Packet is iBeacon.
 * @retval 0 Packet is not iBeacon.
 */
int is_ibeacon(const char *packet);

/**
 * @brief Determines the motion state using accelerometer data.
 *
 * Calculates the acceleration magnitude and compares it
 * against the configured threshold.
 *
 * @param accel Pointer to accelerometer data.
 *
 * @return MotionState_t
 */
MotionState_t is_moving(const AccelerometerData_t *accel);

/**
 * @brief Converts motion state into readable text.
 *
 * @param state Motion state.
 *
 * @return const char*
 */
const char *motion_to_string(MotionState_t state);

#endif