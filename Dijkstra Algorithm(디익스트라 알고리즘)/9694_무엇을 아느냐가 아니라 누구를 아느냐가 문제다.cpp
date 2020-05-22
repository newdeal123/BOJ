#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
const int INF=987654321,MAX_N=20+2;
int N,M;
vector<pair<int,int>>adj[MAX_N];
vector<int>parent;
int dijkstra()
{
    priority_queue<pair<int,int>>pq;
    vector<int>dist(N,INF);
    dist[0]=0;
    parent[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])continue;
        if(now==N-1)return cost;

        for(auto i:adj[now])
        {
            int next=i.first;
            int nextDist=i.second+cost;
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

void output(int now)
{
    if(parent[now]==now){cout<<"0 ";return ;}
    output(parent[now]);
    cout<<now<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int testCase=1;testCase<=t;testCase++)
    {
        cin>>M>>N;
        parent.resize(N);
        for(int i=0;i<MAX_N;i++)adj[i].clear();
        while(M--)
        {
            int u,v,cost;
            cin>>u>>v>>cost;
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
       int ans=dijkstra();
       cout<<"Case "<<"#"<<testCase<<": ";
       if(ans==-1)cout<<"-1";
       else output(N-1);

       cout<<"\n";
    }
}
