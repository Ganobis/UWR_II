reducer = (a, b) => a + b
function sum() {
    return Object.values(arguments).reduce(reducer);
}

console.log(sum(1,2,3))
console.log(sum(1,2,3,4,5))