const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function (line) {
  var input=line.split(' ').map((i)=>parseInt(i));
  var d=input[0],h=input[1],m=input[2];
  var time=11*24*60+11*60+11;
  var thisTime=d*24*60+h*60+m;
  
  if(time>thisTime)console.log(-1);
  else console.log(thisTime-time);

  rl.close();
  }).on('close', function () {
    process.exit();
  });