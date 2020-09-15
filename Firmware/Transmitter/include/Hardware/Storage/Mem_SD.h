#ifndef __Mem_SD_H__

    #define __Mem_SD_H__
    
    #include <SD.h>

    class SD_CARD{

        public:

        void SetGPIO();

        bool selfTest();

        void formatoArchivo(bool formato_CSV_JSON);

        void saveTemperatura(float temperatura);

        void savePresion(float presion);

        void saveHumedad(float humedad);

        void saveVBateria(float tensionBateria);

        void saveVLDO(float tensionLDO);
        
    };

#endif