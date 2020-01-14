#ifndef _AM_QUEUE_H_
#define _AM_QUEUE_H_

/* Standard includes. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "aws_mqtt_agent.h"
#include "FreeRTOS.h"
#include "freertos/queue.h"

extern QueueHandle_t gpio_queue;
extern QueueHandle_t mqtt_queue;
extern QueueHandle_t wifi_queue;


struct MqttMsg {
    uint32_t gpio;
    uint32_t status;
    char name[10];
    uint32_t timestamp;
};

struct GPIOMsg {
    uint32_t gpio;
    uint32_t status;
    char name[10];
};

struct WIFIMsg{
    int status;
};


void am_queue_init();


void am_queue_send_mqtt(struct MqttMsg msg);


void am_queue_send_gpio(uint32_t _gpio, uint32_t _status);


void am_queue_send_wifi(struct WIFIMsg msg);



#endif
