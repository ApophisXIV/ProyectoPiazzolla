 #ifndef __BridgeUSB_H__

    #define __BridgeUSB_H__

    #include <Hardware/Hardware_usage.h>

    #include <Hardware/GPIO.h>

    #include <Hardware/Diagnostic/Monitor.h>

    class USB_PORT_TX: protected Error_Monitor //,public USBSerial
    {
        
        public:

        USB_PORT_TX ();

        void inicializar();

        private:

        //USBSerial USB_TX;
        
    };

#endif