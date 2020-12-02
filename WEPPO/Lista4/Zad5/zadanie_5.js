require('fs').readFile('xxx.txt', 'utf-8', (error, data)=> {
    if(error) {
        throw error
    }
    console.log(data)
})