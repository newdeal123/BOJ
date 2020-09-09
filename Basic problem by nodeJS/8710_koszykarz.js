const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function (line) {
  var input=line.split(' ').map((i)=>parseInt(i));
  var k=input[0],w=input[1],m=input[2];
  console.log(parseInt((w-k)/m)+1+((w-k)%m===0?-1:0));
  rl.close();
  }).on('close', function () {
    process.exit();
  });