#include "am_queue.h"


static struct MqttMsg mqtt_msg;
static struct GPIOMsg gpio_msg;
static struct WIFIMsg wifi_msg;

QueueHandle_t gpio_queue;
QueueHandle_t mqtt_queue;
QueueHandle_t wifi_queue;

void am_queue_init(){
    mqtt_queue = xQueueCreate(100, sizeof(struct MqttMsg));
    gpio_queue = xQueueCreate(15, sizeof(struct GPIOMsg));
    wifi_queue = xQueueCreate(5, sizeof(struct WIFIMsg));
}

void am_queue_send_mqtt(struct MqttMsg msg){
    xQueueSendToBack(mqtt_queue, &msg, 0);
}

void am_queue_send_gpio(uint32_t _gpio, uint32_t _status){
    gpio_msg.gpio = _gpio;
    gpio_msg.status = _status;
    xQueueSendToBack(gpio_queue, &gpio_msg, 0);
}

void am_queue_send_wifi(struct WIFIMsg msg){
    xQueueSendToBack(wifi_queue, &msg, 0);
}
 