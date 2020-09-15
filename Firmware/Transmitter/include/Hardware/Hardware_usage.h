#ifndef __Hardware_usage_H__
    
    #define __Hardware_usage_H__
    
    /* -------------------------------------------------------------------------- */
    /*                             Error Code Monitor                             */
    /* -------------------------------------------------------------------------- */
        #ifdef ERROR_MONITOR_DISABLED        
            #undef ERROR_MONITOR_ENABLED        
            #warning Al desactivar los leds del monitor los errores no serán expresados visualmente. En su defecto serán enviados por el puerto serie auxiliar del dispositivo.     
        #else
            #define ERROR_MONITOR_ENABLED
        #endif
    /* -------------------------------------------------------------------------- */

#endif