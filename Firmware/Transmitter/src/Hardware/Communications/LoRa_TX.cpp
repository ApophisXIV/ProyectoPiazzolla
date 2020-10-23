#ifndef __LoRa_TX_CPP__

    #define __LoRa_TX_CPP__

    #include <Hardware/Communications/LoRa_TX.h>
    
    LoRa_TX::LoRa_TX(){

        LoRa_TX::setGPIO();

        #ifdef DEBUG_LORA
            LoRa_TX::UART3_DEBUG::printf(F("GPIO LoRa Seteado\n"));
            LoRa_TX::UART3_DEBUG::flush();
        #endif
    }

    void LoRa_TX::setGPIO(){

        pinMode(CS_RF,1);
        pinMode(RESET_RF,1);
        pinMode(DIO0,0);
        pinMode(DIO1,4);
        #ifdef DEBUG_LORA
            LoRa_TX::printf(F("Seed Random: %lu\n"),analogRead(DIO1));
            LoRa_TX::flush();
        #endif
        srand(analogRead(DIO1));
        pinMode(DIO1,0);
         
    }

    uint8_t LoRa_TX::selfTest(){

        //Comprobaciones
        //No hay error --> 0
        //Error de inicializacion --> 4
        //Error del echo_test --> 5
        //Error en el CRC del paquete --> 6
        //Error en el LDO --> 7
    /* --------------------- Inicializacion del modulo LoRa --------------------- */
        if(LoRa_TX::LDO_Reg::selfTest()){
            
            #ifdef DEBUG_LORA
                LoRa_TX::UART3_DEBUG::printf(F("LoRa Estado: Falla. Error en el LDO\n"));
                LoRa_TX::UART3_DEBUG::flush();
            #endif

            return (7);
        }

        else if(sx1276.begin(FRECUENCIA_LORA,\
                             ANCHO_DE_BANDA_LORA,\
                             FACTOR_DE_DISPERSION_LORA,\
                             CODING_RATE_LORA,\
                             SYNC_WORD_LORA,\
                             POTENCIA_LORA,PREAMBULO_LORA,\
                             GANANCIA_AGC_AUTO)){

            #ifdef DEBUG_LORA
                LoRa_TX::UART3_DEBUG::printf(F("LoRa Estado: Falla. Error al reinicializar\n"));
                LoRa_TX::UART3_DEBUG::flush();
            #endif

            LoRa_TX::Error_Monitor::errorValue(4);

            return (4); //Error de inicializacion
        }
        
        else{

            // sx1276.setFrequency(FRECUENCIA_LORA);
            // sx1276.setBandwidth(ANCHO_DE_BANDA_LORA);
            // sx1276.setSpreadingFactor(FACTOR_DE_DISPERSION_LORA);
            // sx1276.setCodingRate(CODING_RATE_LORA);
            // sx1276.setSyncWord(SYNC_WORD_LORA);
            // sx1276.setOutputPower(POTENCIA_LORA);
            // sx1276.setPreambleLength(PREAMBULO_LORA);
            // sx1276.setGain(GANANCIA_AGC_AUTO);
            
            tempVarEchoTest->tempEchoTestValue = echoTest();

            if(!tempVarEchoTest->tempEchoTestValue){
                
                #ifdef DEBUG_LORA
                    LoRa_TX::UART3_DEBUG::printf(F("Estado echo: OK. Prueba completada exitosamente\n"));
                    LoRa_TX::UART3_DEBUG::flush();
                #endif

                //Se libera el espacio de memoria
                delete tempVarEchoTest;

                LoRa_TX::Error_Monitor::errorValue(0);

                return (0); //Se completo la prueba de echo y el dispositivo fue re-configurado a
                            //su modo de operación normal
            }

            else if (tempVarEchoTest->tempEchoTestValue == 2){

                #ifdef DEBUG_LORA
                    LoRa_TX::UART3_DEBUG::printf(F("Estado echo: Falla. Error en el CRC del mensaje\n"));
                    LoRa_TX::UART3_DEBUG::flush();
                #endif

                LoRa_TX::Error_Monitor::errorValue(6);

                return (6); //Si bien el mensaje pudo ser leido, se detectaron errores en el CRC
            }

            else{
                
                #ifdef DEBUG_LORA
                    LoRa_TX::UART3_DEBUG::printf(F("Estado echo: Falla. No se establecio canal de comunicacion con base\n"));
                    LoRa_TX::UART3_DEBUG::flush();
                #endif

                LoRa_TX::Error_Monitor::errorValue(5);

                return (5); //El dispositivo fue inicializado correctamente pero
                            //no se pudo establecer un canal de comunicacion entre
                            //la base terrena y el dispositivo transmisor
            }

            
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

    uint8_t LoRa_TX::echoTest(){

        //Se asigna el valor aleatorio de prueba para enviar
        tempVarEchoTest->numeroAleatorioTX [0] = rand() % BYTE_FULL;       
                
        #ifdef DEBUG_LORA
            LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Mensaje a enviar: %d\n"),tempVarEchoTest->numeroAleatorioTX[0]);
            LoRa_TX::UART3_DEBUG::flush();
        #endif

        //Se asocia la ISR disparada por DIO0
        sx1276.setDio0Action(LoRa_ISR_DIO0);  
        
        //Se realiza el test hasta que este completo --> Transmision y lectura de paquete
        while(1){

            #ifdef DEBUG_LORA
                LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Variables:   CodigoErrorLoRa = %i\n\
                        TX_RX_estadoActual = %i\n\
                        RX_SetOnce = %i\n\
                        flagPaquete = %i\n\
                        habilitacionISR = %i\n\n"),\
                        codigoErrorLoRa,\
                        tempVarEchoTest->TX_RX_estadoActual,\
                        tempVarEchoTest->RX_SetOnce,\
                        flagPaquete,\
                        habilitacionISR);
                LoRa_TX::UART3_DEBUG::flush();
            #endif

            //Se verifica si esta configurado como TX o RX

            //Modo TX (Ping)
            if(!tempVarEchoTest->TX_RX_estadoActual){

                //Se configura en modo transmisor 
                codigoErrorLoRa = sx1276.startTransmit(tempVarEchoTest->numeroAleatorioTX,sizeof(tempVarEchoTest->numeroAleatorioTX));

                if(codigoErrorLoRa!=0){
                    
                    #ifdef DEBUG_LORA
                        LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Error al configurar en modo TX. CodigoError: %d\n"),codigoErrorLoRa);
                        LoRa_TX::UART3_DEBUG::flush();
                    #endif

                    //Error en la configuracion en modo TX
                    return (1);
                }
                
                else{
                    
                    #ifdef DEBUG_LORA
                        LoRa_TX::UART3_DEBUG::printf(F("Echo Test. El mensaje fue transmitido correctamente. PING. CodigoError: %d\n"),codigoErrorLoRa);
                        LoRa_TX::UART3_DEBUG::flush();
                    #endif

                    //No vuelve a efectuarse una transmision mas durante la prueba echoTest
                    tempVarEchoTest->TX_RX_estadoActual = 1;

                }
            }

            //Modo RX (Pong)
            else{
                
                //Se configura en modo receptor una unica vez
                if(!tempVarEchoTest->RX_SetOnce){

                    //Se configura en modo receptor 
                    codigoErrorLoRa = sx1276.startReceive(sizeof(tempVarEchoTest->numeroAleatorioRX),SX127X_RXCONTINUOUS);
                    
                    if(codigoErrorLoRa!=0){

                        #ifdef DEBUG_LORA
                            LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Error al configurar en modo RX. CodigoError: %d\n"),codigoErrorLoRa);
                            LoRa_TX::UART3_DEBUG::flush();
                        #endif

                        //Error en la configuracion en modo RX
                        return (1);
                    }

                    else{

                        #ifdef DEBUG_LORA
                            LoRa_TX::UART3_DEBUG::printf(F("Echo Test. El dispositivo fue configurado en modo RX. Esprando PONG. CodigoError: %d\n"),codigoErrorLoRa);
                            LoRa_TX::UART3_DEBUG::flush();
                        #endif

                        //No vuelve a configurarse mas como receptor durante la prueba echoTest
                        tempVarEchoTest->RX_SetOnce = 1;

                    }
                }
                
                else{

                    LoRa_TX::Error_Monitor::mensajeEntrante(80);

                    if(flagPaquete){
                        
                        #ifdef DEBUG_LORA
                            LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Se recibio un mensaje. Posible PONG.\n"));
                            LoRa_TX::UART3_DEBUG::flush();
                        #endif

                        //Se previenen interrupciones durante la lectura de la FIFO con el ultimo paquete recibido
                        habilitacionISR = 0;

                        //Se rearma el disparo de la interrupcion
                        flagPaquete = 0;

                        //Se lee el paquete recibido y se almacena su contenido (payload) en array numeroAleatorioRX
                        codigoErrorLoRa = sx1276.readData(tempVarEchoTest->numeroAleatorioRX,sizeof(tempVarEchoTest->numeroAleatorioRX));

                        if(!codigoErrorLoRa){

                            #ifdef DEBUG_LORA
                                LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Mensaje leido correctamente. Posible PONG. CodigoError: %d\n"),codigoErrorLoRa);
                                LoRa_TX::UART3_DEBUG::flush();
                            #endif

                            //Se verifica que el payload del paquete enviado es igual al del paquete recibido
                            if(tempVarEchoTest->numeroAleatorioTX[0]==tempVarEchoTest->numeroAleatorioRX[0]){
                                
                                #ifdef DEBUG_LORA
                                    LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Mensaje correcto. PONG. Mensaje leido: %d\n"),tempVarEchoTest->numeroAleatorioRX[0]);
                                    LoRa_TX::UART3_DEBUG::flush();
                                #endif

                                delete tempVarEchoTest;

                                //La prueba se completo satisfactoriamente
                                return (0);
                            }

                            else{
                                
                                #ifdef DEBUG_LORA
                                    LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Error mensaje incorrecto. Mensaje leido: %d\n"),tempVarEchoTest->numeroAleatorioRX[0]);
                                    LoRa_TX::UART3_DEBUG::flush();
                                #endif

                                //El paquete leido es diferente al que se envio
                                return (1);
                            }

                        }

                        else if(codigoErrorLoRa == 2){
                            
                            #ifdef DEBUG_LORA
                                LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Error CRC del paquete leido mal formado. CodigoError: %d\n"),codigoErrorLoRa);
                                LoRa_TX::UART3_DEBUG::flush();
                            #endif

                            //Error en el CRC del paquete
                            return (2);

                        }

                        else{
                            
                            #ifdef DEBUG_LORA
                                LoRa_TX::UART3_DEBUG::printf(F("Echo Test. Error al leer el paquete. CodigoError: %d\n"),codigoErrorLoRa);
                                LoRa_TX::UART3_DEBUG::flush();
                            #endif

                            //Error en la lectura del paquete
                            return(1);
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



