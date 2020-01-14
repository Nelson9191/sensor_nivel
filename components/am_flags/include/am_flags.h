#ifndef _AM_FLAGS_H_
#define _AM_FLAGS_H_

#include <stdbool.h>

typedef unsigned int boolean_t;

/*
Union de flags para leer diferentes estados de control a lo largo de todo el programa
*/
typedef union {
    struct{
        boolean_t nvs :             1;
        boolean_t spiffs :          1;
        boolean_t wifi_connected :  1;
        boolean_t mqtt_connected :  1;
        int not_used :              28;        
    };
    int raw_flags;
} flags_t;


/*
Inicializa módulo. Crea mutex y limpia flgas de control
@Params:
@Return:
*/
void am_flags_init();

/*
Revisa si el módulo de NVS se inicializó.
@Params:
@Return: true si módulo inicializado, false de lo contrario
*/
bool am_flags_is_nvs_ok();

/*
Setea flag de NVS inicializado
@Params:
@Return: 
*/
void am_flags_set_nvs_ok();

/*
Revisa si módulo de WiFi se inicializó
@Params:
@Return: true si módulo inicializado, false de lo contrario
*/
bool am_flags_is_wifi_connected();

/*
Setea flag de WiFi inicializado
@Params:
@Return: 
*/
void am_flags_set_wifi_connected();

/*
Resetea flag de WiFi inicializado
@Params:
@Return: 
*/
void am_flags_reset_wifi_connected();


bool am_flags_is_mqtt_connected();

/*
Setea flag de cliente MQTT conectado
@Params:
@Return: 
*/
void am_flags_set_mqtt_connected();

/*
Resetea flag de MQTT
@Params:
@Return: 
*/
void am_flags_reset_mqtt_connected();



#endif