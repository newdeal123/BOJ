const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

var lineN=0,N,cnt=0,arr=[];

rl.on('line', function (line) {
  if(lineN++==0) N=Number(line);
  else arr.push(line);
  
  if(lineN>N){
    for(i=0;i<N;i++){
      var findSame=false;
      for(j=0;j<i;j++){
        if((arr[i]+arr[i]).search(arr[j])!=-1 && arr[i].length==arr[j].length){
          findSame=true;
          break;
        }
      }
      if(findSame===false) cnt++;
    }
    console.log(cnt);
    rl.close();
  }

  }).on('close', function () {
    process.exit();
  });