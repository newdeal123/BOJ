const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

var N,arr=[],lineN=0;


rl.on('line', function (line) {
  if(lineN==0){
    N=Number(line);
  }
  else{
    var input=line.split(' ').map((i)=>(i));
    if(input[0]==parseInt(input[0],10)){
      arr.push([Number(input[0])/2,input[1]]);
    }
    else arr.push([Number(input[1]),input[0]]);
  }

  if(lineN++==N){
    arr.sort(function(a,b){
      return a[0]-b[0];
    });
    for(i=0;i<N;i++) console.log(arr[i][1]);
    rl.close();
  }
  }).on('close', function () {
    process.exit();
  });