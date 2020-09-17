const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

class stack{
  constructor(){
    this.store=[];
    this.nowSize=0;
  }
  push(item){
    this.store.push(item);
    this.nowSize++;
  }
  pop(){
    this.nowSize--;
    return this.store.pop();
  }
  top(){
    return this.store[this.nowSize-1];
  }
  size(){
    return this.nowSize;
  }
}

rl.on('line', function (line) {
  const stk=new stack();
  for(var i of line){
    //console.log(stk.top(),i);
    if(stk.size()==0||stk.top()!=i){
      stk.push(i);
    }
  }
  console.log(parseInt(stk.size()/2,10));
  rl.close();

  }).on('close', function () {
    process.exit();
  });