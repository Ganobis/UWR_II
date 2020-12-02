function Tree(value, left, right) {
    this.value = value;
    this.left = left;
    this.right = right;
}

function * Generator (){
    var kolejka = [this]
    while (kolejka.length) {
        var item = kolejka.shift()
        if(item.right) {
            kolejka.push(item.right)
        }
        if(item.left) {
            kolejka.push(item.left)
        }
        yield item.value
    }
}

Tree.prototype = {[Symbol.iterator]:Generator}

var root = new Tree( 1,
    new Tree( 2, new Tree( 3 ) ), new Tree( 4 ))

for ( var e of root ) {
    console.log( e )
}