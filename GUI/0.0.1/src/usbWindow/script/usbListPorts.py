import sys
import serial as USB_PCB
import serial.tools.list_ports

def PORTS_SEAKER():
    
    puertosDisponibles=list(USB_PCB.tools.list_ports.comports())

    if (len(puertosDisponibles)==0):
        
        print("None")
        #print("No hay puertos disponibles")
    
    for i in puertosDisponibles:
        
        print(str(i).split(" -")[0])

def main():   

    print(PORTS_SEAKER())
    
if __name__ == "__main__":

    main()