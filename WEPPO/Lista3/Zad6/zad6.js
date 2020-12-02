function createGenerator(n) {
    return function(){
        var _state = 0;
        return {
            next : function() {
                return {
                    value : _state,
                    done : _state++ >= n
                    }
            }
        }
    }
}

var foo = {
    [Symbol.iterator] : createGenerator(5)
};

for ( var f of foo )
    console.log(f);
console.log("XXX")
var foo2 = {
    [Symbol.iterator] : createGenerator(9)
};
    
for ( var f of foo2 )
    console.log(f);
        