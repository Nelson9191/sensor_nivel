#ifndef _AM_GPIO_H_
#define _AM_GPIO_H_

#include <stdint.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"


typedef unsigned int boolean_t;

typedef union {
    struct{
        boolean_t DI01 :    1;
        boolean_t DI02 :    1;
        boolean_t DI03 :    1;
        boolean_t DI04 :    1;
        boolean_t DI05 :    1;
        boolean_t DI06 :    1;
        boolean_t DI07 :    1;
        boolean_t DI08 :    1;     
    };
    int raw_DI;
} Gpios_t;

void am_gpio_init();

void am_gpio_read_task(void * pvParameters);

void am_gpio_write_task(void * pvParameters);

int am_gpio_read(uint32_t gpio);

void am_gpio_write(uint32_t gpio, uint32_t level);

void am_gpio_config_gpios();

#endif