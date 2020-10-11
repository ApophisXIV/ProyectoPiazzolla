#ifndef _MEM_SD_CPP__
    
    #define __Mem_SD_CPP__

    #include <Hardware/Storage/Mem_SD.h>

    void SD_CARD::setGPIO(){

        pinMode(CS_CARD,1);
        pinMode(CARD_DS,0);
        pinMode(WRITE_PROTECT,0);
    }

    uint8_t SD_CARD::selfTest(){
        
        /*Autotest -->  Si puede escribir, leer e inicializar la SD entonces esta aprobado.
                        Para la escritura debe generar un dato aleatorio. Este es el que sera utilizado
                        en la escritura.
        */         
        
        #ifdef DEBUG_SD
            USBSerial USB_TX_SD;
        #endif
        
        if(tarjetaInsertadaEnSlot()||dataProtect()){

            return (2);
        }

        //Si falla en la inicializacion
        else{
            
            if(!SD.begin(SPI_QUARTER_SPEED, CS_CARD)){ 
            
                #ifdef DEBUG_SD
                    USB_TX_SD.println(F("Fallo en begin"));
                #endif

                return (3);  
                
                /* 
                TODO ERROR TARJETA
                Cuando falle desde afuera de este archivo 
                cuando se use el metodo de la clase 
                entonces tiene que mostrar el error en el 
                monitor de errores y bloquee el programa 
                pidiendole al usuario con el codigo que 
                lo reinicie manualmente al micro
                */
                //https://marketplace.visualstudio.com/items?itemName=Gruntfuggly.todo-tree
            
            }
        
            //En caso de que inicialice correctamente
            else{
            
                if(SD.exists("echo.txt")){
                
                    SD.remove("echo.txt");
                }

                uint8_t numeroAleatorioTest = rand() % BYTE_FULL;
                
                #ifdef DEBUG_SD
                    USB_TX_SD.print(F("Numero de prueba= "));
                    USB_TX_SD.println(numeroAleatorioTest,DEC);
                #endif
    /* --------------------- Escritura del archivo de prueba -------------------- */

                archivoSelfTest = SD.open("echo.txt", FILE_WRITE);

                if(archivoSelfTest){

                    archivoSelfTest.print(numeroAleatorioTest);

                    archivoSelfTest.close();
                }

                else{

                    //TODO --> No se pudo abrir correctamente el archivo alerta
                    
                    #ifdef DEBUG_SD                
                        USB_TX_SD.println(F("Fallo en archivoSelfTest"));
                    #endif

                    return (3);
                }

    /* ----------------- Comienza lectura del archivo de prueba ----------------- */

                archivoSelfTest = SD.open("echo.txt",FILE_READ);

                if(archivoSelfTest){
                    
                    while(archivoSelfTest.available()){

                        #ifdef DEBUG_SD              
                            USB_TX_SD.printf("Numero leido= %i", archivoSelfTest.parseInt());
                        #endif

                        if(archivoSelfTest.parseInt() == numeroAleatorioTest){
                            
                            archivoSelfTest.close();

                            SD.remove("echo.txt");

                            return (0);
                        }

                        else{

                            #ifdef DEBUG_SD              
                                USB_TX_SD.println(F("Fallo en lectura"));
                            #endif

                            //TODO --> Lo que leimos es diferente a lo que escribimos por eso hay un error
                            return (3);
                        }
                    }

                }

                else{

                    //TODO --> No se pudo abrir correctamente el archivo alerta
                    
                    #ifdef DEBUG_SD
                        USB_TX_SD.println(F("Fallo en archivoSelfTest"));
                    #endif
                    
                    return (3);

                }   

            }

        }

        return (3);

    }
    
    void saveTemperatura(float temperatura);

    void savePresion(float presion);

    void saveHumedad(float humedad);

    void saveVBateria(float tensionBateria);

    void saveVLDO(float tensionLDO);

    bool SD_CARD::tarjetaInsertadaEnSlot(){

        return (digitalRead(CARD_DS));
    }

    bool SD_CARD::dataProtect(){

        return (digitalRead(WRITE_PROTECT));
    }

#endif