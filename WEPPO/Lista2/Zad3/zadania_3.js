console.log((![]+[])[+[]])
console.log(![])
console.log(![]+[])
console.log(+[])

console.log('\npierwsze wyrażenie= ' + ('false')[0] + '\n')

console.log((![]+[])[+!+[]])
console.log(![]+[])
console.log(+!+[])

console.log('\ndrugie wyrazenie= ' + ('false')[1] + '\n')

console.log(([![]]+[][[]])[+!+[]+[+[]]])
console.log([][[]])
console.log([![]]+[][[]])
console.log([+!+[]+[+[]]])
console.log('\ntrzecie wyrażenie= ' + ('falseundefined')[10] + '\n')

console.log((![]+[])[!+[]+!+[]])
console.log(!+[]+!+[])
console.log('\nczwarte wyrażenie= ' + ('false')[2] + '\n')

console.log( (![]+[])[+[]]  +  (![]+[])[+!+[]]  +  ([![]]+[][[]])[+!+[]+[+[]]]  +  (![]+[])[!+[]+!+[]] );
//Co daje nam failm złozone z false i falseundefined