#ifndef _AM_MQTT_H_
#define _AM_MQTT_H_

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "aws_mqtt_agent.h"
#include "queue_conf.h"



/**
 * Estructura para almacenar los mensajes del gpio que cambia de estado.
 * Estos mensajes son encolados desde el gpio_task; y desencolados
 * desde el mqtt_task donde son reportados al broker.
 * 
*/


/**
 * Cola para reporte de estado de los gpios
 * 
*/
extern QueueHandle_t mqtt_queue;

void am_mqtt_init();

/**
 * Tarea mqtt
 * @Params: - pvParameters: puntero void requerido para la creación de la tarea (No se usa)
 * @Return:
 * 
*/
void am_mqtt_task(void * pvParameters);

/**
 * Función llamada al recibir información en la cola (mqtt_queue).
 * @Params: - mqtt_msg: mensaje con el gpio y estado
 * @Return:
*/
void am_mqtt_report_status(struct MqttMsg mqtt_msg);

/**
 * Retorna handler de Mqtt (handler static). Requerido en el OTA agent.
 * @Params: 
 * @Return: Mqtt handler
*/
MQTTAgentHandle_t am_mqtt_get_handler();


#endif
