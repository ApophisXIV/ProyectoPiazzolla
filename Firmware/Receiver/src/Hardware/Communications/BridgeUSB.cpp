 #ifndef __BridgeUSB_CPP__

    #define __BridgeUSB_CPP__

    #include <Hardware/Communications/BridgeUSB.h>

    USB_PORT_RX::USB_PORT_RX (bool nativo_uart , bool fueInicializado) : USBSerial(){

        if(!fueInicializado){

            USB_PORT_RX::setGPIO(nativo_uart);

            USB_PORT_RX::inicializar();
        }


    }

    void USB_PORT_RX::setGPIO(bool nativo_uart){

        pinMode(USB_UART_BR,1);

        digitalWrite(USB_UART_BR,nativo_uart);
    }

    void USB_PORT_RX::inicializar(){

        USB_PORT_RX::USBSerial::begin();

        while (!SerialUSB){   

            USB_PORT_RX::Error_Monitor::barridoUSB_Conectando();
        }

        if(SerialUSB){

            USB_PORT_RX::Error_Monitor::beepBeepAll(80);
            
            #ifdef DEBUG_USB
                USB_PORT_RX::USBSerial::printf(F("BridgeUSB. Estado: USB Conectado OK\n"));
            #endif
        }
    }


#endif