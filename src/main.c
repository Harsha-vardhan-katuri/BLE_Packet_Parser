#include <stdio.h>
#include "ble_parser.h"
#include "ble_utils.h"


int main() {
    const char *packets[] = {
        "0201060303E1FF1216E1FFA10364FFF4000FFF003772A33F23AC",
        "0201061AFF4C00021553594F4F4B534F4349414C444953544500000000E8",
        "0201060303E1FF1216E1FFA10364FFF60011FF003772A33F23AC",
        "0201061AFF4C00021553594F4F4B534F4349414C444953544500000000E8",
        "0201060303E1FF1216E1FFA10364FFF40011FF033772A33F23AC",
        "0201061AFF4C00021553594F4F4B534F4349414C444953544500000000E8"
    };

    int x, y, z;
    const char *status;
    for (int i = 0; i < 6; i++) {
        printf("BLE Packet: %s\n", packets[i]);
        if (parse_ble_packet(packets[i], &x, &y, &z) == 0) { 
            printf("Parsed Data: x=%d, y=%d, z=%d\n", x, y, z);
            status = is_moving(x, y, z);
            printf("Motion Status: %s\n\n", status);
        }
    }
    return 0;
}
