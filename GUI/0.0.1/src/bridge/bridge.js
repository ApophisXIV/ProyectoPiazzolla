
//Se importa el modulo Python Shell para operar con scripts de python desde javascript mediante node
var {PythonShell} = require('python-shell');

//Se genera un objeto que engloba y hereda los atributos y metodos de PythonShell
var mensajeDesdePython = new PythonShell('src/bridge/script/script_1.py',{scriptPath:"./", pythonOptions: ['-u']});


//Se define funcion para "tokenizar" los datos recibidos
function TOKEN_DATA(data_RECEPTION_tokens){

    //Declaracion de variable donde se almacenan los tokens generados del split
    var tokens_Data;

    //Se utiliza el ultimo caracter de dataRecibida para verificar la naturaleza del dato recibido
    switch (data_RECEPTION_tokens.substr(data_RECEPTION_tokens.length - 1)){
        
        //Si tiene el caracter identificatorio "t"
        case 't':

            //Se "tokeniza" los datos recibidos en base al caracter 't'
            tokens_Data = data_RECEPTION_tokens.split('t');
            
            //DEBUG
            //console.log("Tiene T");
            //console.log("TOKEN TEMP: ",tokens_Data[0]);

            //Se pasa al DOM el valor del token de temperatura
            document.getElementById("Temp_Elmt").innerHTML=tokens_Data[0]+" °C";

        break;

        //Si tiene el caracter identificatorio "p"
        case 'p':

            //Se "tokeniza" los datos recibidos en base al caracter 'p'
            tokens_Data = data_RECEPTION_tokens.split('p');

            //DEBUG
            //console.log("Tiene P");
            //console.log("TOKEN PRES: ",tokens_Data[0]);

            //Se pasa al DOM el valor del token de presion
            document.getElementById("Pres_Elmt").innerHTML=tokens_Data[0]+" hPa";

        break;

        //Si tiene el caracter identificatorio "h"
        case 'h':

            //Se "tokeniza" los datos recibidos en base al caracter 'h'
            tokens_Data = data_RECEPTION_tokens.split('h');

            //DEBUG
            //console.log("Tiene H");
            //console.log("TOKEN ALT: ",tokens_Data[0]);

            //Se pasa al DOM el valor del token de altitud
            document.getElementById("Alt_Elmt").innerHTML=tokens_Data[0]+" m";

        break;

        default:
            
            //Se indica en el DOM que no hay datos disponibles con los identificadores requeridos
            document.getElementById("Temp_Elmt").innerHTML="No tiene ninguno de los identificadores validos";
            document.getElementById("Pres_Elmt").innerHTML="No tiene ninguno de los identificadores validos";
            document.getElementById("Alt_Elmt").innerHTML="No tiene ninguno de los identificadores validos";

            //DEBUG
            //console.log("No tiene ninguno de los identificadores validos");
    }
}

//Evento de recepcion de algun mensaje por parte de Python a Node
mensajeDesdePython.on('message',function LINKER (data_LINKER) {
    
    //DEBUG
    //console.log(dataRecibida);

    TOKEN_DATA(data_LINKER);
 
});

//Funcion error. Handler del error en la Pyshell
mensajeDesdePython.end(function (err) {

    //Si termina el script, y efectivamente hay un error se devuelve el error
    if (err){
        
        //Devuelve el error arrojado si hubo error
        throw err;
    } 

    //Se indica si termino el script por consola
    console.log('EL SCRIPT TERMINO');
});
