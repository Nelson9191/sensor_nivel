#ifndef _GPIO_INFO_H_
#define _GPIO_INFO_H_

#define GPIO_DI01      14   /* GPIO12 */
#define GPIO_DI02      27   /* GPIO14 */
#define GPIO_DI03      26   /* GPIO27 */
#define GPIO_DI04      25   /* GPIO26 */
#define GPIO_DI05      18   /* GPIO18 */
#define GPIO_DI06      19   /* GPIO19 */
#define GPIO_DI07      22   /* GPIO22 */
#define GPIO_DI08      23   /* GPIO23 */

#define DI01_NAME "DI01"
#define DI02_NAME "DI02"
#define DI03_NAME "DI03"
#define DI04_NAME "DI04"
#define DI05_NAME "DI05"
#define DI06_NAME "DI06"
#define DI07_NAME "DI07"
#define DI08_NAME "DI08"



#define GPIO_DO01      15   // GPIO15 
#define GPIO_DO02       2   // GPIO02 
#define GPIO_DO03       0   // GPIO00 
#define GPIO_DO04       4  // GPIO04 

#define DO01_NAME "DO01"
#define DO02_NAME "DO02"
#define DO03_NAME "DO03"
#define DO04_NAME "DO04"

/*
Poner en "1" o "0" las entradas digitales del ESP que se van a conectar.
Esto para poder generar interrupciones de esos pines.
*/
#define USE_GPIO_DI01   1
#define USE_GPIO_DI02   1
#define USE_GPIO_DI03   1
#define USE_GPIO_DI04   1
#define USE_GPIO_DI05   1
#define USE_GPIO_DI06   1
#define USE_GPIO_DI07   1
#define USE_GPIO_DI08   1



#endif