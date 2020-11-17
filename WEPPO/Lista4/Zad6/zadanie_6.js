var lineReader = require('readline').createInterface({
    input: require('fs').createReadStream('log.txt')
});

var dict = {};
lineReader.on('line', (line) => {
    var ip = line.split(" ")[1]
    if (dict[ip] === undefined) {
        dict[ip] = 1
    }
    else {
        dict[ip] += 1
    }
})
.on('close', function () {
    var max = 0
    for (var i = 0; i < 3; i++) {
        for(var key in dict){
            if (dict[key] >= max){
                max = key
                ip = dict[key]
            }
        }
        console.log(max, dict[max])
        delete dict[max]
        max = 0
    }
})