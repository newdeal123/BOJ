#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=100+2,INF=987654321;
int N,T,M,L,cache[MAX_N][10000+2];

struct NODE
{
    int v,time,cost;
};
vector<NODE>adj[MAX_N];

int f(int now,int timeRemain)
{
    if(now==N)return 0;
    int&ret=cache[now][timeRemain];
    if(ret!=-1)return ret;
    ret=INF;

    for(auto i:adj[now])
    {
        int next=i.v,nextT=i.time,nextC=i.cost;
        if(timeRemain>=nextT) ret=min(ret,f(next,timeRemain-nextT)+nextC);
    }
    return ret;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N>>T>>M>>L;
    while(L--)
    {
        int u,v,t,c;
        cin>>u>>v>>t>>c;
        adj[u].push_back({v,t,c});
        adj[v].push_back({u,t,c});
    }
    if(f(1,T)<=M)cout<<f(1,T);
    else cout<<-1;
}

