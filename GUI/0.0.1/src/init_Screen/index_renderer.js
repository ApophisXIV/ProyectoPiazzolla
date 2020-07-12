
//Evento al presionar la barra espaciadora (Evitar que el slider selector conmute sin generar ninguna acción)
window.onkeydown = function(teclaPresionada){

    //Si la tecla que se presiono es la barra espaciadora
    if(teclaPresionada.keyCode == 32) {

        //El evento se cancela y se evita que la barra accione el slider
        teclaPresionada.preventDefault();
    }
};

const botonStart_DARK_focus = document.createElement('style');
botonStart_DARK_focus.innerHTML = `

    #botonStart:focus {
        box-shadow: 0 0 0 0.2rem rgba(255, 0, 255, 0.25);
    }
`;

const botonStart_LIGHT_focus = document.createElement('style');
botonStart_LIGHT_focus.innerHTML = `

    #botonStart:focus {
        box-shadow: 0 0 0 0.2rem rgba(0, 123, 255, 0.25);
    }
`;

function Modo_Dark_Light(){

    var colorActual=document.body.style.backgroundColor;

    //Cambio de blanco a violeta
    if(colorActual!="rgb(51, 0, 102)"){

        document.body.style.backgroundColor="#330066";
        document.body.style.transition="0.4s";                
        document.getElementById("tituloPiazzollaCARD").style.color="#FFFFFF";
        document.getElementById("cuerpoPiazzollaCARD").style.color="#FFFFFF";
        document.getElementById("cardPiazzolla").style.backgroundColor="#5400AA";
        document.getElementById("cardPiazzolla").style.transition="0.4s";                
        document.getElementById("botonStart").style.backgroundColor="#7F00FF";
        document.getElementById("botonStart").style.borderColor="#7F00FF";
        document.getElementById("botonStart").style.transition="0.4s";    
        document.head.appendChild(botonStart_DARK_focus);       
        document.getElementById("LogoPIAZZOLLA").src="../../../resources/images/PiazzollaLogoDarkR.png";
    }

    //Cambio de violeta a blanco
    if(colorActual=="rgb(51, 0, 102)"){

        document.body.style.backgroundColor="#FFFFFF";
        document.body.style.transition="0.4s";
        document.getElementById("tituloPiazzollaCARD").style.color="#000000";
        document.getElementById("cuerpoPiazzollaCARD").style.color="#000000";       
        document.getElementById("cardPiazzolla").style.backgroundColor="#FFFFFF";         
        document.getElementById("cardPiazzolla").style.transition="0.4s";                
        document.getElementById("botonStart").style.backgroundColor="#007bff";                
        document.getElementById("botonStart").style.borderColor="#007bff";
        document.getElementById("botonStart").style.transition="0.4s"; 
        document.head.appendChild(botonStart_LIGHT_focus);
        document.getElementById("LogoPIAZZOLLA").src="../../../resources/images/PiazzollaLogoLightR.png";
    }


}