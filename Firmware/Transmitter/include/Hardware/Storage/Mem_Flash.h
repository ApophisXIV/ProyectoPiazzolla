#ifndef __Mem_Flash_H__

    #define __Mem_Flash_H__

    #include <Hardware/Hardware_usage.h>

    #include <EEPROM.h>

    class MEM_Flash{

        public:
        
        // void pruebaCumplida(uint32_t address, uint32_t size, volatile);

        bool selfTest();

    };

#endif