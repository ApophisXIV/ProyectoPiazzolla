import time
import sys
import serial as USB_PCB
import serial.tools.list_ports

cont = 0

while True:
    
    print ("CONTADOR DE PRUEBA NUMERO PROYECTO PIAZZOLLA: ")
    print(str(cont))

    puertosDisponibles=list(USB_PCB.tools.list_ports.comports())

    print("Prueba de puerto", puertosDisponibles[0])

    for i in puertosDisponibles:
        print(i)

    cont+=1
    sys.stdout.flush()
    time.sleep(1)