#ifndef __Mem_Flash_CPP__

    #define __Mem_Flash_CPP__

    #include <Hardware/Storage/Mem_Flash.h>

    bool MEM_Flash::selfTest(){

        #ifdef DEBUG_FLASH
            USBSerial USB_TX_FLASH;
        #endif

        uint8_t numeroAleatorioTest = (rand() % BYTE_FULL);
        
        #ifdef DEBUG_FLASH
            USB_TX_FLASH.println(numeroAleatorioTest);
        #endif

        FlashMicro.write(0,numeroAleatorioTest);

        if(FlashMicro.read(0) == numeroAleatorioTest){

            #ifdef DEBUG_FLASH
                USB_TX_FLASH.println(F("Flash OK"));
            #endif

            return (0);
        }

        else{

            #ifdef DEBUG_FLASH
                USB_TX_FLASH.println(F("Fallo en lectura de Flash"));
            #endif

            return (1);
        }

    }

#endif