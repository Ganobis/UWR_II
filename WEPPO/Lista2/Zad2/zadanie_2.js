//użycie operatorów

var przyklad = {

}

przyklad.xx = 42
console.log(przyklad.xx)
console.log(przyklad['x' + 'x'])
przyklad['xx'] = 24
console.log(przyklad.xx)
//przyklad[xx] = 11         //Daje błąd bo xx nie jest zdefiniowane, i program nie wie do czego się odwołać, w przypadku 'xx' dostaje stringa

//W odwołanie przez . jest bardziej intuicyjne dla większości programistów ponieważ podobne odwołania występują w innych językach. Odwołania poprzez [] mogą wykorzysywać bardziej złożone możliwości (np łączenie stringów). Jak widać oba operatory robią to samo i można je używać zamiennie.

//użycie argumentów
var obiekt2 = {

}

var obiekt21 = {

}

var przyklad2 = {
    1: 'xxx', //Tworzy klucz liczbie 1
    obiekt2: 200 //Tworzy klucz elementowi obiekt2, ale nie jest to obiekt2 zadeklarowany wyżej
}

console.log(przyklad2[1]) //Nie można odwołac się za pomocą '.'
console.log(przyklad2.obiekt2)
przyklad2[obiekt21] = 'kkk' //Tutaj dopiero dodaje obiekt21 jako obiekt i podaje mu klucz kkk
console.log(przyklad2[obiekt21])
console.log(przyklad2.obiekt21)
console.log(przyklad2)

//użycie innego typu niż number

var przyklad3 = [1, 2, 3]
przyklad3["x"] = 4 // Dodaje na koniec tablicy a : 2
console.log(przyklad3) //Nic nie wypisuje
console.log(przyklad3["x"])
przyklad3[obiekt2] = 5 // Dodaje na koniec tablicy [object Object]: 5
console.log(przyklad3) //Nic nie wypisuje
przyklad3.length = 8 // Powiększa tablice, a na nieistniejących elementach wstawia '...'
console.log(przyklad3) //Nic nie wypisuje
przyklad3.length = 1 //Usuwa elementy z tablicy
console.log(przyklad3) //Nic nie wypisuje