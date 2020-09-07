import sys
import serial as USB_PCB
import serial.tools.list_ports

# /************************************************/
# /*  Definiciones -->    Temperatura BMP |   v   */
# /*                      Presion BMP     |   q   */
# /*                      Altitud         |   a   */
# /*                      Temperatura HDC |   h   */
# /*                      Humedad HDC     |   f   */
# /*                      VLDO            |   k   */
# /*                      Acimut          |   z   */
# /************************************************/
# /*              Futura Implementacion           */
# /************************************************/
# /*                      Eje X QMC       |   c   */
# /*                      Eje Y QMC       |   b   */
# /*                      Eje Z QMC       |   n   */
# /************************************************/

def DATA_CLEANER(dataToClean):

    dataToClean = dataToClean.replace("b'",'')
    
    dataToClean = dataToClean.replace("\\r\\n'",'')

    return(dataToClean)

def main():

    if(sys.argv[3] == "CONECTAR"):
       
        USB_port = USB_PCB.Serial(sys.argv[1],sys.argv[2])
        
        # DEBUG
        # USB_port = USB_PCB.Serial('COM3',9600)

        while (1):

            print(DATA_CLEANER(str(USB_port.readline())))

    else:
        
        USB_port.close()

        print("EL PUERTO DEBE CERRAR")


if __name__ == "__main__":

    main()