#ifndef __Hardware_H__

    #define __Hardware_H__

    #include <Hardware/Diagnostic/Monitor.h>
    #include <Hardware/Storage/Mem_SD.h>
    #include <Hardware/Storage/Mem_Flash.h>
    #include <Hardware/Communications/LoRa_TX.h>

    class Hardware_Tests {
        
        Error_Monitor MonitorLED;
        
        MEM_Flash Flash;

        USBSerial USB_TX;

        SD_CARD TarjetaSD;

        LoRa_TX LoRaComm;

        public:

        void prueba_1();

    };

#endif