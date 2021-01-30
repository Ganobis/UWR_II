var http = require('http');
var filename = 'przyklad.txt';
var server =
    http.createServer(
        (req, res) => {
            res.setHeader('Content-Disposition', 'attachment;filename=' + filename);
            res.write('test');
            res.end();
        });
server.listen(3000);
console.log('Site started!');