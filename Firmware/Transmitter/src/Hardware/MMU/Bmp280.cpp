#ifndef __Bmp280_CPP__

    #define __Bmp280_CPP__

    #include <Hardware/MMU/Bmp280.h>

    bool Barometer::selfTest(){

        return(!BMP280.begin(BMP280_I2C_ALT_ADDR)); //Modo Sleep luego de inicializar 

    }

    uint16_t Barometer::temperaturaMedicion(){

        BMP280.startForcedConversion();

        //TODO --> Validacion en caso de que devuelva un 0. La medicion no esta lista -> 0 La medicion esta lista y fue devuelto el valor medido -> 1. Podria meterse un while hasta que termine la conversion. Podria hacerse por polling. Ver si se puede calcular el costo de energia el hecho de esperar que termine la conversion.
        BMP280.getTemperature(temperatura);

        return(conversionAndRedondeo(temperatura));

    }

    uint16_t Barometer::presionMedicion(){
        
        BMP280.startForcedConversion();

        //TODO --> Validacion en caso de que devuelva un 0. La medicion no esta lista -> 0 La medicion esta lista y fue devuelto el valor medido -> 1. Podria meterse un while hasta que termine la conversion. Podria hacerse por polling. Ver si se puede calcular el costo de energia el hecho de esperar que termine la conversion.
        BMP280.getPressure(presion);

        return(conversionAndRedondeo(presion));

    }

#endif