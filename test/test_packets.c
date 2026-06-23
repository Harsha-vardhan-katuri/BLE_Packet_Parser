#include <stdio.h>

#include "../include/ble_parser.h"
#include "../include/ble_utils.h"

typedef struct
{
    const char *packet;
    BLEStatus_t expectedStatus;

} TestCase_t;

int main()
{
    AccelerometerData_t accel;

    TestCase_t tests[] =
    {
        {
            "0201060303E1FF1216E1FFA10364FFF4000FFF003772A33F23AC",
            BLE_OK
        },

        {
            "0201061AFF4C00021553594F4F4B534F4349414C444953544500000000E8",
            BLE_IBEACON
        },

        {
            "",
            BLE_INVALID_LENGTH
        },

        {
            NULL,
            BLE_NULL_PACKET
        },

        {
            "XYZ12345",
            BLE_INVALID_LENGTH
        }
    };

    int total =
        sizeof(tests) / sizeof(TestCase_t);

    int passed = 0;

    for(int i = 0; i < total; i++)
    {
        BLEStatus_t result;

        result =
            parse_ble_packet(
                tests[i].packet,
                &accel);

        if(result == tests[i].expectedStatus)
        {
            printf("[PASS] Test %d\n", i + 1);
            passed++;
        }
        else
        {
            printf("[FAIL] Test %d\n", i + 1);
        }
    }

    printf("\n");

    printf("Passed %d/%d Tests\n",
            passed,
            total);

    return 0;
}