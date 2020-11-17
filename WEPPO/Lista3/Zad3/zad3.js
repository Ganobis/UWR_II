function forEach(tab, f) {
    for (var i = 0; i < tab.length; i++) {
        f(tab[i])
    }
}

function filter(tab, f) {
    var temp = []
    for (var i = 0; i < tab.length; i++) {
        if (f(tab[i])) {
            temp.push(tab[i])
        }
    }
    return temp
}

function map(tab, f) {
    for (var i = 0; i < tab.length; i++) {
        tab[i] = f(tab[i])
    }
}


var tab = [1, 2, 3, 4, 5]

map(tab, _ => _ + 3)
forEach(tab, _ => {console.log(_)})
console.log(filter(tab, _ => _ > 5))