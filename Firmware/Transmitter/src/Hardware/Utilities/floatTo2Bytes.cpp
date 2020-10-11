#ifndef __floatTo2Bytes_CPP__

    #define __floatTo2Bytes_CPP__

    #include <Hardware/Utilities/floatTo2Bytes.h>

    uint16_t conversionAndRedondeo(float_t &conversionFloatTo2Bytes){

        return((uint16_t)roundf(conversionFloatTo2Bytes*100));
        
    }

#endif