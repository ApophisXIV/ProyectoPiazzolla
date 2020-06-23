import time
import sys
import serial as USB_PCB
import serial.tools.list_ports
import random

cont = 0

#***********************#
#  Variables simuladas  #
#***********************#
var_Temp    = str(round(random.uniform(-40, 37),2)) #Variacion entre -40 y 37 °C

var_Pres    = str(round(random.uniform(300, 1030),2)) #Variacion entre 300 y 1030 hPa

var_Alt     = str(round(random.uniform(0, 10000),2)) #Variacion entre 0 y 10 km
#***********************#

def PORTS_SEAKER():
    
    puertosDisponibles=list(USB_PCB.tools.list_ports.comports())

    if (len(puertosDisponibles)==0):
        print("No hay puertos disponibles")

    for i in puertosDisponibles:
        print(i)


while (1):
    
    print(var_Temp+'t')
    print(var_Pres+'p')
    print(var_Alt+'h')

    var_Temp = str(round(random.uniform(-40, 37),2)) #Variacion entre -40 y 37 °C
    var_Pres = str(round(random.uniform(300, 1030),2)) #Variacion entre 300 y 1030 hPa
    var_Alt = str(round(random.uniform(0, 10000),2)) #Variacion entre 0 y 10 km

    sys.stdout.flush()
    time.sleep(0.1)