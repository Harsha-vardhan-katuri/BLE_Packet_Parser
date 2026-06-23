#include <stdio.h>

#include "ble_parser.h"
#include "ble_utils.h"

int main()
{
    const char *packets[] =
    {
        "0201060303E1FF1216E1FFA10364FFF4000FFF003772A33F23AC",
        "0201061AFF4C00021553594F4F4B534F4349414C444953544500000000E8",
        "0201060303E1FF1216E1FFA10364FFF60011FF003772A33F23AC",
        "0201061AFF4C00021553594F4F4B534F4349414C444953544500000000E8",
        "0201060303E1FF1216E1FFA10364FFF40011FF033772A33F23AC",
        "0201061AFF4C00021553594F4F4B534F4349414C444953544500000000E8"
    };

    AccelerometerData_t accel;

    MotionState_t motion;

    BLEStatus_t status;

    for (int i = 0; i < 6; i++)
    {
        printf("BLE Packet : %s\n", packets[i]);

        status = parse_ble_packet(packets[i], &accel);

        if (status != BLE_OK)
        {
            printf("Packet rejected (Status = %d)\n\n", status);
            continue;
        }

        printf("Parsed Data : X=%d Y=%d Z=%d\n",
               accel.x,
               accel.y,
               accel.z);

        motion = is_moving(&accel);

        printf("Motion Status : %s\n\n",
               motion_to_string(motion));
    }

    return 0;
}