#ifndef __Monitor_H__

    #define __Monitor_H__

    #include <Arduino.h>

    class Error_Monitor{

        public:

        void SetGPIO();

        void selfTest();

        void BarridoUSB_Conectando();

        void BeepBeep(uint8_t Transicion);

        void BeepBeepAll(uint8_t Transicion);

        void MensajeEntrante(uint8_t Transicion);

        void ErrorValue(uint8_t Error);

        private:

        void ErrorCodeInternal(bool LED_D, bool LED_C, bool LED_B, bool LED_A, uint8_t Transicion);
            
    };

#endif