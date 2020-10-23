 #ifndef __UART_debug_CPP__

    #define __UART_debug_CPP__

    #include <Hardware/Communications/UART_debug.h>

    UART3_DEBUG::UART3_DEBUG () : HardwareSerial(UART3_RX,UART3_TX){

        UART3_DEBUG::inicializar();

    }

    void UART3_DEBUG::inicializar(){

        UART3_DEBUG::HardwareSerial::begin(115200,0x06); // 8 Bits - Sin paridad - 1 Bit de parada

    }

    // void UART3_DEBUG::outDebug(uint32_t numeroUI32){

    //     UART3_DEBUG::__UART3_Debug->println(numeroUI32);
    // }
                
    // void UART3_DEBUG::outDebug(int32_t numeroSI32){

    //     UART3_DEBUG::__UART3_Debug->println(numeroSI32);
    // }

    // void UART3_DEBUG::outDebug(float_t numeroF){

    //     UART3_DEBUG::__UART3_Debug->println(numeroF);
    // }

    // void UART3_DEBUG::outDebug(const __FlashStringHelper *cadenaGuardadaEnFlash){

    //     UART3_DEBUG::__UART3_Debug->println(cadenaGuardadaEnFlash);
    // }

    // void UART3_DEBUG::outDebug(char *cadena){

    //     UART3_DEBUG::__UART3_Debug->println(cadena);
    // }

#endif