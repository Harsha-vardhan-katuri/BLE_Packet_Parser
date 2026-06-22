#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_ibeacon(const char *packet) { 
    return (strncmp(packet, "0201061A", 8) == 0);
}

int parse_ble_packet(const char *packet, int *x, int *y, int *z) {
    
    if (is_ibeacon(packet)) {
        printf("Cannot find accelerometer data in the packet (iBeacon).\n\n");
        return -1;  
    }
    char x_str[5], y_str[5], z_str[5]; 
    
    strncpy(x_str, packet + 28, 4);  
    x_str[4] = '\0';  
    
    strncpy(y_str, packet + 32, 4);  
    y_str[4] = '\0';  
    
    strncpy(z_str, packet + 36, 4);  
    z_str[4] = '\0';  
    
    // Convert the hex strings to integers
    *x = (short)strtol(x_str, NULL, 16);
    *y = (short)strtol(y_str, NULL, 16);
    *z = (short)strtol(z_str, NULL, 16);
    
    return 0;  
}

const char* is_moving(int x, int y, int z) {
    double magnitude = sqrt(x * x + y * y + z * z);
    double magnitude_in_g = magnitude / 16384;
    double threshold = 1.0;  
    
    return magnitude_in_g > threshold ? "Moving" : "Stationary";
}

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
