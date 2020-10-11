#ifndef __LoRa_TX_CPP__

    #define __LoRa_TX_CPP__

    #include <Hardware/Communications/LoRa_TX.h>
    
    void LoRa_TX::setGPIO(){

        pinMode(CS_RF,1);
        pinMode(RESET_RF,1);
        pinMode(DIO0,0);
        pinMode(DIO1,0);
         
    }

    //El SX envia un pulso solamente para indicar 
    //que el paquete de datos se envio
    //              ___
    //SX1276 -> ____| |_______ -> STM32

    uint8_t LoRa_TX::selfTest(){

        //https://electronics.stackexchange.com/questions/277722/how-to-calculate-the-data-rate-of-lora
        // Doxygen --> https://jgromes.github.io/RadioLib/

        //Comprobaciones
        //No hay error --> 0
        //Error de inicializacion --> 4
        //Error del echo_test --> 5

    /* --------------------------- Seteo de Parametros -------------------------- */

        sx1276.setFrequency(FRECUENCIA_LORA);
        sx1276.setBandwidth(ANCHO_DE_BANDA_LORA);
        sx1276.setSpreadingFactor(FACTOR_DE_DISPERSION_LORA);
        sx1276.setCodingRate(CODING_RATE_LORA);
        sx1276.setSyncWord(SYNC_WORD_LORA);
        sx1276.setOutputPower(POTENCIA_LORA);
        sx1276.setPreambleLength(PREAMBULO_LORA);
        sx1276.setGain(GANANCIA_AGC_AUTO);
    
    /* --------------------- Inicializacion del modulo LoRa --------------------- */

        if(sx1276.begin()){

            return (4); //Error de inicializacion
        }
        
        else{
            
            if(!echoTest()){
                
                return (0); //Se completo la prueba de echo y el dispositivo fue
                            //inicializado correctamente
            }

            else{

                return (5); //El dispositivo fue inicializado correctamente pero
                            //no se pudo establecer un canal de comunicacion entre
                            //la base terrena y el dispositivo transmisor
            }

            //TODO --> Hacer el codigo necesario para el "pong" desde la base
            
            // TX(Real)-->RX(Virtual) y se queda a la espera de recibir un mensaje 
            // desde la base. Una vez que lo recibe se pone en modo transmisor y lo 
            // reenvia al RX(Real) en base.

        }

        return (4);        
       
    }
    
    void LoRa_TX::sendTemperatura(){}
    
    void LoRa_TX::sendPresion(){}    
    
    void LoRa_TX::sendOrientacion(){}
    
    void LoRa_TX::sendVLDO(){}
    
    void LoRa_TX::sendVBatt(){}
    
    //Se incializa el flag asociado a la accion de un paquete
    volatile bool LoRa_TX::flagPaquete = 0;

    //Se inicializa la variable que determina la habilitacion de la ISR disparada por DIO0
    volatile bool LoRa_TX::habilitacionISR = 1;

    bool LoRa_TX::echoTest(){
        
        //Se asigna el valor aleatorio de prueba para enviar
        tempVarEchoTest->numeroAleatorioTX [0] = rand() % BYTE_FULL;       
        
        usbLora.printf("Numero a enviar: %i\n",tempVarEchoTest->numeroAleatorioTX[0]);

        //Se asocia la ISR disparada por DIO0
        sx1276.setDio0Action(LoRa_ISR_DIO0);  
        
        //Se realiza el test hasta que este completo --> Transmision y lectura de paquete
        while(1){

            //Se verifica si esta configurado como TX o RX

            //Modo TX (Ping)
            if(!tempVarEchoTest->TX_RX_estadoActual){
                
                //Se configura en modo transmisor 
                if(sx1276.startTransmit(tempVarEchoTest->numeroAleatorioTX,sizeof(tempVarEchoTest->numeroAleatorioTX))!=0){
                    
                    //Error en la configuracion en modo TX
                    return (1);
                }

                usbLora.println("Transmision efectuada");

                //No vuelve a efectuarse una transmision mas durante la prueba echoTest
                tempVarEchoTest->TX_RX_estadoActual = 1;
            }

            //Modo RX (Pong)
            else{
                
                //Se configura en modo receptor una unica vez
                if(!tempVarEchoTest->RX_SetOnce){
                    
                    //Se configura en modo receptor 
                    if(sx1276.startReceive(sizeof(tempVarEchoTest->numeroAleatorioRX),SX127X_RXCONTINUOUS)!=0){

                        //Error en la configuracion en modo RX
                        return (1);
                    }

                    usbLora.println("Estado: RX");

                    //No vuelve a configurarse mas como receptor durante la prueba echoTest
                    tempVarEchoTest->RX_SetOnce = 1;
                }
                
                else{

                    if(flagPaquete){
                        
                        usbLora.println("Pong recibido");

                        //Se previenen interrupciones durante la lectura de la FIFO con el ultimo paquete recibido
                        habilitacionISR = 0;

                        //Se rearma el disparo de la interrupcion
                        flagPaquete = 0;

                        //Se lee el paquete recibido y se almacena su contenido (payload) en array numeroAleatorioRX
                        if(sx1276.readData(tempVarEchoTest->numeroAleatorioRX,sizeof(tempVarEchoTest->numeroAleatorioRX)) != 0){
                            
                            //Error en la lectura del paquete
                            return (1);

                        }

                        else{
                            
                            usbLora.println("Paquete leido");

                            //Se verifica que el payload del paquete enviado es igual al del paquete recibido
                            if(tempVarEchoTest->numeroAleatorioTX[0]==tempVarEchoTest->numeroAleatorioRX[0]){
                                
                                usbLora.println("Prueba exitosa");

                                delete tempVarEchoTest;

                                //La prueba se completo satisfactoriamente
                                return (0);
                            }

                            else{
                                
                                //El paquete leido es diferente al que se envio
                                return (1);
                            }

                        }

                    }
        
                }

            }

        }

        return (1);
    }

    //Funcion referenciada a la interrupcion DIO0 durante echoTest()
    void LoRa_TX::LoRa_ISR_DIO0(){
        
        //Si se desactivo el ISR entonces retorna al punto actual. Ej.: Recepcion de un paquete de forma simultanea a la lectura de uno en cola
        if(!habilitacionISR){
            
            return;
        } 
        
        //Flag de accion del paquete. Modo TX -> El paquete fue enviado. Modo RX -> Un paquete fue recibido
        flagPaquete = 1;
                
    }
        
        //Esta con bateria
        //TX -> RX -> TX -> Modo normal
        /*
        -Me pongo en transmisor
        -Mando una palabra
        -Me pongo en receptor
        -Espero la misma palabra
        -Recibo la palabra
        -Guardo la palabra
        -Me pongo en transmisor
        -Reenvio la palabra guardada
        -Me quedo operando normalmente        
        */

        //Esta conectado a la PC
        //RX -> TX -> RX -> Modo normal
    


#endif



