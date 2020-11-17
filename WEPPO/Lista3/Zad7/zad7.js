function iter_fib(){
    let f = [0, 1]
    return{
        next: function() {
            f = [f[1], f[1] + f[0]]
            return{
                value: f[0] + f[1],
                done: false
            }
        }
    }
}

function *fib() {
    let f = [0, 1]
    while(1){
        yield f[1]
        f = [f[1], f[0] + f[1]]
    }
}

var _it = iter_fib();
for ( var _result; _result = _it.next(), !_result.done; ) {
    if(_result.value > 150)
         break;
    console.log( _result.value );
}



for ( var i of fib() ) {
    if(i > 150)
            break;
    console.log( i );
}
