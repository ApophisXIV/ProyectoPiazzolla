
const electron = require('electron');
const path = require('path');
const url = require('url');

// SET ENV
process.env.NODE_ENV = 'development';
process.env.ELECTRON_DISABLE_SECURITY_WARNINGS = '1';

const {app, BrowserWindow, Menu, ipcMain} = electron;

let homeWindow=null;
let tempWindow=null;
let presWindow=null;
let humWindow=null;
let inertiaWindow=null;
let expansionWindow=null;
let commWindow=null;
let powerWindow=null;
let geoWindow=null;
let TITULOPENDIENTEWindow=null;
let configWindow=null;


function VENTANA_TEMPERATURA(){
  
  if (!tempWindow) {

    //Ventana principal
    tempWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    tempWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    tempWindow.on('close', ()=>{
    
      tempWindow = null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'TEMP_CLOSE');
    });

  }

}

function VENTANA_PRESION(){
  
  if (!presWindow) {

    //Ventana principal
    presWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    presWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    presWindow.on('close', ()=>{
    
      presWindow = null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'PRES_CLOSE');
    });

  }

}
    
function VENTANA_HUMEDAD(){
  
  if (!humWindow) {

    //Ventana principal
    humWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    humWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    humWindow.on('close', ()=>{
    
      humWindow = null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'HUM_CLOSE');
    });

  }

}
  
function VENTANA_INERCIA(){
  
  if (!inertiaWindow) {

    //Ventana principal
    inertiaWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    inertiaWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    inertiaWindow.on('close', ()=>{
    
      inertiaWindow = null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'INER_CLOSE');
    });

  }

}
   
function VENTANA_PUERTO_EXPANSION(){
  
  if (!expansionWindow) {

    //Ventana principal
    expansionWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    expansionWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    expansionWindow.on('close', ()=>{
    
      expansionWindow = null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'EX_PORT_CLOSE');
    });

  }

}

function VENTANA_COMM(){
  
  if (!commWindow) {

    //Ventana principal
    commWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    commWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    commWindow.on('close', ()=>{
    
      commWindow = null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'COMM_CLOSE');
    });

  }

}

function VENTANA_POWER(){
  
  if (!powerWindow) {

    //Ventana principal
    powerWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    powerWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    powerWindow.on('close', ()=>{
    
      powerWindow = null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'POWER_CLOSE');
    });

  }

}
 
function VENTANA_GEO(){
  
  if (!geoWindow) {

    //Ventana principal
    geoWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    geoWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    geoWindow.on('close', ()=>{
    
      geoWindow= null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'GEO_CLOSE');
    });

  }

}

function VENTANA_TITULOPENDIENTE(){
  
  if (!TITULOPENDIENTEWindow) {

    //Ventana principal
    TITULOPENDIENTEWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    TITULOPENDIENTEWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    TITULOPENDIENTEWindow.on('close', ()=>{
    
      TITULOPENDIENTEWindow = null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'TPEND_CLOSE');
    });

  }

}

function VENTANA_CONFIG(){
  
  if (!configWindow) {

    //Ventana principal
    configWindow = new BrowserWindow({
    
      webPreferences:{nodeIntegration: true}, 
      
      width: 640,

      height: 480,

      minWidth: 640, 
      
      minHeight: 480,

      icon: path.join(__dirname, '../../resources/icons/boya.png')

    });
    
    //Se carga el archivo html de la ventana
    configWindow.loadURL(url.format({

      pathname: path.join(__dirname, `../public/html/tempWindow.html`),
      protocol: 'file',
      slashes: true
      
    }));
    
    // Proceso de reset cuando se cierra
    configWindow.on('close', ()=>{
    
      configWindow = null;
      homeWindow.webContents.send('ventana_gridSCREEN', 'CONFIG_CLOSE');
    });

  }

}

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
  
  // Al cerrarse la ventana home se cierran todas las ventantas abiertas por la aplicacion
  homeWindow.on('close', ()=>{
    
    let arrayVentanas = [];

    arrayVentanas.push(tempWindow,presWindow,humWindow,inertiaWindow,expansionWindow,commWindow,powerWindow,geoWindow,TITULOPENDIENTEWindow,configWindow);
    
    // tempWindow => 0
    // presWindow => 1
    // humWindow => 2
    // inertiaWindow => 3
    // expansionWindow => 4 
    // commWindow => 5
    // powerWindow => 6
    // geoWindow => 7
    // TITULOPENDIENTEWindow => 8
    // configWindow => 9

    //DEBUG --> Cantidad de ventanas abiertas
    //console.log(arrayVentanas.filter(i => i != null).length);
    
    for (let i = 0; i < arrayVentanas.filter(i => i != null).length; i++) {
      
      console.log(arrayVentanas.indexOf(arrayVentanas.filter(i => i != null)[i]));

      switch (arrayVentanas.indexOf(arrayVentanas.filter(i => i != null)[i])) {
        
        case 0:
          tempWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("temp destroy");
        break;

        case 1:
          presWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("pres destroy");
        break;

        case 2:
          humWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("hum destroy");
        break;

        case 3:
          inertiaWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("inert destroy");
        break;

        case 4:
          expansionWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("expan destroy");
        break;

        case 5:
          commWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("comm destroy");
        break;

        case 6:
          powerWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("power destroy");
        break;

        case 7:
          geoWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("geo destroy");
        break;

        case 8:
          TITULOPENDIENTEWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("TITULO destroy");
        break;

        case 9:
          configWindow.destroy();
          //DEBUG --> Destroy por ventana
          //console.log("config destroy");
        break;
      
        default:
          console.log("Error al cerrar las ventanas (SWITCH_KEY_ERROR)");
        break;
      }

    }

  });

  let colorBool = false;

  //Canal de comunicación asincrono del proceso renderer de la ventana Index
  ipcMain.on("ventana_INDEX",(evento_Index,mensajeCLOSE)=>{

    //Si el mensaje se corresponde con el mensaje esperado 
    //("CAMBIAR_VENTANA_HOME_MODO_OSCURO") entonces se cambia el archivo html de la ventana.
    //Luego se le indica al proceso renderer de gridScreen que debe cambiar 
    //el esquema de colores del modo oscuro.

    if(mensajeCLOSE == "CAMBIAR_VENTANA_HOME_MODO_OSCURO"){
      
      //DEBUG
      //console.log(mensajeCLOSE);

      //Se carga el archivo correspondiente a la nueva ventana luego de pulsar el boton START
      homeWindow.loadURL(url.format({

        pathname: path.join(__dirname, `../public/html/gridScreen.html`),
        protocol: 'file',
        slashes: true
        
      })); 
      
      colorBool = true;

    }

    //Si el mensaje se corresponde con el mensaje esperado
    //("CAMBIAR_VENTANA_HOME_MODO_CLARO") entonces se cambia el archivo html de la ventana.
    //Luego se le indica al proceso renderer de gridScreen que debe cambiar 
    //el esquema de colores del modo claro.

    else{

      //DEBUG
      //console.log(mensajeCLOSE);
      
      //Se carga el archivo correspondiente a la nueva ventana luego de pulsar el boton START
      homeWindow.loadURL(url.format({

        pathname: path.join(__dirname, `../public/html/gridScreen.html`),
        protocol: 'file',
        slashes: true
        
      }));         

    }

  });

  //Canal de comunicación asincrono del proceso renderer de la ventana gridScreen
  ipcMain.on("ventana_gridSCREEN",(evento_gridSCREEN,mensajeVENTANAS_PARAMETROS)=>{

    

    switch (mensajeVENTANAS_PARAMETROS) {
      
      case "colorQuery":
        
        evento_gridSCREEN.reply("ventana_gridSCREEN",colorBool);
        
      break;

      case "ABRIR_VENTANA_TEMPERATURA":
        
        evento_gridSCREEN.reply("ventana_gridSCREEN","TEMP_OPEN");
        
        VENTANA_TEMPERATURA();

      break;
          
      case "ABRIR_VENTANA_PRESION":
        
        evento_gridSCREEN.reply("ventana_gridSCREEN","PRES_OPEN");

        VENTANA_PRESION();

      break;   

      case "ABRIR_VENTANA_HUMEDAD":
        
        evento_gridSCREEN.reply("ventana_gridSCREEN","HUM_OPEN");

        VENTANA_HUMEDAD();

      break;  

      case "ABRIR_VENTANA_INERCIA":
      
        evento_gridSCREEN.reply("ventana_gridSCREEN","INER_OPEN");

        VENTANA_INERCIA();

      break;  

      case "ABRIR_VENTANA_EXPANSION_PORT":
      
        evento_gridSCREEN.reply("ventana_gridSCREEN","EX_PORT_OPEN");

        VENTANA_PUERTO_EXPANSION();

      break; 

      case "ABRIR_VENTANA_COMM":

        evento_gridSCREEN.reply("ventana_gridSCREEN","COMM_OPEN");

        VENTANA_COMM();

      break; 

      case "ABRIR_VENTANA_POWER":
      
        evento_gridSCREEN.reply("ventana_gridSCREEN","POWER_OPEN");

        VENTANA_POWER();

      break;  

      case "ABRIR_VENTANA_GEO":
      
        evento_gridSCREEN.reply("ventana_gridSCREEN","GEO_OPEN");

        VENTANA_GEO();

      break; 

      case "ABRIR_VENTANA_TITULOPENDIENTE":
      
        evento_gridSCREEN.reply("ventana_gridSCREEN","TPEND_OPEN");

        VENTANA_TITULOPENDIENTE();

      break; 

      case "ABRIR_VENTANA_CONFIG":
      
        evento_gridSCREEN.reply("ventana_gridSCREEN","CONFIG_OPEN");

        VENTANA_CONFIG();

      break;
      
      default:
        console.log(mensajeVENTANAS_PARAMETROS);
        console.log("Se recibio una solicitud de apertura de ventana inesperada");

      break;
    }

  });

}

//Una vez este listo para mostrarse el contenido se llama a la funcion VENTANA_HOME para generarlas
app.whenReady().then(VENTANA_HOME);

//Codigo para cerrar el proceso correctamente en MAC
app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
      app.quit()
    }
})