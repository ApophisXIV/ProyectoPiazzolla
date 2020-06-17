
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
  homeWindow = new BrowserWindow({webPreferences:{nodeIntegration: true},width: 720, height: 600});
  
  //Debug, el path orignal era incorrecto.
  //console.log(path.join(__dirname, `../public/html/index.html`));

  homeWindow.loadURL(url.format({

    pathname: path.join(__dirname, `../public/html/index.html`),
    protocol: 'file',
    slashes: true
    
  }))

  let {PythonShell} = require('python-shell')

  PythonShell.run('src/bridge/script/script_1.py', null, function  (err, results)  {
      if  (err)  throw err;
      console.log('script_1.py termino.');
      console.log('lo que devuelve python:', results);
  });
}

//Una vez este listo para mostrarse el contenido se llama a la funcion VENTANAS para generarlas
app.on('ready', VENTANA_HOME);


//Codigo para cerrar el proceso correctamente en MAC
app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
      app.quit()
    }
})