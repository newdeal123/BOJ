const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

var N,K,arr=[],lineN=0;


rl.on('line', function (line) {
  if(lineN==0){
    var input=line.split(' ').map((i)=>parseInt(i));
    N=input[0],K=input[1];
  }
  else{
    arr.push(line);
  }

  if(lineN++==N){
    arr.sort();
    console.log(arr[K-1]);
    rl.close();
  }
  }).on('close', function () {
    process.exit();
  });