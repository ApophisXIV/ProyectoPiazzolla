import time
import sys
import serial

cont = 0

while True:
    print ("CONTADOR DE PRUEBA NUMERO PROYECTO PIAZZOLLA: ")
    print(str(cont))
    cont+=1
    sys.stdout.flush()
    time.sleep(1)