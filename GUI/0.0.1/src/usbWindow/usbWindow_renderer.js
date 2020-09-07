const {ipcRenderer} = require('electron');

//Se importa el modulo Python Shell para operar con scripts de python desde javascript mediante node
let {PythonShell} = require('python-shell');

//Se genera un objeto que engloba y hereda los atributos y metodos de PythonShell
let commPythonBridge_LIST_PORTS = new PythonShell('src/usbWindow/script/usbListPorts.py',{scriptPath:"./", pythonOptions: ['-u']});

//Se define funcion para mostrar los puertos disponibles mediante un menu desplegable
function PORT_LIST_a_DOM(ports_DISPONIBLES) {

    let elementoPuertoNuevo=document.createElement("option");

    elementoPuertoNuevo.setAttribute("value",ports_DISPONIBLES);

    elementoPuertoNuevo.appendChild(document.createTextNode(ports_DISPONIBLES));

    document.getElementById("elementoRootPORTS").parentNode.insertBefore(elementoPuertoNuevo, document.getElementById("elementoRootPORTS"));
    
}

//Evento de recepcion de algun mensaje por parte de Python a Node (Instancia 1)
commPythonBridge_LIST_PORTS.on('message',function LINKER (data_LINKER) {
    
    //DEBUG
    console.log(data_LINKER);

    if(data_LINKER != "None"){

        PORT_LIST_a_DOM(data_LINKER);

    }

});

//Funcion error. Handler del error en la Pyshell o fin de ejecucion del script
commPythonBridge_LIST_PORTS.end(function (err) {

    //Si termina el script, y efectivamente hay un error se devuelve el error
    if (err){
        
        //Devuelve el error arrojado si hubo error
        throw err;
    } 

    //Se indica si termino el script por consola
    console.log('EL SCRIPT TERMINO');

});


let puertoSeleccionado=["PUERTO","BAUDS","ON_OFF"];

document.getElementById("listaPuertos").addEventListener("change", () => {

    puertoSeleccionado[0]=document.getElementById("listaPuertos").selectedOptions[0].value;

    //DEBUG -> Nombre del puerto
    //console.log(puertoSeleccionado);

    document.getElementById("listaBauds").removeAttribute("disabled");
});

document.getElementById("listaBauds").addEventListener("change", () => {

    puertoSeleccionado[1]=document.getElementById("listaBauds").selectedOptions[0].value;

    //DEBUG -> Nombre del puerto
    //console.log(puertoSeleccionado);

    document.getElementById("boton_ConectarDesconectar").removeAttribute("disabled");
});

document.getElementById("boton_ConectarDesconectar").addEventListener("click", function(){  

    if(document.getElementById("boton_ConectarDesconectar").innerHTML == "Connect"){

        document.getElementById("boton_ConectarDesconectar").setAttribute("class","btn btn-danger");
        
        document.getElementById("boton_ConectarDesconectar").innerHTML = "Disconnect";

        document.getElementById("listaPuertos").setAttribute("disabled","");
        
        document.getElementById("listaBauds").setAttribute("disabled","");

        puertoSeleccionado[2]="CONECTAR";
    
        document.getElementById("elementoRootPORTS").removeAttribute("selected");
        
        document.getElementById("elementoRootBAUD").removeAttribute("selected");
       
        ipcRenderer.send("ventana_usbWINDOW",puertoSeleccionado);

    }

    else{

        document.getElementById("boton_ConectarDesconectar").setAttribute("class","btn btn-success");
       
        document.getElementById("boton_ConectarDesconectar").innerHTML = "Connect";

        puertoSeleccionado[2]="DESCONECTAR";

        document.getElementById("listaPuertos").removeAttribute("disabled");
        
        document.getElementById("listaBauds").setAttribute("disabled","");

        document.getElementById("boton_ConectarDesconectar").setAttribute("disabled","");
        
        document.getElementById("elementoRootPORTS").setAttribute("selected","");
        
        document.getElementById("elementoRootBAUD").setAttribute("selected","");

        ipcRenderer.send("ventana_usbWINDOW",puertoSeleccionado);

    }

});