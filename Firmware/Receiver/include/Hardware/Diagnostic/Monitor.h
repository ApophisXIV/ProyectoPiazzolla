#ifndef __Monitor_H__

    #define __Monitor_H__

    #include <Hardware/Hardware_usage.h>

    #include <Hardware/GPIO.h>

    #include <Hardware/Utilities/delayNB.h>

    /************************************************************
     * Error 0 ->   No hay error
     * Error 1 ->   Error en la lectura o escritura de la memoria 
     *              flash
     * Error 2 ->   La memoria SD no esta insertada en
     *              el slot o esta activado el switch de 
     *              dataProtect
     * Error 3 ->   La memoria SD no fue inicializada
     *              correctamente o no pudo ser escrito o
     *              leido el archivo de prueba
     * Error 4 ->   Error en la inicializacion del modulo LoRa
     * Error 5 ->   Prueba Echo Test = Fallida       
     ***********************************************************/
    
    //Si hay error devuelve valores diferentes de 0
    //Si no hay error devuelve 0

    class Error_Monitor{

        public:

        Error_Monitor();

        void selfTest();

        void beepBeep(uint8_t Transicion);


        private:

        void setGPIO();

        void errorCodeInternal(bool LED_D, bool LED_C, bool LED_B, bool LED_A, uint8_t Transicion);
        
        //Metodos a heredar por la clase USB
        protected:

        uint8_t errorValue(uint8_t Error);

        void beepBeepAll(uint8_t Transicion);

        void barridoUSB_Conectando();
        
        void mensajeEntrante(uint8_t Transicion);
    };

#endif