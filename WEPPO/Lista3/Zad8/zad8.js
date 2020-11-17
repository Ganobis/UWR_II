function *fib() {
    let f = [0, 1]
    while(1){
        yield f[1]
        f = [f[1], f[0] + f[1]]
    }
}

function *take(it, top) {
    for(var i = 0; i < top; i++)
        yield it.next().value;
}

for (let num of take( fib(), 10 ) ) {
    console.log(num);
}
    