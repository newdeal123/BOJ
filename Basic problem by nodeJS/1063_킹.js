const readline = require('readline');
const { RSA_X931_PADDING } = require('constants');
const { type } = require('os');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

var inputTurn=-1;
var kingY,kingX,stoneY,stoneX,query;
var dY=[1,-1,0,0,1,-1,1,-1],dX=[0,0,-1,1,1,1,-1,-1];

function trans(a){
    if(a==='R')return 0;
    else if(a==='L')return 1;
    else if(a==='B')return 2;
    else if(a==='T')return 3;
    else if(a==='RT')return 4;
    else if(a==='LT')return 5;
    else if(a==='RB')return 6;
    else if(a==='LB')return 7;
    else return -1;
}

function is_in_board(y,x){
    if(y<1||y>8||x<1||x>8)return false;
    else return true;
}

rl.on('line', function (line) {
    inputTurn++;
    if(inputTurn===0){
        var input=line.split(' ').map((i)=>(i));
        kingY=input[0].charCodeAt(0)-64,kingX=input[0].charCodeAt(1)-48;
        stoneY=input[1].charCodeAt(0)-64,stoneX=input[1].charCodeAt(1)-48;
        query=Number(input[2]);
    }
    else{
        var idx=trans(line);
        //console.log(idx);
        if(kingY+dY[idx]===stoneY&&kingX+dX[idx]===stoneX){
            if(is_in_board(stoneY+dY[idx],stoneX+dX[idx])){
                kingY+=dY[idx],kingX+=dX[idx];
                stoneY+=dY[idx],stoneX+=dX[idx];
            }
        }
        else if(is_in_board(kingY+dY[idx],kingX+dX[idx])){
            kingY+=dY[idx],kingX+=dX[idx];
        }
        //console.log(String.fromCharCode(kingY+64)+kingX);
        //console.log(String.fromCharCode(stoneY+64)+stoneX);
    }

    if(inputTurn===query){
        console.log(String.fromCharCode(kingY+64)+kingX);
        console.log(String.fromCharCode(stoneY+64)+stoneX);
        rl.close();
    }
  }).on('close', function () {
    process.exit();
  });