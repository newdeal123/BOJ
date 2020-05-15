#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
int N,M;
const int INF=987654321;
vector<pair<int,int>>adj[201];

vector<int>dijksta(int start)
{
    vector<int>dist(N+1,INF),parent(N+1);
    priority_queue <pair<int,int>>pq;
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty())
    {
        int cost=-pq.top().first,now=pq.top().second;
        pq.pop();
        if(cost>dist[now])continue;

        for(auto i:adj[now])
        {
            int next=i.first,nextDist=cost+i.second;
            if(nextDist<dist[next])
            {
                dist[next]=nextDist;
                parent[next]=now;
                pq.push({-nextDist,next});
            }
        }

    }
    return parent;
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
    for(int i=1;i<=N;i++)
    {
        vector<int>parent=dijksta(i);
        for(int j=1;j<=N;j++)
        {
            if(i==j)cout<<"- ";
            else
            {
                int p=j;
                while(parent[p]!=i)
                {
                    p=parent[p];
                }
                cout<<p<<" ";
            }
        }
        cout<<"\n";
    }
}
