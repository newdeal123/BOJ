#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N=250+2,INF=987654321;
int adj[MAX_N][MAX_N];
vector<int>parent;
int N,M;

int dijkstra(int start,int fin)
{
    priority_queue<pair<int,int>>pq;
    vector<int>dist(N+1,INF);
    pq.push({0,start});
    dist[start]=0;
    parent[start]=start;
    while(!pq.empty())
    {
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])continue;
        if(now==fin)return cost;
        for(int i=1;i<=N;i++)
        {
            if(adj[now][i]==0)continue;
            int next=i;
            int nextDist=cost+adj[now][i];
            if(nextDist<dist[next])
            {
                dist[next]=nextDist;
                parent[next]=now;
                pq.push({-nextDist,next});
            }
        }
    }
    return -1;
}

int main()
{
    cin>>N>>M;
    parent.resize(N+1);
    while(M--)
    {
        int u,v,dist;
        cin>>u>>v>>dist;
        adj[u][v]=dist;
        adj[v][u]=dist;
    }
    int len=dijkstra(1,N),maxN=0;
    vector<int>v=parent;
    for(int p=N;p!=v[p];p=v[p])
    {
        //cout<<p<<" "<<v[p]<<endl;
        adj[p][v[p]]*=2;
        adj[v[p]][p]*=2;
        maxN=max(maxN,dijkstra(1,N));
        adj[p][v[p]]/=2;
        adj[v[p]][p]/=2;
    }
    cout<<maxN-len;
}
