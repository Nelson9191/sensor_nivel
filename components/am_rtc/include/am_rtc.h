#ifndef _AM_RTC_H_
#define _AM_RTC_H_

#include "freertos/FreeRTOSConfig.h"
#include <stdint.h>

#if configTICK_RATE_HZ == 100
    #define RTC_CONFIG_FACTOR 10
    #define RTC_CONFIG_NORM_FACTOR 100
#else
    #define RTC_CONFIG_FACTOR 1
    #define RTC_CONFIG_NORM_FACTOR 1000
#endif

void am_rtc_init();
uint32_t am_rtc_get_time();
uint32_t am_rtc_get_ticks_MS();
void am_rtc_set_time(uint32_t in_time);
void am_rtc_set_time_(char * timeString, int len);



#endif

