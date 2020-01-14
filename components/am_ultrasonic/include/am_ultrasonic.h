#ifndef _AM_ULTRASONIC_H_
#define _AM_ULTRASONIC_H_

//https://github.com/UncleRus/esp-idf-lib

#include <stdlib.h>
#include <stdint.h>

/**
 * Device descriptor
 */
typedef struct
{
    uint32_t trigger_pin;
    uint32_t echo_pin;
} ultrasonic_sensor_t;

#endif