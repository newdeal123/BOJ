#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=1000+2,MAX_V=MAX_N*2+2,INF=(int)1e9+2;
int S=MAX_N-2,E=MAX_N-1,N,M,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V],cost[MAX_V][MAX_V];
vector<int>adj[MAX_V];

int in(int num){return num*2;}
int out(int num){return num*2+1;}

int networkFlow(int source,int sink)
{
    int totalSum=0;
    while(true)
    {
        vector<int>parent(MAX_V,-1),dist(MAX_V,INF);
        bool inQ[MAX_V]={0,};
        queue<int>q;

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
    capacity[v][u]=cap;
    cost[u][v]=c;
    cost[v][u]=-c;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    memset(capacity,0,sizeof(capacity));
    memset(cost,0,sizeof(cost));
    memset(flow,0,sizeof(flow));
    for(int i=0;i<N;i++)
        connect(in(i),out(i),0,INF);
    connect(out(S),in(0),0,2);
    connect(out(N-1),in(E),0,2);
    while(M--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        u--,v--;
        connect(out(u),in(v),c,1);
        connect(out(v),in(u),c,1);
        capacity[in(v)][out(u)]=0;
        capacity[in(u)][out(v)]=0;
    }
    cout<<networkFlow(out(S),in(E));

}
