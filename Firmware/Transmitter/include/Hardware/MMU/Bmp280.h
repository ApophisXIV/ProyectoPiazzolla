#ifndef __Bmp280_H__

    #define __Bmp280_H__
    
    #include <Hardware/Hardware_usage.h>

    #include <Hardware/Utilities/floatTo2Bytes.h>

    #include <BMP280_DEV.h>

    class Barometer {

        BMP280_DEV BMP280;
        
        public:

        bool selfTest();

        uint16_t temperaturaMedicion();

        uint16_t presionMedicion();

        private:

        float_t temperatura=0.0;
        
        float_t presion=0.0;

    };

#endif