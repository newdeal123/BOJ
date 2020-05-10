#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=100000,MOD=1e9+7;
int N,cache[252][252];

int f(int now,int gNum)
{
    if(now==0)return (gNum==0?1:0);
    int&ret=cache[now][gNum];
    if(ret!=-1)return ret%MOD;
    ret=0;
    for(int i=0;i<now;i++)
        ret=(ret+f(now-(i+1),gNum^i))%MOD;
    return ret%MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    cout<<f(N+1,0);
}
