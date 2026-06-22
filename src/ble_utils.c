#include <stdio.h>
#include <string.h>
#include <math.h>

#include "ble_utils.h"
#include "ble_config.h"


int is_ibeacon(const char *packet) { 
    return (strncmp(packet, "0201061A", 8) == 0);
}
const char* is_moving(int x, int y, int z) {
    double magnitude = sqrt(x * x + y * y + z * z);
    double magnitude_in_g = magnitude / 16384;
    double threshold = 1.0;  
    
    return magnitude_in_g > threshold ? "Moving" : "Stationary";
}
