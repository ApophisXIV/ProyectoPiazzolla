
const electron = require('electron');
const path = require('path');
const url = require('url');

// SET ENV
process.env.NODE_ENV = 'development';
process.env.ELECTRON_DISABLE_SECURITY_WARNINGS = '1';

const {app, BrowserWindow, Menu, ipcMain} = electron;

let homeWindow;

function VENTANA_HOME() {

  //Ventana principal
  homeWindow = new BrowserWindow({
  
    webPreferences:{nodeIntegration: true}, 
    
    width: 640,

    height: 480,

    minWidth: 640, 
    
    minHeight: 480, 
    
    icon: path.join(__dirname, '../../resources/icons/boya.png')

  });

  
  //Se carga el archivo html de la ventana
  homeWindow.loadURL(url.format({

    pathname: path.join(__dirname, `../public/html/index.html`),
    protocol: 'file',
    slashes: true
    
  }));

  //Se maximiza la ventana
  homeWindow.maximize();

  //Se recibe un mensaje asincrono desde el proceso renderer
  ipcMain.on("asynchronous-message",(eventoRENDER,mensajeCLOSE)=>{

    //Si el mensaje se corresponde con el mensaje esperado entonces se cambia el archivo html de la ventana 
    if(mensajeCLOSE=="CAMBIAR_VENTANA_HOME"){

      //DEBUG
      //console.log(mensajeCLOSE);

      //Se carga el archivo correspondiente a la nueva ventana luego de pulsar el boton START
      homeWindow.loadURL(url.format({

        pathname: path.join(__dirname, `../public/html/gridScreen.html`),
        protocol: 'file',
        slashes: true
        
      }));

    }

  })

}

//Una vez este listo para mostrarse el contenido se llama a la funcion VENTANA_HOME para generarlas
app.whenReady().then(VENTANA_HOME);

//Codigo para cerrar el proceso correctamente en MAC
app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
      app.quit()
    }
})