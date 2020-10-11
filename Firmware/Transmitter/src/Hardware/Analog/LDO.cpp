#ifndef __LDO_CPP__

    #define __LDO_CPP__

    #include <Hardware/Analog/LDO.h>

    void LDO_Reg::setGPIO(){

        pinMode(LDO_ENABLE,1);
        pinMode(LDO_ADC,4); // 4 = Entrada analogica -> Canal del ADC
    }

    bool LDO_Reg::selfTest(){

        digitalWrite(LDO_ENABLE,1);
        
        //HAL_GPIO_WritePin(GPIOB,5,GPIO_PIN_SET);

        if(ADC_RES*analogRead(LDO_ADC)<=3.00){//~90% de la tensión nominal de trabajo del regulador 

            digitalWrite(LDO_ENABLE,0);

            return (1);

        }

        else{

            digitalWrite(LDO_ENABLE,0);

            if(ADC_RES*analogRead(LDO_ADC)>=0.33){//~10% de la tensión nominal de trabajo del regulador 

                digitalWrite(LDO_ENABLE,0); //Reintenta apagar el regulador

                return (1);

            }

            else{

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