
const {ipcRenderer} = require('electron');

function colorSwitch(nombre,color,propiedad) {
    
    var i = document.getElementsByClassName(nombre).length;
    
    if(propiedad){

        while (i--) {

            document.getElementsByClassName(nombre)[i].style.backgroundColor=color;
        }
    }

    else{ 

        while (i--) {

            document.getElementsByClassName(nombre)[i].style.color=color;
        }
    }

}

ipcRenderer.send("ventana_gridSCREEN","colorQuery");

ipcRenderer.on('ventana_gridSCREEN', (event, cardsPropiedades) => {

    switch (cardsPropiedades) {
        
        case true:
            
            document.body.style.backgroundColor="#140F2A";
    
            colorSwitch("card-body","#212432",1);
            colorSwitch("card-title","#FFFFFF",0);
            colorSwitch("card-text","#FFFFFF",0);

            document.getElementById("tempCARD").style.boxShadow="var(--orange) 0px 0px 16px 0rem";
            document.getElementById("presCARD").style.boxShadow="var(--yellow) 0px 0px 16px 0rem";
            document.getElementById("humCARD").style.boxShadow="var(--green) 0px 0px 16px 0rem";
            document.getElementById("inertiaCARD").style.boxShadow="var(--blue) 0px 0px 16px 0rem";
            document.getElementById("expansionCARD").style.boxShadow="var(--pink) 0px 0px 16px 0rem";
            document.getElementById("commCARD").style.boxShadow="var(--pink) 0px 0px 16px 0rem";
            document.getElementById("powerCARD").style.boxShadow="var(--blue) 0px 0px 16px 0rem";
            document.getElementById("geoCARD").style.boxShadow="var(--green) 0px 0px 16px 0rem";
            document.getElementById("pendienteCARD").style.boxShadow="var(--yellow) 0px 0px 16px 0rem";
            document.getElementById("configCARD").style.boxShadow="var(--orange) 0px 0px 16px 0rem";
        
        break;
            
        case false:

            document.body.style.backgroundColor="#FFFFFF";

            colorSwitch("card-body","#FFFFFF",1);
            colorSwitch("card-title","#212529",0);
            colorSwitch("card-text","#212529",0);

            document.getElementById("tempCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
            document.getElementById("presCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
            document.getElementById("humCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
            document.getElementById("inertiaCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
            document.getElementById("expansionCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
            document.getElementById("commCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
            document.getElementById("powerCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
            document.getElementById("geoCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
            document.getElementById("pendienteCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
            document.getElementById("configCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";

        break;

        case "TEMP_OPEN":
            
            document.getElementById("StartTemperature").setAttribute("disabled","");

        break;
        
        case "TEMP_CLOSE":
            
            document.getElementById("StartTemperature").removeAttribute("disabled");

        break;

        case "PRES_OPEN":

            document.getElementById("StartPreasure").setAttribute("disabled","");

        break;
        
        case "PRES_CLOSE":

           document.getElementById("StartPreasure").removeAttribute("disabled"); 

        break;
        
        case "HUM_OPEN":

            document.getElementById("StartHumidity").setAttribute("disabled","");

        break;
        
        case "HUM_CLOSE":

            document.getElementById("StartHumidity").removeAttribute("disabled");

        break;

        case "INER_OPEN":

            document.getElementById("StartInertia").setAttribute("disabled","");

        break;
        
        case "INER_CLOSE":

            document.getElementById("StartInertia").removeAttribute("disabled");

        break;

        case "EX_PORT_OPEN":

            document.getElementById("StartExpansionPort").setAttribute("disabled","");    

        break;
        
        case "EX_PORT_CLOSE":

            document.getElementById("StartExpansionPort").removeAttribute("disabled");    

        break;

        case "COMM_OPEN":

            document.getElementById("StartCommunications").setAttribute("disabled","");

        break;
        
        case "COMM_CLOSE":

            document.getElementById("StartCommunications").removeAttribute("disabled");
        
        break;

        case "POWER_OPEN":

            document.getElementById("StartPower").setAttribute("disabled","");

        break;
        
        case "POWER_CLOSE":

            document.getElementById("StartPower").removeAttribute("disabled");
        
        break;

        case "GEO_OPEN":

            document.getElementById("StartGeolocation").setAttribute("disabled","");

        break;

        case "GEO_CLOSE":

            document.getElementById("StartGeolocation").removeAttribute("disabled");

        break;
        
        case "TPEND_OPEN":

            document.getElementById("StartTITULOPENDIENTE").setAttribute("disabled","");

        break;
        
        case "TPEND_CLOSE":

            document.getElementById("StartTITULOPENDIENTE").removeAttribute("disabled");
        
        break;

        case "CONFIG_OPEN":

            document.getElementById("StartConfiguration").setAttribute("disabled","");

        break;
        
        case "CONFIG_CLOSE":

            document.getElementById("StartConfiguration").removeAttribute("disabled");
        
        break;

        default:

            console.log("Se recibio un mensaje inesperado (gridScreen)");

        break;
    }
    if(colorCards=="MODO_OSCURO"){

        document.body.style.backgroundColor="#140F2A";

        colorSwitch("card-body","#212432",1);
        colorSwitch("card-title","#FFFFFF",0);
        colorSwitch("card-text","#FFFFFF",0);

        document.getElementById("tempCARD").style.boxShadow="var(--orange) 0px 0px 16px 0rem";
        document.getElementById("presCARD").style.boxShadow="var(--yellow) 0px 0px 16px 0rem";
        document.getElementById("humCARD").style.boxShadow="var(--green) 0px 0px 16px 0rem";
        document.getElementById("inertiaCARD").style.boxShadow="var(--blue) 0px 0px 16px 0rem";
        document.getElementById("expansionCARD").style.boxShadow="var(--pink) 0px 0px 16px 0rem";
        document.getElementById("commCARD").style.boxShadow="var(--pink) 0px 0px 16px 0rem";
        document.getElementById("powerCARD").style.boxShadow="var(--blue) 0px 0px 16px 0rem";
        document.getElementById("geoCARD").style.boxShadow="var(--green) 0px 0px 16px 0rem";
        document.getElementById("pendienteCARD").style.boxShadow="var(--yellow) 0px 0px 16px 0rem";
        document.getElementById("configCARD").style.boxShadow="var(--orange) 0px 0px 16px 0rem";
    }

    else{

        document.body.style.backgroundColor="#FFFFFF";

        colorSwitch("card-body","#FFFFFF",1);
        colorSwitch("card-title","#212529",0);
        colorSwitch("card-text","#212529",0);

        document.getElementById("tempCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
        document.getElementById("presCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
        document.getElementById("humCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
        document.getElementById("inertiaCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
        document.getElementById("expansionCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
        document.getElementById("commCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
        document.getElementById("powerCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
        document.getElementById("geoCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
        document.getElementById("pendienteCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
        document.getElementById("configCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 16px 0rem";
    }
    
});

//Listener boton start
document.getElementById("StartTemperature").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_TEMPERATURA");
});


document.getElementById("StartPreasure").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_PRESION");
});


document.getElementById("StartHumidity").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_HUMEDAD");
});


document.getElementById("StartInertia").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_INERCIA");
});


document.getElementById("StartExpansionPort").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_EXPANSION_PORT");
});


document.getElementById("StartCommunications").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_COMM");
});


document.getElementById("StartPower").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_POWER");
});


document.getElementById("StartGeolocation").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_GEO");
});


document.getElementById("StartTITULOPENDIENTE").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_TITULOPENDIENTE");
});


document.getElementById("StartConfiguration").addEventListener("click", function(){
    
    ipcRenderer.send("ventana_gridSCREEN","ABRIR_VENTANA_CONFIG");
});
