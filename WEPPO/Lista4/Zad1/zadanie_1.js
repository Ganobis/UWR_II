function Tree(val, left, right) {
 this.left = left;
 this.right = right;
 this.val = val;
}

Tree.prototype[Symbol.iterator] = function*() {
 yield this.val;
 if ( this.left ) yield* this.left;
 if ( this.right ) yield* this.right;
}

var root = new Tree( 1, new Tree( 2, new Tree( 3 ) ), new Tree( 4 ));

function* createGenerator(){
    function* aux(tree){
        if(tree == null){
            return
        }
        yield* aux(tree.left)
        yield tree.v
        yield* aux(tree.right)
    }
    yield* aux(tree)
}

for ( var e of root ) {
    console.log( e );
}

var iter_root = createGenerator(root)

for (var x in iter_root){
    console.log(x)
}