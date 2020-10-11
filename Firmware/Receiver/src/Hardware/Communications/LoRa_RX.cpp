#ifndef __LoRa_RX_CPP__

    #define __LoRa_RX_CPP__

    #include <Hardware/Communications/LoRa_RX.h>
    
    LoRa_RX::LoRa_RX(){

        LoRa_RX::setGPIO();

    }

    void LoRa_RX::setGPIO(){

        pinMode(CS_RF,1);
        pinMode(RESET_RF,1);
        pinMode(DIO0,0);
        pinMode(DIO1,0);
         
    }

    uint8_t LoRa_RX::selfTest(){

        //Comprobaciones
        //No hay error --> 0
        //Error de inicializacion --> 4
        //Error del echo_test --> 5
        //Error en el CRC del paquete --> 6
        //Error en el LDO --> 7
    /* --------------------- Inicializacion del modulo LoRa --------------------- */
        if(LoRa_RX::LDO_Reg::selfTest()){
            
            float_t VLDO = analogRead(LDO_ADC)*0.0008056640625;

            #ifdef DEBUG_RX_LORA
                USB_RX_LORA.print("\nError LDO. V: \n");
                USB_RX_LORA.println(VLDO);
                
                VLDO = analogRead(ADC_CHANNEL_TEMPSENSOR);

                USB_RX_LORA.print("\nVRef INT: \n");
                USB_RX_LORA.println(VLDO);
            #endif
            
            return (7);
        }

        else if((sx1276.begin())){

            #ifdef DEBUG_RX_LORA
                USB_RX_LORA.printf("\nError en el begin. L:48\n");
            #endif

            LoRa_RX::Error_Monitor::errorValue(4);

            return (4); //Error de inicializacion
        }
        
        else{

            sx1276.setFrequency(FRECUENCIA_LORA);
            sx1276.setBandwidth(ANCHO_DE_BANDA_LORA);
            sx1276.setSpreadingFactor(FACTOR_DE_DISPERSION_LORA);
            sx1276.setCodingRate(CODING_RATE_LORA);
            sx1276.setSyncWord(SYNC_WORD_LORA);
            sx1276.setOutputPower(POTENCIA_LORA);
            sx1276.setPreambleLength(PREAMBULO_LORA);
            sx1276.setGain(GANANCIA_AGC_AUTO);

            sx1276.startReceive();//Ver de ponerlo de nuevo en el if de arriba

            tempVarEchoTest->tempEchoTestValue = echoTest();

            if(!tempVarEchoTest->tempEchoTestValue){

                //Se libera el espacio de memoria
                delete tempVarEchoTest;

                LoRa_RX::Error_Monitor::errorValue(0);

                return (0); //Se completo la prueba de echo y el dispositivo fue re-configurado a
                            //su modo de operación normal
            }
            
            else if(tempVarEchoTest->tempEchoTestValue == 2){
                
                LoRa_RX::Error_Monitor::errorValue(6);

                return (6); //Si bien el mensaje pudo ser leido, se detectaron errores en el CRC
            }

            else{
                
                LoRa_RX::Error_Monitor::errorValue(5);

                return (5); //El dispositivo fue inicializado correctamente pero
                            //no se pudo reenviar el mensaje recibido desde el
                            //dispositivo transmisor
            }

        }

        return (4);        
       
    }
    
    void LoRa_RX::sendTemperatura(){}
    
    void LoRa_RX::sendPresion(){}    
    
    void LoRa_RX::sendOrientacion(){}
    
    void LoRa_RX::sendVLDO(){}
    
    void LoRa_RX::sendVBatt(){}
    
    //Se incializa el flag asociado a la accion de un paquete
    volatile bool LoRa_RX::flagPaquete = 0;

    //Se inicializa la variable que determina la habilitacion de la ISR disparada por DIO0
    volatile bool LoRa_RX::habilitacionISR = 1;

    uint8_t LoRa_RX::echoTest(){
        
        //Se asocia la ISR disparada por DIO0
        sx1276.setDio0Action(LoRa_ISR_DIO0);  
        
        //Se realiza el test hasta que este completo --> Lectura y transmision de paquete
        while(1){
            
            LoRa_RX::Error_Monitor::mensajeEntrante(80);

            //Se disparo la ISR asociada a DIO0
            if(flagPaquete){
                
                //Se previenen interrupciones durante la lectura de la FIFO con el ultimo paquete recibido
                habilitacionISR = 0;

                //Se rearma el disparo de la interrupcion
                flagPaquete = 0;

                //Se lee el paquete recibido, se almacena su contenido (payload) en el array numeroAleatorioRX y se almacena el codigo de error
                codigoErrorLoRa = sx1276.readData(tempVarEchoTest->numeroAleatorioRX,sizeof(tempVarEchoTest->numeroAleatorioRX));
                
                #ifdef DEBUG_RX_LORA
                    USB_RX_LORA.printf("Paquete recibido: %i \n RSSI: %1.2f \n SNR: %1.2f \n CodErr: %i \n",tempVarEchoTest->numeroAleatorioRX[0],sx1276.getRSSI(),sx1276.getSNR(),codigoErrorLoRa);
                #endif

                //No hay error en la lectura
                if(!codigoErrorLoRa){

                    delayNoBloqueante(200);

                    //Se configura en modo transmisor y se almacena el resultado del codigo de error. Pong.
                    if(sx1276.startTransmit(tempVarEchoTest->numeroAleatorioRX,sizeof(tempVarEchoTest->numeroAleatorioRX)) != 0){
               
                        #ifdef DEBUG_RX_LORA
                            USB_RX_LORA.printf("\nError Transmision. L:129\n");
                        #endif
        
                        //Error en la configuracion en modo TX
                        return (1);
                    }

                    //El paquete fue enviado correctamente.
                    else{

                        //Se re-configura a su estado normal
                        if(sx1276.startReceive()){

                            #ifdef DEBUG_RX_LORA
                                USB_RX_LORA.printf("\nError re-inicializacion. L:143\n");
                            #endif

                            return (1); //Error de re-inicializacion
                        }
                        
                        else{

                            #ifdef DEBUG_RX_LORA
                                USB_RX_LORA.printf("\nSe completo el 'pong'. L:152\n");
                            #endif

                            //Se habilita nuevamente la ISR asociada a DIO0
                            habilitacionISR = 1;

                            return (0); //Se completo la prueba de echo y el dispositivo fue
                                        //re-inicializado correctamente
                        }

                    }

                    //Error en la lectura del paquete
                    return (1);

                }

                //No hubo error en la lectura pero el paquete tiene errores
                else if (codigoErrorLoRa == -7){
                    
                    #ifdef DEBUG_RX_LORA
                        USB_RX_LORA.printf("\nError CRC paquete. L:173\n");
                    #endif                 
                    
                    //Error en el CRC del paquete
                    return (2);
                }

                else{

                    #ifdef DEBUG_RX_LORA
                        USB_RX_LORA.printf("\nError desconocido. L:183\n");
                    #endif 

                    //Error desconocido durante la lectura del paquete
                    return (1);
                }

            }

        }

        return (1);
    }

    //Funcion referenciada a la interrupcion DIO0 durante echoTest()
    void LoRa_RX::LoRa_ISR_DIO0(){
        
        //Si se desactivo el ISR entonces retorna al punto actual. Ej.: Recepcion de un paquete de forma simultanea a la lectura de uno en cola
        if(!habilitacionISR){
            
            return;
        } 

        //Flag de accion del paquete. Modo TX -> El paquete fue enviado. Modo RX -> Un paquete fue recibido
        flagPaquete = 1;
                
    }
        
#endif