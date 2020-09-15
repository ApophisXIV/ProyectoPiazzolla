#ifndef __delayNB_CPP__

    #define __delayNB_CPP__

    #include <Hardware/Utilities/delayNB.h>

    void delayNoBloqueante (uint8_t tiempoDelay){

        volatile uint32_t tiempoViejo = HAL_GetTick();

        while (HAL_GetTick() - tiempoViejo < tiempoDelay);
    }

#endif