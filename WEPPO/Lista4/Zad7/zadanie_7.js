var ul = require('util')
var fs = require('fs')


function func(fileName, type){
    return new Promise(function(resolve, reject){
      fs.readFile(fileName, type, (err, data) => {
          if (err) { reject(err); }
          resolve(data);
      })
    });
}

async function f1(){
    var text = await func("xxx.txt", 'utf-8')
    console.log(text)
}

async function f2(){
    var text = await ul.promisify(fs.readFile)("xxx.txt", 'utf-8')
    console.log(text)
}

async function f3(){
    await fs.promises.readFile("xxx.txt", 'utf-8')
    .then(function(result) { 
        console.log(result) })
}



f1()

f2()

f3()

