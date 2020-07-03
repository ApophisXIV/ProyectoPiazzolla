
const {ipcRenderer} = require('electron');

document.getElementById("botonStart").addEventListener("click", function(){

    ipcRenderer.send("asynchronous-message","CAMBIAR_VENTANA_HOME");
    
});
