const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let allDays=[31,28,31,30,31,30,31,31,30,31,30,31];
let allYears=365;

rl.on('line', function (line) {
  const date=new Date(line+':00');
  const year=1900 + date.getYear();
  const month=date.getMonth();

  if(year%400==0||(year%4==0&&year%100!=0)){
    allDays[1]++;
    allYears++;
  }
  let sum=0;
  for(let i=0;i<month;i++)sum+=allDays[i];
  sum += date.getDate()-1+(date.getHours()+(date.getMinutes()/60))/24;
  console.log(sum/allYears*100);

  rl.close();
    
  }).on('close', function () {
    process.exit();
  });