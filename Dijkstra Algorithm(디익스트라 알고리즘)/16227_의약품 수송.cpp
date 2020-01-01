#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int INF=987654321;
int N,K;
vector<pair<int,int>>adj[1002];

int dijkstra()
{
    int dist[1002][101];
    for(int i=0;i<1002;i++)
        for(int j=0;j<101;j++)dist[i][j]=INF;
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{0,0}});
    dist[0][0]=0;
    while(!pq.empty())
    {
        int nowD=-pq.top().first,now=pq.top().second.first,nowT=pq.top().second.second;
        pq.pop();
        if(nowD>dist[now][nowT])continue;
        if(now==N+1)return nowD;
        for(auto i:adj[now])
        {
            int next=i.first,nextT=i.second;
            //그냥 가는거
            if(nextT+nowT<=100&&dist[next][nextT+nowT]>nowD+nextT)
            {
                dist[next][nextT+nowT]=nowD+nextT;
                pq.push({-(nowD+nextT),{next,nextT+nowT}});
            }
            //씻고 가는거
            if(nextT<=100&&dist[next][nextT]>nowD+nextT+5)
            {
                dist[next][nextT]=nowD+nextT+5;
                pq.push({-(nowD+nextT+5),{next,nextT}});
            }

        }
    }
}

int main()
{
    cin>>N>>K;
    while(K--)
    {
        int u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    cout<<dijkstra();
}
