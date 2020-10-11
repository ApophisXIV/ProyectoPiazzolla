#ifndef __Mem_SD_H__

    #define __Mem_SD_H__

    #include <hardware/Hardware_usage.h>

    #include <Hardware/GPIO.h>

    #include <SD.h>
    
    class SD_CARD{
        
        File archivoSelfTest;

        Sd2Card TarjetaSD;

        SdVolume volume;

        SdFile root;

        public:

        void setGPIO();

        uint8_t selfTest();

        void formatoArchivo(bool formato_CSV_JSON);

        void saveTemperatura(float temperatura);

        void savePresion(float presion);

        void saveHumedad(float humedad);

        void saveVBateria(float tensionBateria);

        void saveVLDO(float tensionLDO);

        private:

        bool tarjetaInsertadaEnSlot();

        bool dataProtect();
    };

#endif