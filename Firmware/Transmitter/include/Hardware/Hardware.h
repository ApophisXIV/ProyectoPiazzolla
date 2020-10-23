#ifndef __Hardware_H__

    #define __Hardware_H__

    #include <Hardware/Diagnostic/Monitor.h>
    //#include <Hardware/Communications/BridgeUSB.h>
    //#include <Hardware/Storage/Mem_SD.h>
    //#include <Hardware/Storage/Mem_Flash.h>
    #include <Hardware/Communications/LoRa_TX.h>
    #include <Hardware/Communications/UART_debug.h>

    class Hardware_Tests{
        
        Error_Monitor MonitorLED;
        
        //MEM_Flash Flash;

        UART3_DEBUG Uart3Comm;

        //USB_PORT_TX USBComm;

        //SD_CARD TarjetaSD;

        LoRa_TX LoRaComm;

        public:

        void prueba_1();

    };

#endif