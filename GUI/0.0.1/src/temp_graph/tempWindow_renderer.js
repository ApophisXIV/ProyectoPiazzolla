const {ipcRenderer} = require('electron');

let tempChart = new Chart(document.getElementById("tempCHART").getContext("2d"), {
  type: 'line',
  data: {
    labels: [],
    datasets: [
      {
        label: "Temperatura [°C]",
        data: []
      }
    ]
  },
  options:  {
    scales: {
      yAxes: [{
        type: 'linear',
        ticks: {
          beginAtZero: true,
        }
      }],
      xAxes: {
        type: 'time',
        ticks: {
          beginAtZero: true,
        },
        time: {
          unit: 'second',
          displayFormats: {
            'second': 'HH:mm:ss:mm',
          },
          tooltipFormat: 'HH:mm:ss:mm',
        }
      }
    },

    showLines: true

  }

});

ipcRenderer.on('ventana_tempWINDOW', (event, tempData) => {
  

  document.getElementById('h1').innerHTML="T= "+ tempData[0] + " H= " + tempData[1] + " C= " + tempChart.data.datasets[0].data.length;
  
  tempChart.data.labels.push(tempData[1]);

  tempChart.data.datasets[0].data.push(tempData[0]);

  if (tempChart.data.datasets[0].data.length>50) {

    tempChart.data.labels.shift();

    tempChart.data.datasets[0].data.shift();

    tempChart.update();

  }

  else{

    tempChart.update();

  }

});