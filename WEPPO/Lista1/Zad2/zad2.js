var liczba = 0;
var suma = 0;
var flaga = true;
for (var i = 1; i < 100000; i++){
    liczba = i;
    suma = 0;
    flaga = true;
    while (liczba != 0){
        var curr = liczba % 10;
        liczba = Math.floor(liczba/10);
        suma += curr;
        if ((curr != 0) && (liczba%curr != 0)){
            flaga = false;
        }
    }
    if(flaga){
        console.log( i )
    }
}