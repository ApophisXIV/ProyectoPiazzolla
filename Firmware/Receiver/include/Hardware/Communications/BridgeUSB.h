 #ifndef __BridgeUSB_H__

    #define __BridgeUSB_H__

    #include <Hardware/Hardware_usage.h>

    #include <Hardware/GPIO.h>

    #include <Hardware/Diagnostic/Monitor.h>

    #define DEBUG_USB

    class USB_PORT_RX: protected Error_Monitor , public USBSerial{
        
        public:

        USB_PORT_RX (bool nativo_uart , bool fueInicializado);

        USB_PORT_RX (bool yaFueInicializado);

        private:
        
        void inicializar();

        void setGPIO(bool nativo_uart);
        
    };

#endif