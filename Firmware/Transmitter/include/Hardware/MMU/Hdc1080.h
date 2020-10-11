#ifndef __Hdc1080_H__

    #define __Hdc1080_H__
    
    #include <Hardware/Hardware_usage.h>

    #include <Hardware/Utilities/floatTo2Bytes.h>

    #include <HDC1080_DEV.h>

    class Higrometer{
        
        HDC1080_DEV HDC1080;    

        public:
        
        bool selfTest(uint16_t &valorTempComparar);

        uint16_t temperaturaMedicion();

        uint16_t humedadMedicion();
        

        private:

        float_t temperatura=0.0;
        



    };

#endif