#include <Hardware/Hardware.h>

//HardwareSerial Serial3(USART3);

int main (){

    Hardware_Tests PCB_Transmisor;

    PCB_Transmisor.prueba_1();

    // Error_Monitor Monitor;
    
    // USBSerial USB_TX;

    // USB_TX.begin(115200);
   
    // pinMode(PC13,1);

    // Monitor.setGPIO();

    // while (!USB_TX){   
    //     Monitor.BarridoUSB_Conectando();
    // }

    // if(USB_TX){
    //     digitalWrite(PC13,1);
    //     Monitor.BeepBeepAll(200);
    //     USB_TX.println(F("USB Conectado OK"));
    // }

    // FlashMicro.write(0,3);

    // USB_TX.println(F(FlashMicro.read(0)));


}