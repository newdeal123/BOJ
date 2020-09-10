const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function (line) {
  var input=line.split(' ').map((i)=>parseInt(i));
  var a=input[0],b=input[1];
  for(i=0;i<=2000;i++)
    for(j=0;j<=2000;j++)
    {
      //console.log(i,j,i+j,Math.abs(i-j));
        if(i+j===a&&Math.abs(i-j)===b) 
      {
        console.log(Math.max(i,j),Math.min(i,j));
        rl.close();
      }
    }
  console.log(-1);
  rl.close();
  }).on('close', function () {
    process.exit();
  });