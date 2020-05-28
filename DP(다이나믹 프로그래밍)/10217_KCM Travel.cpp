#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
const int INF=987654321,MAX_N=100+2;
int N,M,K,cache[MAX_N][MAX_N*MAX_N];
struct Edge{
    int v,cost,time;
};
bool operator <(Edge a,Edge b){
    if(a.time!=b.time)return a.time<b.time;
    else return a.cost<b.cost;
}
vector<Edge>adj[MAX_N];

int f(int now,int money)
{
    if(now==N)return 0;
    int&ret=cache[now][money];
    if(ret!=-1)return ret;
    ret=INF;

    for(auto next:adj[now])
    {
        if(money>=next.cost)ret=min(ret,f(next.v,money-next.cost)+next.time);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N>>M>>K;
        for(int i=0;i<MAX_N;i++)adj[i].clear();
        memset(cache,-1,sizeof(cache));
        while(K--)
        {
            int u,v,c,t;
            cin>>u>>v>>c>>t;
            adj[u].push_back({v,c,t});
        }
        int ans=f(1,M);
        if(ans==INF)cout <<"Poor KCM\n";
        else cout<<ans<<"\n";
    }
}
