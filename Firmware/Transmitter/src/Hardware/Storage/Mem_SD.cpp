#ifndef __Mem_SD_CPP__
    
    #define __Mem_SD_CPP__

    #include <Hardware/Storage/Mem_SD.h>

    void SetGPIO();

    bool selfTest();

    void formatoArchivo(bool formato_CSV_JSON);

    void saveTemperatura(float temperatura);

    void savePresion(float presion);

    void saveHumedad(float humedad);

    void saveVBateria(float tensionBateria);

    void saveVLDO(float tensionLDO);

#endif