 #ifndef __UART_debug_H__

    #define __UART_debug_H__

    #include <Hardware/GPIO.h>

    #include <Hardware/Utilities/delayNB.h>
    
    class UART3_DEBUG : public HardwareSerial{
                
        public:
        
        UART3_DEBUG ();

        private:
        
        void inicializar(); 

    };


#endif