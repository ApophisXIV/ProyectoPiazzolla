let ctx = document.getElementById('TempGraph');
    new Chart (ctx, {
        type: 'pie',
        data: {
            labels: ['Total Pokemones', 'Porcentaje ' + condition],
            datasets: [{
                label: '# of Votes',
                data: [dataPokemon.length, sizePokemon],
                backgroundColor: [
                    
                    
                    'rgba(255, 206, 86, 1)',
                    'rgba(153, 102, 255, 1)',
                    
                ],
                borderColor: [
                   
                    
                    'rgba(255, 206, 86, 1)',
                    'rgba(153, 102, 255, 1)',
                    
                ],
                borderWidth: 1
            }]
        },
        
    });