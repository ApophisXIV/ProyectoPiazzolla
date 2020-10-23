#ifndef __LDO_H__

    #define __LDO_H__

    #include <Hardware/Hardware_usage.h>

    #include <Hardware/GPIO.h>

    #include <Hardware/Utilities/delayNB.h>

    #include <Hardware/Utilities/floatTo2Bytes.h>

    #include <Hardware/Communications/UART_debug.h>

    #define DEBUG_LDO

    class LDO_Reg : virtual public UART3_DEBUG{

        public:
        
        LDO_Reg();

        bool selfTest();

        uint16_t tensionActual();

        private:
        
        void setGPIO();
        
        void tensionRead();

    };

#endif