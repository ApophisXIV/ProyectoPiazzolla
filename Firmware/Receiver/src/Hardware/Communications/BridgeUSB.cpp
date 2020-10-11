 #ifndef __BridgeUSB_CPP__

    #define __BridgeUSB_CPP__

    #include <Hardware/Communications/BridgeUSB.h>

    USB_PORT_RX::USB_PORT_RX (bool nativo_uart){

        USB_PORT_RX::setGPIO(nativo_uart);
    }

    void USB_PORT_RX::setGPIO(bool nativo_uart){

        pinMode(USB_UART_BR,1);

        digitalWrite(USB_UART_BR,nativo_uart);
    }

    void USB_PORT_RX::inicializar(){

        USB_RX.begin();

        while (!USB_RX){   

            USB_PORT_RX::Error_Monitor::barridoUSB_Conectando();
        }

        if(USB_RX){

            USB_PORT_RX::Error_Monitor::beepBeepAll(50);
            USB_RX.println("USB Conectado OK");
        }
    }


#endif