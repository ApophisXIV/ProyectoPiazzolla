
const {app, BrowserWindow, dialog} = require('electron')

function VENTANA () {

    window = new BrowserWindow({width: 1000, height: 800})
    window.loadFile('index.html')
    

    let {PythonShell} = require('python-shell')
 
    PythonShell.run('public/script/script_1.py', null, function  (err, results)  {
        if  (err)  throw err;
        console.log('script_1.py termino.');
        console.log('lo que devuelve python:', results);
    });   	
        
    // const response = dialog.showMessageBox(null);
    // console.log(response);
            
}

app.on('ready', VENTANA)

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
      app.quit()
    }
})