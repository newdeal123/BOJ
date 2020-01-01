#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=2000+2,INF=987654321;
int N,M,T,S,G,H;
vector<pair<int,int>>adj[MAX_N];

int dijkstra(int u,int v)
{
    priority_queue<pair<int,int>>pq;
    vector<int>dist(N+1,INF);
    dist[u]=0;
    pq.push({0,u});
    while(!pq.empty())
    {
        int now=pq.top().second,cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])continue;
        if(now==v)return dist[v];
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
    return INF;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<MAX_N;i++)adj[i].clear();
        cin>>N>>M>>T>>S>>G>>H;
        while(M--)
        {
            int u,v,dist;
            cin>>u>>v>>dist;
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        vector<int>ans;
        while(T--)
        {
            int fin;
            cin>>fin;
            int minDist=dijkstra(S,fin);
            if(dijkstra(S,G)+dijkstra(G,H)+dijkstra(H,fin)==minDist ||
               dijkstra(S,H)+dijkstra(H,G)+dijkstra(G,fin)==minDist)ans.push_back(fin);
        }
        sort(ans.begin(),ans.end());
        for(auto i:ans)cout<<i<<" ";
        cout<<"\n";
    }
}
