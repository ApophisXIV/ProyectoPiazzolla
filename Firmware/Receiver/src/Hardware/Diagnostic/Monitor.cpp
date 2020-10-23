#ifndef __Monitor_CPP__

    #define __Monitor_CPP__

    #include <Hardware/Diagnostic/Monitor.h>

    Error_Monitor::Error_Monitor(){
        
        Error_Monitor::setGPIO();

    }

    void Error_Monitor::setGPIO(){

        pinMode(LED_ERROR_A,1);
        pinMode(LED_ERROR_B,1);
        pinMode(LED_ERROR_C,1);
        pinMode(LED_ERROR_D,1);
    }
   
    void Error_Monitor::selfTest(){

        for (uint8_t i=0; i<15; i++){

            Error_Monitor::errorValue(i);
            delayNoBloqueante(10);
        }

        Error_Monitor::errorValue(0);

    }
    
    void Error_Monitor::barridoUSB_Conectando(){

        Error_Monitor::errorCodeInternal(1,0,0,0,50);
        Error_Monitor::errorCodeInternal(0,1,0,0,50);
        Error_Monitor::errorCodeInternal(0,0,1,0,50);
        Error_Monitor::errorCodeInternal(0,0,0,1,50);
        Error_Monitor::errorCodeInternal(0,0,0,1,50);
        Error_Monitor::errorCodeInternal(0,0,1,0,50);
        Error_Monitor::errorCodeInternal(0,1,0,0,50);
        Error_Monitor::errorCodeInternal(1,0,0,0,50);
    }

    void Error_Monitor::beepBeep(uint8_t Transicion){

        Error_Monitor::errorCodeInternal(0,0,0,1,0);
        delayNoBloqueante(Transicion);
        Error_Monitor::errorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
        Error_Monitor::errorCodeInternal(0,0,0,1,0);
        delayNoBloqueante(Transicion);
        Error_Monitor::errorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
    }

    void Error_Monitor::beepBeepAll(uint8_t Transicion){

        Error_Monitor::errorCodeInternal(1,1,1,1,0);
        delayNoBloqueante(Transicion);
        Error_Monitor::errorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
        Error_Monitor::errorCodeInternal(1,1,1,1,0);
        delayNoBloqueante(Transicion);
        Error_Monitor::errorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
    }

    void Error_Monitor::mensajeEntrante(uint8_t Transicion){

        Error_Monitor::errorCodeInternal(1,0,0,1,0);
        delayNoBloqueante(Transicion);
        Error_Monitor::errorCodeInternal(1,1,1,1,0);
        delayNoBloqueante(Transicion);
        Error_Monitor::errorCodeInternal(0,1,1,0,0);
        delayNoBloqueante(Transicion);
        Error_Monitor::errorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
    }

    uint8_t Error_Monitor::errorValue(uint8_t Error){

        switch (Error){

            case 1:

            Error_Monitor::errorCodeInternal(0,0,0,1,0);
            
            break;

            case 2:

            Error_Monitor::errorCodeInternal(0,0,1,0,0);
        
            break;

            case 3:
            
            Error_Monitor::errorCodeInternal(0,0,1,1,0);

            break;

            
            case 4:
            
            Error_Monitor::errorCodeInternal(0,1,0,0,0);

            break;

            
            case 5:
            
            Error_Monitor::errorCodeInternal(0,1,0,1,0);

            break;

            
            case 6:
            
            Error_Monitor::errorCodeInternal(0,1,1,0,0);

            break;

            
            case 7:
            
            Error_Monitor::errorCodeInternal(0,1,1,1,0);

            break;

            
            case 8:
            
            Error_Monitor::errorCodeInternal(1,0,0,0,0);

            break;

            
            case 9:
            
            Error_Monitor::errorCodeInternal(1,0,0,1,0);

            break;

            
            case 10:
            
            Error_Monitor::errorCodeInternal(1,0,1,0,0);

            break;

            
            case 11:
            
            Error_Monitor::errorCodeInternal(1,0,1,1,0);

            break;

            
            case 12:
            
            Error_Monitor::errorCodeInternal(1,1,0,0,0);

            break;

            
            case 13:
            
            Error_Monitor::errorCodeInternal(1,1,0,1,0);

            break;

            
            case 14:
            
            Error_Monitor::errorCodeInternal(1,1,1,0,0);

            break;

            
            case 15:
            
            Error_Monitor::errorCodeInternal(1,1,1,1,0);

            break;

            default:

            //Revisar Juego de luces
            
            Error_Monitor::errorCodeInternal(1,0,0,0,80);

            Error_Monitor::errorCodeInternal(1,1,0,0,80);

            Error_Monitor::errorCodeInternal(1,1,1,0,80); 

            Error_Monitor::errorCodeInternal(1,1,1,1,80);

            Error_Monitor::errorCodeInternal(0,0,0,0,0);

            Error_Monitor::errorCodeInternal(1,1,1,1,0);

            delayNoBloqueante(200);

            Error_Monitor::errorCodeInternal(0,0,0,0,0);

            delayNoBloqueante(200);

            Error_Monitor::errorCodeInternal(1,1,1,1,0);

            delayNoBloqueante(200);

            Error_Monitor::errorCodeInternal(0,0,0,0,0);

            delayNoBloqueante(200);
            
            break;
        }

        return (0);
    }

    void Error_Monitor::errorCodeInternal(bool LED_D, bool LED_C, bool LED_B, bool LED_A, uint8_t Transicion) {

        digitalWrite(LED_ERROR_A,LED_A);
        delayNoBloqueante(Transicion);
        digitalWrite(LED_ERROR_B,LED_B);
        delayNoBloqueante(Transicion);
        digitalWrite(LED_ERROR_C,LED_C);
        delayNoBloqueante(Transicion);
        digitalWrite(LED_ERROR_D,LED_D);
        delayNoBloqueante(Transicion);
    }

#endif
