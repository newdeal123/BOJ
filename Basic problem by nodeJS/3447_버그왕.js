const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function (line) {

   while(line.search('BUG')!=-1){
     line=line.replace('BUG','');
   }
  console.log(line);

  }).on('close', function () {
    process.exit();
  });