#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=100+2,MAX_V=MAX_N*2+2,INF=987654321;
int S=MAX_N-2,E=MAX_N-1,N,M,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V],cost[MAX_V][MAX_V];
vector<int>adj[MAX_V];

int networkFlow(int source,int sink)
{
    memset(flow,0,sizeof(flow));
    int totalSum=0;
    while(true)
    {
        vector<int>parent(MAX_V,-1),dist(MAX_V,INF);
        bool inQ[MAX_V]={0,};
        queue<int>q;

        parent[source]=source;
        dist[source]=0;
        inQ[source]=true;
        q.push(source);

        while(!q.empty())
        {
            int now=q.front();q.pop();
            inQ[now]=false;
            for(auto next:adj[now])
            {
                if(capacity[now][next]-flow[now][next]>0 &&
                   dist[next]>dist[now]+cost[now][next])
                {
                    dist[next]=dist[now]+cost[now][next];
                    parent[next]=now;
                    if(!inQ[next])
                    {
                        inQ[next]=true;
                        q.push(next);
                    }
                }
            }
        }
        if(parent[sink]==-1) break;
        int sum=INF;
        for(int p=sink;p!=source;p=parent[p])
            sum=min(capacity[parent[p]][p]-flow[parent[p]][p],sum);
        for(int p=sink;p!=source;p=parent[p])
        {
            totalSum+=sum*cost[parent[p]][p];
            flow[parent[p]][p]+=sum;
            flow[p][parent[p]]-=sum;
        }
    }
    return totalSum;
}

void connect(int u,int v,int c,int cap)
{
    capacity[u][v]=cap;
    cost[u][v]=c;
    cost[v][u]=-c;
    adj[v].push_back(u);
    adj[u].push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    memset(capacity,0,sizeof(capacity));
    memset(flow,0,sizeof(flow));

    for(int i=0;i<N;i++)connect(S,i,0,1);
    for(int i=MAX_N;i<MAX_N+N;i++)connect(i,E,0,1);

    for(int u=0;u<N;u++)
        for(int v=MAX_N;v<MAX_N+N;v++)
    {
        cin>>cost[u][v];
        connect(u,v,cost[u][v],1);
    }
    cout<<networkFlow(S,E);
}
