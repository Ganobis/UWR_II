module.exports = {
    b
};

var var_b = require('./a.js')

function b(n){
    console.log('Wywołano b')
    var_b.a(n-1)
}