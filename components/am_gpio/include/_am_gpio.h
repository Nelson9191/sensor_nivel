#ifndef __AM_GPIO_H
#define __AM_GPIO_H

/*
Rutina de atención a interrupción de señal en gpios de entrada.
Cada que hay un cambio en una entrada, esta ISR informará del pin GPIO en el cual 
se registró un cambio
@Params: - arg: puntero en el cual es FreeRTOS pone el número de GPIO de la interrupción
@Return: 
*/
static void IRAM_ATTR am_gpio_ISR(void* arg);

/*
Devuelve la mascara bits de las entradas segun se hayan definido en gpio_info.h
@Params:
@Return: mascara de entradas
*/
static uint64_t am_gpio_get_input_mask();

/*
Devuelve la mascara bits de las salidas segun se hayan definido en gpio_info.h
@Params:
@Return: mascara de salidas
*/
static uint64_t am_gpio_get_output_mask();

/*
Para un gpio (entrada) compara el estado actual con el que se ha reportado anteriormente
@Params: - gpio: entrada a comparar
@Return: - true si hay un cambio entre las dos muestras, false en otro caso
*/
static bool am_gpio_compare_status(unsigned int gpio);

#endif