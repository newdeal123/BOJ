const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function (line) {

  var input=line.split(' ').map((i)=>parseInt(i));

  if(input[0]+input[1]+input[2]===0)
    rl.close();
  
  if((input[2]-input[0])%input[1]===0 && ((input[2]-input[0])/input[1])+1 > 0)
    console.log(((input[2]-input[0])/input[1])+1);
  else console.log('X');

  }).on('close', function () {
    process.exit();
  });