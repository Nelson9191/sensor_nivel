#ifndef _ANALOG_INFO_H_
#define _ANALOG_INFO_H_
 

#define NO_OF_SAMPLES       64      //Numero de muestras para promediar valor analógico
#define ANALOG_RANGE_AN01   40      //Rango de detección de cambio en entrada analógica
#define ANALOG_RANGE_AN02   40      
#define ANALOG_RANGE_AN03   50      
#define ANALOG_RANGE_AN04   8      
#define ANALOG_RANGE_AN05   50      
#define ANALOG_RANGE_AN06   50      


#define AN01      ADC1_CHANNEL_0 /*!< ADC1 channel 9 is GPIO36 */
#define AN02      ADC1_CHANNEL_3 /*!< ADC1 channel 8 is GPIO39 */
#define AN03      ADC1_CHANNEL_6 /*!< ADC1 channel 7 is GPIO34 */
#define AN04      ADC1_CHANNEL_7 /*!< ADC1 channel 6 is GPIO35 */
#define AN05      ADC1_CHANNEL_4 /*!< ADC1 channel 4 is GPIO32 */
#define AN06      ADC1_CHANNEL_5 /*!< ADC1 channel 5 is GPIO33 */

#define AN01_NAME "AI01"
#define AN02_NAME "AI02"
#define AN03_NAME "AI03"
#define AN04_NAME "AI04"
#define AN05_NAME "AI05"
#define AN06_NAME "AI06"



/*
Poner en "1" o "0" las entradas analógicas del ESP que se van a conectar.
Esto para poder leer el valoy y compar con deltas para el disoaro de mensajes/alarmas/acciones.
*/
#define USE_AN01   1
#define USE_AN02   1
#define USE_AN03   0
#define USE_AN04   1
#define USE_AN05   0
#define USE_AN06   0

#endif