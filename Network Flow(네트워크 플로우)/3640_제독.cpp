#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=1000,MAX_V=MAX_N*2+2,INF=987654321;
int N,M,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V],cost[MAX_V][MAX_V];
vector<int>adj[MAX_V];

int in(int n){return n*2;}
int out(int n){return n*2+1;}

int networkFlow(int source,int sink)
{
    memset(flow,0,sizeof(flow));
    int totalSum=0,circle=0;
    while(circle!=2)
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
        for(int p=sink;p!=source;p=parent[p])
        {
            totalSum+=cost[parent[p]][p];
            flow[parent[p]][p]++;
            flow[p][parent[p]]--;
        }
        //cout<<sum<<","<<totalSum<<"\n";
        circle++;
    }
    return totalSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>N>>M)
    {
        memset(capacity,0,sizeof(capacity));
        memset(cost,0,sizeof(cost));
        memset(flow,0,sizeof(flow));
        for(int i=0;i<MAX_V;i++)adj[i].clear();
        for(int i=0;i<N;i++)
    {
        capacity[in(i)][out(i)]=1;
        capacity[out(i)][in(i)]=1;
        adj[in(i)].push_back(out(i));
        adj[out(i)].push_back(in(i));
    }
    while(M--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a=out(a-1),b=in(b-1);
        cost[a][b]=c;
        cost[b][a]=-c;
        capacity[a][b]=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cout<<networkFlow(out(0),in(N-1))<<"\n";
    }
    
}
