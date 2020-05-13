#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int INF=987654321;
int N,D;
vector<pair<int,int>>adj[10001];

int dijkstra()
{
    priority_queue<pair<int,int>>pq;
    vector<int>dist(10001,INF);
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty())
    {
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])continue;
        //cout<<now<<" "<<cost<<endl;
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
    return dist[D];
}

int main()
{
    cin>>N>>D;
    while(N--)
    {
        int u,v,len;
        cin>>u>>v>>len;
        adj[u].push_back({v,len});
    }
    for(int i=0;i<D;i++)
    adj[i].push_back({i+1,1});
    cout<<dijkstra();
}
