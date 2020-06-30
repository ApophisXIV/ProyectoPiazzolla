function Modo_Dark_Light(){

    var colorActual=document.body.style.backgroundColor;

    //Cambio de blanco a violeta
    if(colorActual!="rgb(51, 0, 102)"){

        document.body.style.backgroundColor="#330066";
        document.body.style.transition="0.4s";                
        document.getElementById("tituloPiazzollaCARD").style.color="#FFFFFF";
        document.getElementById("cuerpoPiazzollaCARD").style.color="#FFFFFF";
        document.getElementById("botonStart").style.backgroundColor="#7F00FF";
        document.getElementById("botonStart").style.borderColor="#7F00FF";
    }

    //Cambio de violeta a blanco
    if(colorActual=="rgb(51, 0, 102)"){

        document.body.style.backgroundColor="#FFFFFF";
        document.body.style.transition="0.4s";
        document.getElementById("tituloPiazzollaCARD").style.color="#000000";
        document.getElementById("cuerpoPiazzollaCARD").style.color="#000000";                
        document.getElementById("botonStart").style.backgroundColor="#007bff";                
        document.getElementById("botonStart").style.borderColor="#007bff";
    }

}