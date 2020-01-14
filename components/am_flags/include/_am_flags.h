#ifndef __AM_FLAGS_H_
#define __AM_FLAGS_H_

/*
Toma el mutex de las flags
@Params:
@Return: true si tomó el mutex, false de lo contrario
*/
static bool _am_flags_take_mutex();

/*
Devuelve mutex
@Params:
@Return:
*/
static void _am_flags_give_mutex();

#endif