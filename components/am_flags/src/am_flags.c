#include "am_flags.h"
#include "_am_flags.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

/*
Mutes para prevenir data races 
*/
static SemaphoreHandle_t flags_mutex;
static TickType_t flags_max_block_time;

flags_t CONTROL_FLAGS;

void am_flags_init(){
    flags_max_block_time = pdMS_TO_TICKS(500); //La lectura/escritura se bloqueará max por 500 ms
    CONTROL_FLAGS.raw_flags = 0;
    flags_mutex = xSemaphoreCreateMutex();
    if(flags_mutex != NULL){
        _am_flags_give_mutex();
    }
}

bool am_flags_is_nvs_ok(){
    bool ret = false;
    if(_am_flags_take_mutex()){
        ret = CONTROL_FLAGS.nvs ? true : false;
    }
    _am_flags_give_mutex();
    return ret;
}

void am_lags_set_nvs_ok(){
    if(_am_flags_take_mutex()){
        CONTROL_FLAGS.nvs = 1;
    }
    _am_flags_give_mutex();
}

bool am_flags_is_wifi_connected(){
    bool ret = false;
    if(_am_flags_take_mutex()){
        ret = CONTROL_FLAGS.wifi_connected ? true : false;
    }
    _am_flags_give_mutex();
    return ret;
}

void am_flags_set_wifi_connected(){
    if(_am_flags_take_mutex()){
        CONTROL_FLAGS.wifi_connected = 1;
    }
    _am_flags_give_mutex();
}

void am_flags_reset_wifi_connected(){
    if(_am_flags_take_mutex()){
        CONTROL_FLAGS.wifi_connected = 0;
    }
    _am_flags_give_mutex();
}

void am_flags_reset_mqtt_connected(){
    if(_am_flags_take_mutex()){
        CONTROL_FLAGS.mqtt_connected = 0;
    }
    _am_flags_give_mutex();
}

bool am_flags_is_mqtt_connected(){
    bool ret = false;
    if(_am_flags_take_mutex()){
        ret = CONTROL_FLAGS.mqtt_connected ? true : false;
    }
    _am_flags_give_mutex();
    return ret;
}

void am_flags_set_mqtt_connected(){
    if(_am_flags_take_mutex()){
        CONTROL_FLAGS.mqtt_connected = 1;
    }
    _am_flags_give_mutex();
}


static bool _am_flags_take_mutex(){
    if(xSemaphoreTake(flags_mutex, flags_max_block_time) == pdPASS){
        return true;
    }
    else{
        return false;
    }
}

static void _am_flags_give_mutex(){
    xSemaphoreGive(flags_mutex);
}