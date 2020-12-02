module.exports = {
    a
};

var var_a = require('./b.js')

function a(n){
    if(n > 0){
        console.log('Wywołano a')
        var_a.b(n)
    }
}