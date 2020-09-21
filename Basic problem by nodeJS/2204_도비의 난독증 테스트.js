const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
var testCase=0;
var arr=[];
rl.on('line', function (line) {
  testCase--;
  if(testCase===-1){
    testCase=Number(line);
    if(testCase===0) rl.close();
  }
  else{
    var s=line.toLowerCase();
    arr.push([line.toLowerCase(),line]);
  }
  if(testCase===0){
    arr.sort();
    console.log(arr[0][1]);
    arr=[];
  }
  }).on('close', function () {
    process.exit();
  });