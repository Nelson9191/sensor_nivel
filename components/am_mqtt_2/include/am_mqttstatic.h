#ifndef _AM_MQTT_STATIC_H_
#define _AM_MQTT_STATIC_H_

#include "FreeRTOS.h"
#include "aws_mqtt_agent.h"

static BaseType_t am_mqtt_connect_to_broker( void );

static BaseType_t am_mqtt_subscribe_to_output(void);

static BaseType_t am_mqtt_subscribe_to_heartbeat(void);

/*
 * Función callback cuando el cliente recibe datos del broker     
 */
static MQTTBool_t am_mqtt_subs_callback(void * pvUserData, const MQTTPublishData_t * const pxCallbackParams);

static BaseType_t mqtt_events_callback (void * pvUserData, const MQTTAgentCallbackParams_t * const pxCallbackParams);

static MQTTAgentReturnCode_t am_mqtt_connect();

static MQTTAgentReturnCode_t am_mqtt_create( void );

static void am_mqtt_delete();

static void am_mqtt_disconnect();

static void am_mqtt_verify_heartbeat();

static void am_mqtt_process_output(const char * cBuffer);

static void am_mqtt_process_heartbeat(const char * cBuffer);


#endif