#ifndef BLE_UTILS_H
#define BLE_UTILS_H

int is_ibeacon(const char *packet);

const char *is_moving(int x,
                      int y,
                      int z);

#endif