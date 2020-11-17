obiekt = {
    funkcja(){
        console.log("Uruchomiono funkcje");
    },
    _wartosc: 11,
    get wartosc(){
        return this._wartosc
    },
    set wartosc(x){
        this._wartosc = x
    }
}
console.log(obiekt.wartosc)
obiekt.funkcja()
obiekt.wartosc = 10
console.log(obiekt.wartosc)

Object.defineProperty(obiekt, "_wartosc2", {
    value: 42,
    writable: true
})

Object.defineProperty(obiekt, "wartosc2", {
    get: function() {
        return this._wartosc2
    },
    set: function(x) {
        this._wartosc2 = x
    }
})

obiekt.funkcja2 = () => {
    console.log("Druga funkcja")
}

obiekt.funkcja2()
console.log(obiekt.wartosc2)
obiekt.wartosc2 = 0
console.log(obiekt.wartosc2)