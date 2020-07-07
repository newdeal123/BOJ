#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
const int MAX_N=1e3+2,INF=987654321;
int N,M,cache[MAX_N];
int dist[MAX_N];
vector<pair<int,int>>adj[MAX_N];


int f(int now)
{
    if(now==2)return 1;

    int&ret=cache[now];
    if(ret!=-1)return ret;
    ret=0;

    for(auto next:adj[now])
        if(dist[next.first]<dist[now])ret+=f(next.first);
    return ret;
}

void dijkstra()
{
    for(int i=1;i<=N;i++) dist[i]=INF;
    priority_queue<pair<int,int>>pq;
    dist[2]=0;
    pq.push({0,2});
    while(!pq.empty())
    {
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])continue;

        for(auto i:adj[now])
        {
            int next=i.first;
            int nextDist=i.second+cost;
            if(nextDist<dist[next])
            {
                dist[next]=nextDist;
                pq.push({-nextDist,next});
            }
        }
    }
    return ;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    memset(cache,-1,sizeof(cache));
    while(M--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    dijkstra();
    cout<<f(1);
}
