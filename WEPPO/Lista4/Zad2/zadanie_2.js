function Foo() {
    console.log('Foo')
}

Foo.prototype.Bar = function() {
    function Qux() {
        console.log('Qux')
    }
    Qux();
    console.log('Bar')
}

const f = new Foo()
console.log("XXX")
f.Bar()
f.Qux() //error