#ifndef __Hardware_usage_H__
    
    #define __Hardware_usage_H__

    #include <Arduino.h>

    /* -------------------------------------------------------------------------- */
    /*                            Constantes generales                            */
    /* -------------------------------------------------------------------------- */
        #define ADC_RES                     0.0008056640625
        #define BYTE_FULL                   255U 
        #define FRECUENCIA_LORA             433.0F              //Portadora = 433 MHz
        #define ANCHO_DE_BANDA_LORA         31.25F              //BW = 31,25 kHz
        #define FACTOR_DE_DISPERSION_LORA   9U                  //SF = 9
        #define CODING_RATE_LORA            4U+2U               //CR = 4/6
        #define SYNC_WORD_LORA              0x14                //SyncWord = 0x14
        #define POTENCIA_LORA               17U                 //Potencia de salida = 17 dBm
        #define PREAMBULO_LORA              2U+4U               //Preambulo = 2 Symb. + 4,25 Symb. --> 6,25 Symb.
        #define GANANCIA_AGC_AUTO           0                   //AGC Habilitado
    /* -------------------------------------------------------------------------- */

    /* -------------------------------------------------------------------------- */
    /*                             Error Code Monitor                             */
    /* -------------------------------------------------------------------------- */
        #ifdef ERROR_MONITOR_DISABLED        
            #undef ERROR_MONITOR_ENABLED
            #warning "Al desactivar los leds del monitor los errores no serán "\
                     "expresados visualmente. En su defecto serán enviados por "\
                     "el puerto serie auxiliar del dispositivo."
        #else
            #define ERROR_MONITOR_ENABLED
        #endif
    /* -------------------------------------------------------------------------- */
    
    /* -------------------------------------------------------------------------- */
    /*                                     USB                                    */
    /* -------------------------------------------------------------------------- */
        #ifdef USB_DISABLED        
            #undef USB_ENABLED
            #warning "El puerto USB del dispositivo fue desactivado"
        #else
            #define USB_ENABLED
        #endif
    /* -------------------------------------------------------------------------- */
    
    /* -------------------------------------------------------------------------- */
    /*                                 UART3 Debug                                */
    /* -------------------------------------------------------------------------- */
        #ifdef UART3_DEBUG_DISABLED        
            #undef UART3_DEBUG_ENABLED
            #warning "Al desactivar los leds del monitor los errores no serán "\
                     "expresados visualmente. En su defecto serán enviados por "\
                     "el puerto serie auxiliar del dispositivo."
        #else
            #define UART3_DEBUG_ENABLED
        #endif
    /* -------------------------------------------------------------------------- */
    
    /* -------------------------------------------------------------------------- */
    /*                                 Tarjeta SD                                 */
    /* -------------------------------------------------------------------------- */
        #ifdef MEM_SD_DISABLED        
            #undef MEM_SD_ENABLED        
            #warning "Al desactivar el almacenamiento de datos en la tarjeta SD el"\
                     "sistema no podrá realizar las pruebas finales, sin embargo"\
                     "este si podra realizar las evaluaciones disponibles en base"\
                     "con la salvedad de que el resultado de las mismas no será "\
                     "registrado en el dispositivo transmisor."
        #else
            #define MEM_SD_ENABLED
        #endif
    /* -------------------------------------------------------------------------- */
        
    /* -------------------------------------------------------------------------- */
    /*                                     LDO                                    */
    /* -------------------------------------------------------------------------- */
        #ifdef LDO_DISABLED
            #undef LDO_ENABLED
            #warning "Al desabilitarse el LDO, el modulo de comunicaciones no"\
                     "ser inicializado"
        #else
            #define LDO_ENABLED 
        #endif
    /* -------------------------------------------------------------------------- */

    /* -------------------------------------------------------------------------- */
    /*                                  LoRa Comm                                 */
    /* -------------------------------------------------------------------------- */
        #ifdef COMM_LORA_DISABLED
            #undef COMM_LORA_ENABLED
            #ifdef MEM_SD_ENABLED
                #warning "Al desactivar el modulo de comunciaciones los datos" \
                         "obtenidos no podran ser transmitidos inalambricamente"\
                         "pero si serán almacenados en la memoria SD."\
                         "Ej.: La ubicación geográfica del dispositivo."\
                         "Por casos como este no se recomienda desactivar el "\
                         "modulo de comunicaciones para pruebas de vuelo en el exterior."
            #else 
                #ifdef MEM_SD_DISABLED
                    #warning "Al desactivar el modulo de comunciaciones y la memoria"\
                             "SD los datos obtenidos no podran ser transmitidos "\
                             "inalambricamente ni almacenados, solamente seran enviados "\
                             "a traves del puerto serie auxiliar. "\
                             "Ej.: La ubicación geográfica del dispositivo."\
                             "Por casos como este no se recomienda desactivar el modulo"\
                             "de comunicaciones para pruebas de vuelo en el exterior."
                #endif
            #endif
        #else
            #ifdef LDO_ENABLED
                #define COMM_LORA_ENABLED
            #else
                #error "No puede habiltarse el modulo de comunicaciones sin la "\
                       "habilitacion de regulador LDO."
            #endif
        #endif
    /* -------------------------------------------------------------------------- */
#endif