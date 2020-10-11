#ifndef __LDO_H__

    #define __LDO_H__

    #include <Hardware/Hardware_usage.h>

    #include <Hardware/GPIO.h>

    #include <Hardware/Utilities/floatTo2Bytes.h>

    class LDO_Reg{

        USBSerial USB_LDO;

        public:
        
        LDO_Reg();

        bool selfTest();

        uint16_t tensionActual();

        private:
        
        uint32_t __tempVLDO = 0;

        void setGPIO();
        
        void tensionRead();

    };

#endif