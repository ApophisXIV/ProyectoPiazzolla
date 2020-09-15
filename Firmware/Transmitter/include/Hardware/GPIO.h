#ifndef __GPIO_H__

    #define __GPIO_H__
    
    #include <Hardware/Hardware_usage.h>

    /**************************************************/
    /*             Definicion Generales               */
    /**************************************************/
    #define ADC_RES 0.0008056640625
    /**************************************************/

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

    #ifdef MEM_SD_ENABLED
        /***********************/
        /*    Tarjeta SD       */
        /***********************/
        #define CS_CARD       PA3
        #define CARD_DS       PB8
        #define WRITE_PROTECT PB9
        /***********************/
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

    #if defined(BMP280_ENABLED)|| defined(HDC1080_ENABLED) || defined(QMC5883L_ENABLED) || defined(MPU6050_ENABLED)
        /****************************/
        /*           I2C            */
        /****************************/
        #define I2C_SDA       PB7
        #define I2C_SCL       PB6
        /****************************/
    #endif 

    #ifdef GPS_L80R_ENABLED
        /***********************/
        /*         GPS         */
        /***********************/
        #define GPS_TX        PA9
        #define GPS_RX        P10
        #define RESET_GPS     PB9
        /***********************/
    #endif

    #ifdef USB_ENABLED
        /****************************/
        /*           USB            */
        /****************************/
        #define D_P           PA12
        #define D_N           PA11
        /****************************/
    #endif

    #ifdef COMM_LORA_ENABLED
        /****************************/
        /*           LDO            */
        /****************************/
        #define LDO_ENABLE    PB5
        #define LDO_ADC       PB0
        /****************************/
    #endif

    #ifdef ADC_BATT_ENABLED
        /****************************/
        /*         Bateria          */
        /****************************/
        #define BATERIA_ADC   PB1
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