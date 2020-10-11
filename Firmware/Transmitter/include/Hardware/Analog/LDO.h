#ifndef __LDO_H__

    #define __LDO_H__

    #include <Hardware/Hardware_usage.h>

    #include <Hardware/GPIO.h>

    #include <Hardware/Utilities/floatTo2Bytes.h>

    class LDO_Reg{

        public:

        void setGPIO();

        bool selfTest();

        uint16_t tensionActual();

        private:
        
        void tensionRead();

    };

#endif