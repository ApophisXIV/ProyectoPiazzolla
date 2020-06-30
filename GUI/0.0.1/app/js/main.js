
const electron = require('electron');
const path = require('path');
const url = require('url');
const { request } = require('http');

// SET ENV
process.env.NODE_ENV = 'development';
process.env.ELECTRON_DISABLE_SECURITY_WARNINGS = '1';

const {app, BrowserWindow, Menu} = electron;

let homeWindow;

function VENTANA_HOME() {

  //Ventana principal
  homeWindow = new BrowserWindow({webPreferences:{nodeIntegration: true}, width: 640, height: 480, transparent: false, frame: true});
  
  //Debug, el path orignal era incorrecto.
  //console.log(path.join(__dirname, `../public/html/index.html`));

  homeWindow.loadURL(url.format({

    pathname: path.join(__dirname, `../public/html/index_1.html`),
    protocol: 'file',
    slashes: true
    
  }));

  homeWindow.maximize();
}

//Una vez este listo para mostrarse el contenido se llama a la funcion VENTANA_HOME para generarlas
app.on('ready', VENTANA_HOME);


//Codigo para cerrar el proceso correctamente en MAC
app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
      app.quit()
    }
})