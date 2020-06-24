
//Se crea el objeto map 
const map = L.map('map').setView([-34.616730, -58.374526], 14);

//Se elige el tipo de mapa, sus caracteristicas y se pasan al objeto map
L.tileLayer('http://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: 'Map data &copy; <a href="http://openstreetmap.org">OpenStreetMap</a> contributors, <a href="http://creativecommons.org/licenses/by-sa/2.0/">CC-BY-SA</a>, Imagery © <a href="http://cloudmade.com">CloudMade</a>',
    maxZoom: 16,
    minZoom: 4
}).addTo(map);

//Se crea el objeto globoMarcador cuya funcion es la de marcador en el mapa para el dispositivo transmisor
const globoMarcador = L.icon({
    iconUrl: "../../../resources/icons/GloboMarcadorRojo1.svg",
    iconSize: [80, 80],
    iconAnchor: [43, 22]
});

//Se crea el objeto baseMarcador cuya funcion es la de marcador en el mapa para la base terrena
const baseMarcador = L.icon({
    iconUrl: "../../../resources/icons/BaseMarcador1.png",
    iconSize: [50, 50],
});

//Se agrega al mapa los controles de zoom (+ / -)
L.control.scale().addTo(map);

//Se posiciona el marcador correspondiente a la base y se agrega la funcion de popup
L.marker([-34.616730, -59.374526], {draggable: false, icon: baseMarcador}).addTo(map).
bindPopup("<b>Base terrena</b><br>Usted se encuentra aquí<br>Latitud:<br>Longitud:");

//Se posiciona el marcador correspondiente al transmisor y se agrega la funcion de popup
L.marker([-34.616730, -58.374526], {draggable: false, icon: globoMarcador}).addTo(map).
bindPopup("<b>Transmisor</b><br>Distancia: 100 km<br>Altitud: 13400 m<br>");

//Se posiciona el marcador correspondiente a la base y se agrega la funcion de popup
var popup = L.popup({autoClose: true });

//Event handler de popup 
function onMapClick(e) {
    popup
        .setLatLng(e.latlng)
        .setContent("Posción clickeada " + e.latlng.toString())
        .openOn(map);
}

map.on('click', onMapClick);

