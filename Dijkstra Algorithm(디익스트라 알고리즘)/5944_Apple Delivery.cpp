#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
const int INF=987654321,MAX_N=100000+2;
int M,N,start,finA,finB;
vector<pair<int,int>>adj[MAX_N];

int dijkstra()
{
    priority_queue<pair<int,pair<int,int>>>pq;
    int dist[MAX_N][4];
    for(int i=0;i<MAX_N;i++)
        for(int j=0;j<4;j++)dist[i][j]=INF;
    pq.push({0,{start,0}});

    while(!pq.empty())
    {
        int now=pq.top().second.first;
        int bits=pq.top().second.second;
        int cost=-pq.top().first;
        pq.pop();
        if(bits==3)return cost;
        if(cost>dist[now][bits])continue;

        for(auto i:adj[now])
        {
            int next=i.first;
            int nextDist=cost+i.second;
            int nextBits=bits;
            if(next==finA)nextBits|=(1<<0);
            if(next==finB)nextBits|=(1<<1);
            if(dist[next][nextBits]>nextDist)
            {
                dist[next][nextBits]=nextDist;
                pq.push({-nextDist,{next,nextBits}});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>M>>N>>start>>finA>>finB;
    while(M--)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    cout<<dijkstra();
}
