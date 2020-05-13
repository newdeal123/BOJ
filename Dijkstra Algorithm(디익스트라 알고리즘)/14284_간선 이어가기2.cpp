#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int INF=987654321;
const int MAX_N=5000+2;
int N,M;
vector<pair<int,int>>adj[MAX_N];

int dijkstra(int start,int fin)
{
    priority_queue<pair<int,int>>pq;
    vector<int>dist(N+1,INF);
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty())
    {
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])continue;

        for(auto i:adj[now])
        {
            int next=i.first,nextDist=i.second+cost;
            if(nextDist<dist[next])
            {
                dist[next]=nextDist;
                pq.push({-nextDist,next});
            }
        }
    }
    return dist[fin];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    while(M--)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    int start,fin;
    cin>>start>>fin;
    cout<<dijkstra(start,fin);
}
