var values_rec = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34];
var values_it = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34];


for(var i = 10; i < 30; i++){
    console.log("dla wyrazu" + i + ": ")
    console.time("Czas na rekurencyje");
    values_rec.push(fib_rec(i));
    console.timeEnd("Czas na rekurencyje");
    console.time("Czas na iteracyjne");
    values_it.push(values_it[i-1] + values_it[i-2]);
    console.timeEnd("Czas na iteracyjne");
}



console.log( values_rec + "\n" + values_it );

function fib_rec(n){
    if(n > 1){
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
    else{
        return n;
    }
}
// na google chrome wykonuje się nieco woleniej, a na microsoft edge jeszcze wolniej