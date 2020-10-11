#ifndef __Hardware_usage_H__
    
    #define __Hardware_usage_H__

    #include <Arduino.h>

    /* -------------------------------------------------------------------------- */
    /*                            Constantes generales                            */
    /* -------------------------------------------------------------------------- */
        #define USB_NATIVO                  0
        #define USB_BRIDGE                  1
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
            #error "El puerto USB fue desactivado. El dispositivo no puede operar"\
                   "normalmente sin el"
        #else
            #define USB_ENABLED
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