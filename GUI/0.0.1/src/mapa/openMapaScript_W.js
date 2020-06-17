const BrowserWindow = require('electron').remote.BrowserWindow;
const path = require('path')
const url = require('url')

//Declaracion global (Recomendado por la documentacion)
let mapaWindow;

function VENTANA_MAPA() {

    //Ventana principal
    mapaWindow = new BrowserWindow({webPreferences:{webSecurity: false},width: 700, height: 500});
          
    //Debug del path .
    //console.log(path.join(__dirname, `../../public/html/mapWindow.html`));
  
    mapaWindow.loadURL(url.format({
  
      pathname: path.join(__dirname, `../../public/html/mapWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
  
    // Proceso de reset cuando se cierra
    mapaWindow.on('close', function(){
    mapaWindow = null;
    });
}

function TEST(){

    if(!mapaWindow){

        document.getElementById("TEXT").innerHTML="BOTON CLICKEADO";
        VENTANA_MAPA();
    }
}

/*************************************************************/