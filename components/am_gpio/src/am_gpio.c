#include "am_gpio.h"
#include "_am_gpio.h"

/*--- Config Files */
#include "gpio_info.h"
#include "task_config.h"

/*---- Project Components---- */
#include "am_queue.h"
#include "am_rtc.h"

static QueueHandle_t gpio_evt_queue;
QueueHandle_t gpio_queue;


static Gpios_t DI_status;
static Gpios_t DI_reported;


static uint32_t last_gpio = 0;
static uint32_t last_status = 0;
static uint32_t curr_gpio = 0;
static uint32_t curr_status = 0;


void am_gpio_init(){
    DI_status.raw_DI = 0;
    DI_reported.raw_DI =  0;
    am_gpio_config_gpios();
    gpio_evt_queue = xQueueCreate(25, sizeof(uint32_t));
    if(gpio_evt_queue != NULL){
        ( void ) xTaskCreate( am_gpio_read_task,
                              TASK_GPIO_READ_NAME,
                              TASK_GPIO_READ_STACK_SIZE,
                              NULL,
                              TASK_READ_GPIO_PRIORITY,
                              NULL );

        ( void ) xTaskCreate( am_gpio_write_task,
                              TASK_GPIO_WRITE_NAME,
                              TASK_GPIO_WRITE_STACK_SIZE,
                              NULL,
                              TASK_WRITE_GPIO_PRIORITY,
                              NULL );                              
    }
}


static void IRAM_ATTR am_gpio_ISR(void* arg){
    curr_gpio = (uint32_t) arg;
    curr_status = (uint32_t)  am_gpio_read(curr_gpio);
    if(curr_gpio != last_gpio || (curr_gpio == last_gpio && curr_status != last_status)){
        xQueueSendFromISR(gpio_evt_queue, &curr_gpio, NULL);
    }

    last_gpio = curr_gpio;
    last_status = curr_status;
}

int am_gpio_read(uint32_t gpio){
    return gpio_get_level(gpio);
}

void am_gpio_write(uint32_t gpio, uint32_t level){
    switch(gpio){
        case 1: gpio = GPIO_DO01;
                break;
        case 2: gpio = GPIO_DO02;
                break;
        case 3: gpio = GPIO_DO03;
                break;
        case 4: gpio = GPIO_DO04;
                break;                
    }
    //printf("write gpio-> %d:", gpio);    
    //printf("%d\n", level);
    gpio_set_level(gpio, level);
}


void am_gpio_read_task(void * pvParameters){
    (void) pvParameters;
    uint32_t gpio;
    struct MqttMsg mqtt_msg;
    uint32_t interrupt_time = 0;
    bool report_change = false;
    int status = 0;

    for(;;){
        while(xQueueReceiveFromISR(gpio_evt_queue, &gpio, NULL)){
            status = am_gpio_read(gpio);
            interrupt_time = am_rtc_get_ticks_MS();
            report_change = true;
            switch(gpio){
                    case GPIO_DI01:
                        DI_status.DI01 = status;
                        break;
                    case GPIO_DI02:
                        DI_status.DI02 = status;
                        break;
                    case GPIO_DI03:
                        DI_status.DI03 = status;
                        break;
                    case GPIO_DI04:
                        DI_status.DI04 = status;
                        break;
                    case GPIO_DI05:
                        DI_status.DI05 = status;
                        break;
                    case GPIO_DI06:
                        DI_status.DI06 = status;
                        break;
                    case GPIO_DI07:
                        DI_status.DI07 = status;
                        break;
                    case GPIO_DI08:
                        DI_status.DI08 = status;
                        break;                                                                                                                                                                        
                }   
            }
        
        vTaskDelay(10 / portTICK_PERIOD_MS);

        if(report_change){
            report_change = false;

            if(am_gpio_compare_status(GPIO_DI01)){
                DI_reported.DI01 = DI_status.DI01;
                snprintf(mqtt_msg.name, 10, "%s", DI01_NAME);
                mqtt_msg.status = DI_reported.DI01;
                mqtt_msg.timestamp = am_rtc_get_time();
                am_queue_send_mqtt(mqtt_msg);
            }
            
            if(am_gpio_compare_status(GPIO_DI02)){
                DI_reported.DI02 = DI_status.DI02;
                snprintf(mqtt_msg.name, 10, "%s", DI02_NAME);
                mqtt_msg.status = DI_reported.DI02;
                mqtt_msg.timestamp = am_rtc_get_time();                
                am_queue_send_mqtt(mqtt_msg);
            }

            if(am_gpio_compare_status(GPIO_DI03)){
                DI_reported.DI03 = DI_status.DI03;
                snprintf(mqtt_msg.name, 10, "%s", DI03_NAME);
                mqtt_msg.status = DI_reported.DI03;
                mqtt_msg.timestamp = am_rtc_get_time();                
                am_queue_send_mqtt(mqtt_msg);
            }

            if(am_gpio_compare_status(GPIO_DI04)){
                DI_reported.DI04 = DI_status.DI04;
                snprintf(mqtt_msg.name, 10, "%s", DI04_NAME);
                mqtt_msg.status = DI_reported.DI04;
                mqtt_msg.timestamp = am_rtc_get_time();                
                am_queue_send_mqtt(mqtt_msg);
            }

            if(am_gpio_compare_status(GPIO_DI05)){
                DI_reported.DI05 = DI_status.DI05;
                snprintf(mqtt_msg.name, 10, "%s", DI05_NAME);
                mqtt_msg.status = DI_reported.DI05;
                mqtt_msg.timestamp = am_rtc_get_time();                
                am_queue_send_mqtt(mqtt_msg);
            }

            if(am_gpio_compare_status(GPIO_DI06)){
                DI_reported.DI06 = DI_status.DI06;
                snprintf(mqtt_msg.name, 10, "%s", DI06_NAME);
                mqtt_msg.status = DI_reported.DI06;
                mqtt_msg.timestamp = am_rtc_get_time();                
                am_queue_send_mqtt(mqtt_msg);
            }

            if(am_gpio_compare_status(GPIO_DI07)){
                DI_reported.DI07 = DI_status.DI07;
                snprintf(mqtt_msg.name, 10, "%s", DI07_NAME);
                mqtt_msg.status = DI_reported.DI07;
                mqtt_msg.timestamp = am_rtc_get_time();                
                am_queue_send_mqtt(mqtt_msg);
            }

            if(am_gpio_compare_status(GPIO_DI08)){
                DI_reported.DI08 = DI_status.DI08;
                snprintf(mqtt_msg.name, 10, "%s", DI08_NAME);
                mqtt_msg.status = DI_reported.DI08;
                mqtt_msg.timestamp = am_rtc_get_time();                
                am_queue_send_mqtt(mqtt_msg);
            }

        }

    }
}

static bool am_gpio_compare_status(unsigned int gpio){
    switch(gpio){
        case GPIO_DI01:
            return  DI_status.DI01 != DI_reported.DI01 && DI_status.DI01 == am_gpio_read(gpio);
            break;
        case GPIO_DI02:
            return DI_status.DI02 != DI_reported.DI02 && DI_status.DI02 == am_gpio_read(gpio);
            break;
        case GPIO_DI03:
            return DI_status.DI03 != DI_reported.DI03 && DI_status.DI03 == am_gpio_read(gpio);
            break;
        case GPIO_DI04:
            return DI_status.DI04 != DI_reported.DI04 && DI_status.DI04 == am_gpio_read(gpio);
            break;
        case GPIO_DI05:
            return DI_status.DI05 != DI_reported.DI05 && DI_status.DI05 == am_gpio_read(gpio);
            break;
        case GPIO_DI06:
            return DI_status.DI06 != DI_reported.DI06 && DI_status.DI06 == am_gpio_read(gpio);
            break;
        case GPIO_DI07:
            return DI_status.DI07 != DI_reported.DI07 && DI_status.DI07 == am_gpio_read(gpio);
            break;
        case GPIO_DI08:
            return DI_status.DI08 != DI_reported.DI08 && DI_status.DI08 == am_gpio_read(gpio);
            break; 
        default:
            return false;
            break;     
    }
}


void am_gpio_write_task(void * pvParameters){
    (void) pvParameters;
    struct GPIOMsg gpio_msg;

    for(;;){
        while(xQueueReceive(gpio_queue, &gpio_msg, NULL) != errQUEUE_EMPTY){
            am_gpio_write(gpio_msg.gpio, gpio_msg.status);            
        }

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}


void am_gpio_config_gpios(){
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;//disable interrupt    
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = am_gpio_get_output_mask(); // Toma la mascara de bit de gpios de entrada
    io_conf.pull_down_en = 0;//disable pull-down mode
    io_conf.pull_up_en = 0;//disable pull-up mode    
    gpio_config(&io_conf);//configure GPIO with the given settings

    io_conf.intr_type = GPIO_INTR_ANYEDGE;//interrupt of rising edge
    io_conf.pin_bit_mask = am_gpio_get_input_mask();
    io_conf.mode = GPIO_MODE_INPUT;    
    io_conf.pull_down_en = 0;//disable pull-down mode
    io_conf.pull_up_en = 1;//enable pull-up mode
    gpio_config(&io_conf);

    gpio_install_isr_service(0);//Activa llamada a ISR cuando hay interrupciones
    //gpio_isr_handler_add(GPIO_IN_D36_36, am_gpio_ISR, (void*) GPIO_IN_D36_36);
    if(USE_GPIO_DI01){
        gpio_isr_handler_add(GPIO_DI01, am_gpio_ISR, (void*) GPIO_DI01);
        //gpio_set_intr_type(GPIO_DI01, GPIO_INTR_ANYEDGE);
    }
    if(USE_GPIO_DI02){
        gpio_isr_handler_add(GPIO_DI02, am_gpio_ISR, (void*) GPIO_DI02);
        //gpio_set_intr_type(GPIO_DI02, GPIO_INTR_ANYEDGE);
    }
    if(USE_GPIO_DI03){
        gpio_isr_handler_add(GPIO_DI03, am_gpio_ISR, (void*) GPIO_DI03);
        gpio_set_intr_type(GPIO_DI03, GPIO_INTR_ANYEDGE);
    }
    if(USE_GPIO_DI04){
        gpio_isr_handler_add(GPIO_DI04, am_gpio_ISR, (void*) GPIO_DI04);
        //gpio_set_intr_type(GPIO_DI04, GPIO_INTR_ANYEDGE);
    }
    if(USE_GPIO_DI05){
        gpio_isr_handler_add(GPIO_DI05, am_gpio_ISR, (void*) GPIO_DI05);
        //gpio_set_intr_type(GPIO_DI05, GPIO_INTR_ANYEDGE);
    }
    if(USE_GPIO_DI06){
        gpio_isr_handler_add(GPIO_DI06, am_gpio_ISR, (void*) GPIO_DI06);
        //gpio_set_intr_type(GPIO_DI06, GPIO_INTR_ANYEDGE);
    }
    if(USE_GPIO_DI07){
        gpio_isr_handler_add(GPIO_DI07, am_gpio_ISR, (void*) GPIO_DI07);
        //gpio_set_intr_type(GPIO_DI07, GPIO_INTR_ANYEDGE);
    }
    if(USE_GPIO_DI08){
        gpio_isr_handler_add(GPIO_DI08, am_gpio_ISR, (void*) GPIO_DI08);
        //gpio_set_intr_type(GPIO_DI08, GPIO_INTR_ANYEDGE);
    }


}

static uint64_t am_gpio_get_input_mask(){
    uint64_t input = 0;
    if(USE_GPIO_DI01){
        input |= 1ULL<<GPIO_DI01;
    }
    if(USE_GPIO_DI02){
        input |= 1ULL<<GPIO_DI02;
    }    
    if(USE_GPIO_DI03){
        input |= 1ULL<<GPIO_DI03;
    }    
    if(USE_GPIO_DI04){
        input |= 1ULL<<GPIO_DI04;
    }
    if(USE_GPIO_DI05){
        input |= 1ULL<<GPIO_DI05;
    }
    if(USE_GPIO_DI06){
        input |= 1ULL<<GPIO_DI06;
    }    
    if(USE_GPIO_DI07){
        input |= 1ULL<<GPIO_DI07;
    }    
    if(USE_GPIO_DI08){
        input |= 1ULL<<GPIO_DI08;
    }
                         

    return input;
}


static uint64_t am_gpio_get_output_mask(){
    uint64_t output = 0;
    output |= 1ULL<<GPIO_DO01;
    output |= 1ULL<<GPIO_DO02;
    output |= 1ULL<<GPIO_DO03;
    output |= 1ULL<<GPIO_DO04;

    return output;
}