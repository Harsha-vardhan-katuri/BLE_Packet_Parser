#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ble_parser.h"
#include "ble_utils.h"
#include "ble_config.h"

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