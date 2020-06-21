#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int INF=987654321;
int N,K,cache[1<<20];
int effort[21][21];

int f(int bits,int emptyN)
{
    if(emptyN==(N-K))return 0;
    int&ret=cache[bits];
    if(ret!=-1)return ret;
    ret=INF;

    for(int i=0;i<N;i++)
    {
        if(bits&(1<<i))continue;
        int minN=INF;
        for(int j=0;j<N;j++)
            if(i!=j&&!(bits&(1<<j)))minN=min(minN,effort[i][j]);
        ret=min(ret,f(bits|(1<<i),emptyN+1)+minN);
    }
    return ret;
}

int main()
{
    cin>>N>>K;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)cin>>effort[i][j];
    cout<<f(0,0);
}
