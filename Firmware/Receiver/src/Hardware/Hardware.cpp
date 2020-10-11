#ifndef __Hardware_CPP__

    #define __Hardware_CPP__ 

    #include <Hardware/Hardware.h>

    void Hardware_Tests::prueba_1(){
        
        /* -------------------------------------------------------------------------- */
        /*                      Monitor de errores inicializacion                     */
        /* -------------------------------------------------------------------------- */
            
            MonitorLED.selfTest();

        /* -------------------------------------------------------------------------- */

        /* -------------------------------------------------------------------------- */
        /*                        Memoria Flash inicializacion                        */
        /* -------------------------------------------------------------------------- */

            //TODO --> Si bien funciona la memoria Flash, todavia queda pensar de forma estrategica su uso
            
            //MonitorLED.ErrorValue(Flash.selfTest());

        /* -------------------------------------------------------------------------- */

        /* -------------------------------------------------------------------------- */
        /*                             USB Inicializacion                             */
        /* -------------------------------------------------------------------------- */

            USBComm.inicializar();

        /* -------------------------------------------------------------------------- */

        /* -------------------------------------------------------------------------- */
        /*                          Comm: LoRa Inicializacion                         */
        /* -------------------------------------------------------------------------- */
            
            LoRaComm.selfTest();
            
        /* -------------------------------------------------------------------------- */


    }

#endif