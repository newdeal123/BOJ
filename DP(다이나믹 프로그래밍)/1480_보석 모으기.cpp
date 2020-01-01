#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,M,C,cache[21][10][1<<13];
int weight[21];

int f(int extra,int n,int bits)
{
    int&ret=cache[extra][n][bits];
    if(ret!=-1)return ret;
    ret=0;
    if(n)ret=max(ret,f(C,n-1,bits));
    for(int i=0;i<N;i++)
    {
        if(bits&(1<<i)||extra<weight[i])continue;
        ret=max(ret,f(extra-weight[i],n,bits|(1<<i))+1);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M>>C;
    for(int i=0;i<N;i++)cin>>weight[i];
    cout<<f(C,M-1,0);
}
