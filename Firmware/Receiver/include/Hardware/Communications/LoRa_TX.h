 #ifndef __LoRa_TX_H__

    #define __LoRa_TX_H__

    #include <Hardware/Hardware_usage.h>

    #include <Hardware/GPIO.h>

    #include <Hardware/Utilities/delayNB.h>

    #include <RadioLib.h>

    #include <Hardware/Analog/LDO.h>

    #define DEBUG_RX_LORA
    
    #ifdef DEBUG_RX_LORA
        #include <Hardware/Diagnostic/Monitor.h>
    #endif


    class LoRa_TX : protected Error_Monitor , public LDO_Reg{
        
        SX1276 sx1276 = new Module(CS_RF,DIO0,RESET_RF,DIO1);
        
        #ifdef DEBUG_RX_LORA
            USBSerial USB_RX_LORA;
        #endif

        public:

        LoRa_TX();

        uint8_t selfTest();

        void sendTemperatura();

        void sendPresion();
            
        void sendOrientacion();

        void sendVLDO();

        void sendVBatt();
        
        private:

        void setGPIO();
        
        struct echoTestVars{

            uint8_t numeroAleatorioRX[1] = {0};

            uint8_t tempEchoTestValue = 0;
            
        };

        echoTestVars *tempVarEchoTest = new echoTestVars;

        int8_t codigoErrorLoRa = 0; //No hay error 

        static volatile bool flagPaquete;   //Se define el flag de accion del paquete. 
                                            //Tiene que inicializarse antes de usarse.

        static volatile bool habilitacionISR;   //Se define la habilitacion de la ISR disparada por DIO0. 
                                                //Tiene que inicializarse antes de usarse.

        uint8_t echoTest();

        bool cambiarReceptor();

        static void LoRa_ISR_DIO0();    //Tiene que ser static porque 
                                        //no puede perderse la direccion 
                                        //de memoria ni el contenido de 
                                        //la funcion por mas que se cambie 
                                        //el scope y tiene que ser accesible por 
                                        //mas que un objeto de la clase 
                                        //no se haya creado como ocurre con el
                                        //uso iterno al setear la accion de DIO0

    };

#endif