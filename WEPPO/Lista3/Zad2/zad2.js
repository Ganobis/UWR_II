function recFib(n){
    if(n == 0)
        return 0
    if(n == 1 || n == 2)
        return 1
    else
        return (recFib(n-1) + recFib(n-2))
}

function iterFib(n){
    let v1 = 0
    let v2 = 1
    let sum = 0
    for(var i = 0; i < n-1; i++){
        sum = v1 + v2
        v1 = v2
        v2 = sum
    }
    return v2
}

function memFib(n){
    let x = {0: 0, 1: 1};
    function f(m){
        if(typeof x[m] == 'undefined'){
            x[m] = f(m-1) + f(m-2)
        }
        return x[m]
    }
    return f(n)
}


console.time("test iteracyjny");
iterFib(40);
console.timeEnd("test iteracyjny");
console.time("test rekurencyjny");
recFib(40);
console.timeEnd("test rekurencyjny");
console.time("test memoizacyjny");
memFib(40);
console.timeEnd("test memoizacyjny");
