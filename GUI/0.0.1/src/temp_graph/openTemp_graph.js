
//Declaracion global (Recomendado por la documentacion)
let tempWindow;

function VENTANA_TEMP_GRAPH() {

    //Ventana principal
    tempWindow = new BrowserWindow({webPreferences:{webSecurity: false},width: 700, height: 500});
          
    //Debug del path .
    //console.log(path.join(__dirname, `../../public/html/temp_graph.html`));
  
    tempWindow.loadURL(url.format({
  
      pathname: path.join(__dirname, `../../public/html/temp_graph.html`),
      protocol: 'file',
      slashes: true
      
    }));
  
    // Proceso de reset cuando se cierra
    tempWindow.on('close', function(){
    tempWindow = null;
    document.getElementById("Flag_TEMP_CHART").innerHTML="Gráfico de temperatura cerrado";
    });
}

function Abrir_TempChart(){

    if(!tempWindow){

        document.getElementById("Flag_TEMP_CHART").innerHTML="Gráfico de temperatura abierto";
        VENTANA_TEMP_GRAPH();
    }
}

/*************************************************************/