#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N=100+2,INF=9876543;
vector<pair<int,double>>adj[MAX_N];
int N,M;

double dijkstra(int start,int fin)
{
    vector<double>dist(N+1,0);
    priority_queue<pair<double,int>>pq;
    pq.push({1,start});
    dist[start]=1;
    while(!pq.empty())
    {
        int now=pq.top().second;
        double cost=pq.top().first;
        pq.pop();
        if(cost<dist[now])continue;
        if(now==fin)return cost;

        for(auto i:adj[now])
        {
            int next=i.first;
            double nextDist=i.second*cost;
            if(nextDist>dist[next])
            {
                dist[next]=nextDist;
                pq.push({nextDist,next});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    cout<<fixed;
    cout.precision(4);
    for(int tc=1;tc<=t;tc++)
    {
        for(int i=0;i<MAX_N;i++)adj[i].clear();
        int start,fin;
        cin>>N>>start>>fin>>M;
        while(M--)
        {
            int u,v;
            double dist;
            cin>>u>>v>>dist;
            adj[u].push_back({v,dist});
        }
        cout<<"Case "<<tc<<": "<<dijkstra(start,fin)<<"\n";
    }
}
