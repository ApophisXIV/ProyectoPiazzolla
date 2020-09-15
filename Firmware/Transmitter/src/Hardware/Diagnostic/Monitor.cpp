#ifndef __Monitor_CPP__

    #define __Monitor_CPP__

    #include <Hardware/Diagnostic/Monitor.h>

    #include <Hardware/GPIO.h>

    #include <Hardware/Utilities/delayNB.h>

    void Error_Monitor::SetGPIO(){

        pinMode(LED_ERROR_A,1);
        pinMode(LED_ERROR_B,1);
        pinMode(LED_ERROR_C,1);
        pinMode(LED_ERROR_D,1);
    }
   
    void Error_Monitor::selfTest(){

        for (uint8_t i=0; i<15; i++){

            ErrorValue(i);
            delayNoBloqueante(100);
        }

    }
    
    void Error_Monitor::BarridoUSB_Conectando(){

        ErrorCodeInternal(1,0,0,0,20);
        ErrorCodeInternal(0,1,0,0,20);
        ErrorCodeInternal(0,0,1,0,20);
        ErrorCodeInternal(0,0,0,1,20);
        ErrorCodeInternal(0,0,0,1,20);
        ErrorCodeInternal(0,0,1,0,20);
        ErrorCodeInternal(0,1,0,0,20);
        ErrorCodeInternal(1,0,0,0,20);
    }

    void Error_Monitor::BeepBeep(uint8_t Transicion){

        ErrorCodeInternal(0,0,0,1,0);
        delayNoBloqueante(Transicion);
        ErrorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
        ErrorCodeInternal(0,0,0,1,0);
        delayNoBloqueante(Transicion);
        ErrorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
    }

    void Error_Monitor::BeepBeepAll(uint8_t Transicion){

        ErrorCodeInternal(1,1,1,1,0);
        delayNoBloqueante(Transicion);
        ErrorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
        ErrorCodeInternal(1,1,1,1,0);
        delayNoBloqueante(Transicion);
        ErrorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
    }

    void Error_Monitor::MensajeEntrante(uint8_t Transicion){

        ErrorCodeInternal(1,0,0,1,0);
        delayNoBloqueante(Transicion);
        ErrorCodeInternal(1,1,1,1,0);
        delayNoBloqueante(Transicion);
        ErrorCodeInternal(0,1,1,0,0);
        delayNoBloqueante(Transicion);
        ErrorCodeInternal(0,0,0,0,0);
        delayNoBloqueante(Transicion);
    }

    void Error_Monitor::ErrorValue(uint8_t Error){

        switch (Error){

            case 1:

            ErrorCodeInternal(0,0,0,1,0);
            
            break;

            case 2:

            ErrorCodeInternal(0,0,1,0,0);
        
            break;

            case 3:
            
            ErrorCodeInternal(0,0,1,1,0);

            break;

            
            case 4:
            
            ErrorCodeInternal(0,1,0,0,0);

            break;

            
            case 5:
            
            ErrorCodeInternal(0,1,0,1,0);

            break;

            
            case 6:
            
            ErrorCodeInternal(0,1,1,0,0);

            break;

            
            case 7:
            
            ErrorCodeInternal(0,1,1,1,0);

            break;

            
            case 8:
            
            ErrorCodeInternal(1,0,0,0,0);

            break;

            
            case 9:
            
            ErrorCodeInternal(1,0,0,1,0);

            break;

            
            case 10:
            
            ErrorCodeInternal(1,0,1,0,0);

            break;

            
            case 11:
            
            ErrorCodeInternal(1,0,1,1,0);

            break;

            
            case 12:
            
            ErrorCodeInternal(1,1,0,0,0);

            break;

            
            case 13:
            
            ErrorCodeInternal(1,1,0,1,0);

            break;

            
            case 14:
            
            ErrorCodeInternal(1,1,1,0,0);

            break;

            
            case 15:
            
            ErrorCodeInternal(1,1,1,1,0);

            break;

            default:

            //Revisar Juego de luces
            
            ErrorCodeInternal(1,0,0,0,80);

            ErrorCodeInternal(1,1,0,0,80);

            ErrorCodeInternal(1,1,1,0,80); 

            ErrorCodeInternal(1,1,1,1,80);

            ErrorCodeInternal(0,0,0,0,0);

            ErrorCodeInternal(1,1,1,1,0);

            delayNoBloqueante(200);

            ErrorCodeInternal(0,0,0,0,0);

            delayNoBloqueante(200);

            ErrorCodeInternal(1,1,1,1,0);

            delayNoBloqueante(200);

            ErrorCodeInternal(0,0,0,0,0);

            delayNoBloqueante(200);
            
            break;
        }
    }

    void Error_Monitor::ErrorCodeInternal(bool LED_D, bool LED_C, bool LED_B, bool LED_A, uint8_t Transicion) {

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
