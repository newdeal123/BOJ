#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int MAX_N=1000+2,MAX_M=30000+2;
const ll INF=987654321987654321;
int N,M,K,start,fin;
ll cache[MAX_N],dist[MAX_N][MAX_N];
vector<pair<int,int>>adj[MAX_N];

ll dijkstra()
{
    ll ret=INF;
    for(int i=0;i<MAX_N;i++)cache[i]=INF;
    for(int j=0;j<MAX_N;j++)
        for(int k=0;k<MAX_N;k++)dist[j][k]=INF;

    priority_queue<pair<ll,pair<int,int>>>pq;
    pq.push({0,{start,0}});
    dist[start][0]=0;
    while(!pq.empty())
    {
        ll cost=-pq.top().first;
        int now=pq.top().second.first,visited=pq.top().second.second;
        pq.pop();
        if(visited>N || cost>dist[now][visited])continue;
        if(now==fin)cache[visited]=min(cache[visited],cost);

        for(auto j:adj[now])
        {
            int next=j.first,nextVisited=visited+1;
            int nextDist=cost+j.second;
            if(nextDist<dist[next][nextVisited])
            {
                dist[next][nextVisited]=nextDist;
                pq.push({-nextDist,{next,nextVisited}});
            }
        }
    }
    for(int i=1;i<=N;i++)
        if(dist[fin][i]!=INF)ret=min(ret,dist[fin][i]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M>>K;
    cin>>start>>fin;
    for(int i=0;i<M;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    cout<< dijkstra()<<"\n";
    while(K--)
    {
        int p;
        ll minN=INF;
        cin>>p;
        for(int i=1;i<=N;i++)
        {
            if(cache[i]==INF)continue;
            cache[i]+=p*i;
            minN=min(minN,cache[i]);
        }
        cout<<minN<<"\n";
    }
}
