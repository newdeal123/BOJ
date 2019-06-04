#include <bits/stdc++.h>
using namespace std;
const int MAX_N=50+2;
int cache[MAX_N][MAX_N][MAX_N][3][4];
string s;

int f(int sum1,int sum2,int sum3,int rest1,int rest2)
{
    if(!sum1 && !sum2 && !sum3) return 1;
    int&ret= cache[sum1][sum2][sum3][rest1][rest2];
    if(ret !=-1) return ret;
    ret=0;
    if(sum1>0) ret=max(ret,f(sum1-1,sum2,sum3,min(2,rest1+1),min(3,rest2+1)));
    if(sum2>0 && rest1>=1) ret=max(ret, f(sum1,sum2-1,sum3,0,min(3,rest2+1)));
    if(sum3>0 && rest2>=2) ret=max(ret, f(sum1,sum2,sum3-1,min(2,rest1+1),0));
    return ret;
}

void output(int sum1,int sum2,int sum3,int rest1,int rest2)
{
    if(!sum1 && !sum2 && !sum3) return;
    if(sum1>0 && f(sum1-1,sum2,sum3,min(2,rest1+1),min(3,rest2+1)))
    {
        cout <<"A";
        return output(sum1-1,sum2,sum3,min(2,rest1+1),min(3,rest2+1));
    }
    if(sum2>0 && rest1>=1 && f(sum1,sum2-1,sum3,0,min(3,rest2+1)))
    {
        cout <<"B";
        return output(sum1,sum2-1,sum3,0,min(3,rest2+1));
    }
    if(sum3>0 &&rest2>=2 && f(sum1,sum2,sum3-1,min(2,rest1+1),0))
    {
        cout <<"C";
        return output(sum1,sum2,sum3-1,min(2,rest1+1),0);
    }
}

int main()
{
    memset(cache,-1,sizeof(cache));
    int sum[3]={0,};
    cin >> s;
    for(auto c:s)
        sum[c-'A']++;
   bool possible= f(sum[0],sum[1],sum[2],2,3);
   if(possible)
    output(sum[0],sum[1],sum[2],2,3);
   else
    cout <<-1;
}
