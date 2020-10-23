#ifndef __LDO_CPP__

    #define __LDO_CPP__

    #include <Hardware/Analog/LDO.h>

    LDO_Reg::LDO_Reg(){

        LDO_Reg::setGPIO();
        
        #ifdef DEBUG_LDO
            LDO_Reg::USBSerial::printf(F("GPIO LDO Seteado\n"));
            LDO_Reg::USBSerial::flush();
        #endif
    }

    void LDO_Reg::setGPIO(){

        pinMode(LDO_ENABLE,1);
        pinMode(LDO_ADC,4); // 4 = Entrada analogica -> Canal del ADC
        analogReadResolution(12);
    }

    bool LDO_Reg::selfTest(){

        digitalWrite(LDO_ENABLE,1);
       
        #ifdef DEBUG_LDO
            LDO_Reg::UART3_DEBUG::printf(F("LDO ENABLE: 1. VLDO: %lu\n"),analogRead(LDO_ADC));
            LDO_Reg::UART3_DEBUG::flush();
        #endif

        if(analogRead(LDO_ADC)<=3723){//~90% de la tensión nominal de trabajo del regulador 
            
            #ifdef DEBUG_LDO
                LDO_Reg::UART3_DEBUG::printf(F("LDO Estado: Falla. Menor tension de la esperada\n"));
                LDO_Reg::UART3_DEBUG::flush();
            #endif

            digitalWrite(LDO_ENABLE,0);

            return (1);

        }

        else{

            digitalWrite(LDO_ENABLE,0);

            #ifdef DEBUG_LDO
                LDO_Reg::UART3_DEBUG::printf(F("LDO ENABLE: 0. VLDO: %lu\n"),analogRead(LDO_ADC));
                LDO_Reg::UART3_DEBUG::flush();
            #endif

            if(analogRead(LDO_ADC)>=409){//~10% de la tensión nominal de trabajo del regulador 

                #ifdef DEBUG_LDO
                    LDO_Reg::UART3_DEBUG::printf(F("LDO Estado: Falla. Mayor tension de la esperada\n"));
                    LDO_Reg::UART3_DEBUG::flush();
                #endif

                digitalWrite(LDO_ENABLE,0); //Reintenta apagar el regulador

                return (1);

            }

            else{

                #ifdef DEBUG_LDO
                    LDO_Reg::UART3_DEBUG::printf(F("LDO Estado: OK. Prueba exitosa!!\n"));
                    LDO_Reg::UART3_DEBUG::flush();
                #endif

                digitalWrite(LDO_ENABLE,1);
                
                return (0);
            }

        } 

    }

    uint16_t LDO_Reg::tensionActual(){
        
        float_t tensionLDO = ADC_RES*analogRead(LDO_ADC);
        //TODO --> Lectura de tension 16 bits integer
        
        return (conversionAndRedondeo(tensionLDO));
    }

#endif