#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=500+10,MAX_V=MAX_N+2,INF=987654321,IMP=(int)1e6;
int S=MAX_V-10,E=MAX_V-9,K=MAX_V-8,N,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V],cost[MAX_V][MAX_V];
int node[4]={MAX_V-7,MAX_V-6,MAX_V-5,MAX_V-4};
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
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<3;i++)
    {
        int c;
        cin>>c;
        connect(S,node[i],0,c-1);
        connect(K,node[i],0,1);
    }
    connect(S,K,-IMP,3);
    connect(S,node[3],0,INF);
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<3;j++)
            {
                int c;
                cin>>c;
                connect(node[j],i,-c,1);
            }
            connect(node[3],i,0,1);
            connect(i,E,0,1);
        }
    cout<<-networkFlow(S,E)-3*IMP;
}
