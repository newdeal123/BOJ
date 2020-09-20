const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function trans(c){
  if(c==='A')return 1;
  else if(c==='T')return 10;
  else if(c==='J')return 11;
  else if(c==='Q')return 12;
  else if(c==='K')return 13;
  else return parseInt(c,10);

}

var N,arr=[],lineN=0;
var cache=new Array(8);

for(i=0;i<8;i++) cache[i]=new Array(8);
for(i=0;i<8;i++)
  for(j=0;j<8;j++)cache[i][j]=-1;

function dp(nowY,nowX){
  if(nowY<0||nowY>=N||nowX<0||nowX>=N)return -1;
  if(nowY==0&&nowX==N-1)return arr[nowY][nowX];

  if(cache[nowY][nowX]!=-1)return cache[nowY][nowX];

  return cache[nowY][nowX]=Math.max(dp(nowY-1,nowX),dp(nowY,nowX+1))+arr[nowY][nowX];
}

rl.on('line', function (line) {
  if(lineN==0){
    N=Number(line);
  }
  else{
    var input=line.split(' ').map((i)=>(i));
    var tmp=[];
    for(i=0;i<N;i++)
      tmp.push(trans(input[i][0]));
    arr.push(tmp);
  }

  if(lineN++==N){
    console.log(dp(N-1,0));
    rl.close();
  }

  }).on('close', function () {
    process.exit();
  });