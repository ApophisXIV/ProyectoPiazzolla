#ifndef __GPIO_H__

    #define __GPIO_H__
    
    #include <Hardware/Hardware_usage.h>

    /**************************************************/
    /*              Definicion de GPIO                */
    /**************************************************/

    #ifdef ERROR_MONITOR_ENABLED
        /*************************/
        /*     LEDS de error     */
        /*************************/
        #define LED_ERROR_A   PB12
        #define LED_ERROR_B   PB13
        #define LED_ERROR_C   PB14
        #define LED_ERROR_D   PB15
        /*************************/
    #endif

    #ifdef COMM_LORA_ENABLED
        /****************************/
        /* Modulo de comunicaciones */
        /****************************/
        #define CS_RF         PA2
        #define RESET_RF      PA4
        #define DIO0          PA0
        #define DIO1          PA1
        /****************************/
    #endif 

    #ifdef USB_ENABLED
        /****************************/
        /*           USB            */
        /****************************/
        #define USB_UART_BR   PA8
        #define D_P           PA12
        #define D_N           PA11
        /****************************/
    #endif

    #ifdef COMM_LORA_ENABLED
        /****************************/
        /*           LDO            */
        /****************************/
        #define LDO_ENABLE    PB1
        #define LDO_ADC       PB0
        /****************************/
    #endif

    #ifdef UART3_DEBUG_ENABLED
        /*************************/
        /*         UART 3        */
        /*************************/
        #define UART3_TX      PB10
        #define UART3_RX      PB11
        /*************************/
    #endif

#endif