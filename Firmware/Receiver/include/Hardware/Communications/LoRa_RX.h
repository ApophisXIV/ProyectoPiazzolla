 #ifndef __LoRa_RX_H__

    #define __LoRa_RX_H__

    #include <Hardware/Hardware_usage.h>

    #include <Hardware/GPIO.h>

    #include <Hardware/Utilities/delayNB.h>

    #include <RadioLib.h>

    #include <Hardware/Analog/LDO.h>

    #include <Hardware/Diagnostic/Monitor.h>

    #define DEBUG_LORA

    class LoRa_RX : protected Error_Monitor , public LDO_Reg , virtual public USBSerial {
        
        SX1276 sx1276 = new Module(CS_RF,DIO0,RESET_RF,DIO1);
        
        public:

        LoRa_RX();

        uint8_t selfTest();
        
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