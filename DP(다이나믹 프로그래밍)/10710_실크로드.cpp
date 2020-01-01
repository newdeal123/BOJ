#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
const int INF=987654321;
int N,M,cache[1001][1001],weather[1001],dist[1001];

int f(int city,int days)
{
    if(city==N)return 0;

    int&ret=cache[city][days];
    if(ret!=-1)return ret;
    ret=INF;
    for(int i=1;i+days<=M;i++)
        ret=min(ret,f(city+1,days+i)+weather[days+i-1]*dist[city]);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    for(int i=0;i<N;i++)cin>>dist[i];
    for(int i=0;i<M;i++)cin>>weather[i];
    cout<<f(0,0);
}
