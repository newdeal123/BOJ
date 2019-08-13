#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const int INF=987654321;
int N,M,cache[1001][200][11];
vector<int>cost;

int f(int idx,int m,int last)
{
    if(idx==N+1) return 0;
    int&ret=cache[idx][m][last];
    if(ret!=-1) return ret;
    ret=INF;
    if(cost[idx-1]+last<=cost[idx])return ret=f(idx+1,m,0);
    for(int i=0;i<=min(10,m);i++)
        ret=min(ret,f(idx+1,m-i,i)+(int)pow(cost[idx-1]+last-cost[idx]-i,2));
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    cost.resize(N+1);
    cost[0]=0;
    for(int i=1;i<=N;i++)cin>>cost[i];
    cout<<f(1,M,0);
}
