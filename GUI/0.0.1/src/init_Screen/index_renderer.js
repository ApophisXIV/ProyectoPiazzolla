
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
    if(colorActual!="rgb(20, 15, 42)"){

        document.body.style.backgroundColor="#140F2A";
        document.body.style.transition="0.4s";                
        document.getElementById("tituloPiazzollaCARD").style.color="#FFFFFF";
        document.getElementById("subtituloPiazzollaCARD").style.color="#FFFFFF";
        document.getElementById("descripcionPiazzollaCARD").style.color="#FFFFFF";
        document.getElementById("divisionPiazzollaCARD").style.borderTopColor="#FFFFFF"; 
        document.getElementById("containerCARD").style.borderColor="#353251"; 
        document.getElementById("containerCARD").style.boxShadow="rgba(65, 56, 100, 0.5) 0px 0px 20px 1rem"; 

        document.getElementById("cardPiazzolla").style.backgroundColor="#212432";
        document.getElementById("cardPiazzolla").style.transition="0.4s";                
        document.getElementById("botonStart").style.backgroundColor="#454A5A";
        document.getElementById("botonStart").style.borderColor="#454A5A";
        document.getElementById("botonStart").style.transition="0.4s";    
        document.head.appendChild(botonStart_DARK_focus);       
        // document.getElementById("LogoPIAZZOLLA").src="../../../resources/images/PiazzollaLogoDarkR.png";
    }

    //Cambio de violeta a blanco
    if(colorActual=="rgb(20, 15, 42)"){

        document.body.style.backgroundColor="#FFFFFF";
        document.body.style.transition="0.4s";
        document.getElementById("tituloPiazzollaCARD").style.color="#212529";
        document.getElementById("subtituloPiazzollaCARD").style.color="#212529";
        document.getElementById("descripcionPiazzollaCARD").style.color="#212529";   
        document.getElementById("divisionPiazzollaCARD").style.borderTopColor="#D1D4D7"; 
        document.getElementById("containerCARD").style.borderColor="#FFFFFF"; 
        document.getElementById("containerCARD").style.boxShadow="rgba(29, 33, 36, 0.7) 0px 0px 20px 0rem"; 
        
        document.getElementById("cardPiazzolla").style.backgroundColor="#E9ECEF";         
        document.getElementById("cardPiazzolla").style.transition="0.4s";                
        document.getElementById("botonStart").style.backgroundColor="#007bff";                
        document.getElementById("botonStart").style.borderColor="#007bff";
        document.getElementById("botonStart").style.transition="0.4s"; 
        document.head.appendChild(botonStart_LIGHT_focus);
        // document.getElementById("LogoPIAZZOLLA").src="../../../resources/images/PiazzollaLogoLightR.png";
    }


}