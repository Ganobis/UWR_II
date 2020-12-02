var flaga = false;
for(var l = 2; l < 100000 ; l++){
    flaga = true
    if(flaga){
        for (var i = 2; i < l; i++) {
            if(l % i == 0)
                flaga = false;
        }
    }
    if(flaga){
        console.log( i )
    }
}