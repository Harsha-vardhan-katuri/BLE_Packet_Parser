#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_ibeacon(const char *packet) {
    // Check if the packet starts with "0x0201061A" to identify iBeacon packets
    return (strncmp(packet, "0201061A", 8) == 0);
}

int parse_ble_packet(const char *packet, int *x, int *y, int *z) {
    // Check if the packet is an iBeacon packet
    if (is_ibeacon(packet)) {
        printf("Cannot find accelerometer data in the packet (iBeacon).\n\n");
        return -1;  // Return -1 to indicate no accelerometer data
    }

    // Extract the 4 characters (2 bytes) for each axis from the packet
    char x_str[5], y_str[5], z_str[5];  // 4 characters + null terminator
    
    // Extract the data for X, Y, Z axes starting from correct positions
    strncpy(x_str, packet + 28, 4);  // Starting from position 28, take 4 characters for X
    x_str[4] = '\0';  // Null-terminate the string
    
    strncpy(y_str, packet + 32, 4);  // Starting from position 32, take 4 characters for Y
    y_str[4] = '\0';  // Null-terminate the string
    
    strncpy(z_str, packet + 36, 4);  // Starting from position 36, take 4 characters for Z
    z_str[4] = '\0';  // Null-terminate the string
    
    // Convert the hex strings to integers
    *x = (short)strtol(x_str, NULL, 16);
    *y = (short)strtol(y_str, NULL, 16);
    *z = (short)strtol(z_str, NULL, 16);
    
    return 0;  // Return 0 to indicate successful parsing
}

const char* is_moving(int x, int y, int z) {
    // Calculate the magnitude of the vector
    double magnitude = sqrt(x * x + y * y + z * z);
    
    // Convert magnitude into g (assuming the accelerometer has a full scale of 16384)
    double magnitude_in_g = magnitude / 16384;
    
    // Threshold for motion detection
    double threshold = 1.0;  // This can be adjusted
    
    return magnitude_in_g > threshold ? "Moving" : "Stationary";
}

int main() {
    // Array of packets to process
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
    
    // Process each packet
    for (int i = 0; i < 6; i++) {
        printf("BLE Packet: %s\n", packets[i]);
        
        // Parse the accelerometer data from the packet
        if (parse_ble_packet(packets[i], &x, &y, &z) == 0) {  // Only process if accelerometer data is found
            printf("Parsed Data: x=%d, y=%d, z=%d\n", x, y, z);
            
            // Determine the motion status
            status = is_moving(x, y, z);
            printf("Motion Status: %s\n\n", status);
        }
    }

    return 0;
}
