var http = require('http');
var fs = require('fs');

var readData = fs.readFileSync('champ.json');
var parseData = JSON.parse(readData);

http.createServer(function (req, res) {
    res.writeHead(200, {'Content-Type': 'application/json'});
    res.end(readData);
  }).listen(8080);