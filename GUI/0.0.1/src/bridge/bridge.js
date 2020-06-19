//Se importa el modulo Python Shell para operar con scripts de python desde javascript mediante node
var {PythonShell} = require('python-shell');

//Se genera un objeto que engloba y hereda los atributos y metodos de PythonShell
var mensajeDesdePython = new PythonShell('src/bridge/script/script_1.py',{scriptPath:"./", pythonOptions: ['-u']});

//Evento de recepcion de algun mensaje por parte de Python a Node
mensajeDesdePython.on('message', function (dataRecibida) {

    //LOG en la consola de los datos recibidos 
    console.log(dataRecibida);

});

mensajeDesdePython.end(function (err) {

    //Si termina el script, y efectivamente hay un error se devuelve el error
    if (err){
        
        //Devuelve el error arrojado si hubo error
        throw err;
    } 

    //Se indica si termino el script por consola
    console.log('EL SCRIPT TERMINO');
});