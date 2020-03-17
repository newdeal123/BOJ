#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=300,MAX_V=MAX_N*2+2,INF=987654321;
int N,M,S=MAX_V-2,E=MAX_V-1,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int in(int num){return num*2;}
int out(int num){return num*2+1;}
int networkFlow(int source,int sink)
{
    memset(flow,0,sizeof(flow));
    int totalSum=0;
    while(true)
    {
        vector <int> parent(MAX_V,-1);
        queue <int> q;
        parent[source]=source;
        q.push(source);
        while(!q.empty()&&parent[sink]==-1)
        {
            int now=q.front();q.pop();
            for(auto next:adj[now])
            {
                if(capacity[now][next]-flow[now][next]>0 && parent[next]==-1)
                {
                    q.push(next);
                    parent[next]=now;
                }
            }
        }
        if(parent[sink]==-1) break;
        int sum=INF;
        for(int p=sink;p!=source;p=parent[p])
            sum=min(capacity[parent[p]][p]-flow[parent[p]][p],sum);
        for(int p=sink;p!=source;p=parent[p])
        {
            flow[parent[p]][p]+=sum;
            flow[p][parent[p]]-=sum;
        }
        totalSum+=sum;
    }
    return totalSum;
}

void connect(int u,int v,int c)
{
    capacity[u][v]+=c;
    capacity[v][u]+=c;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    memset(capacity,0,sizeof(capacity));
    memset(flow,0,sizeof(flow));
    for(int i=0;i<N;i++)connect(in(i),out(i),INF);
    while(M--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        u--,v--;
        connect(out(u),in(v),c);
        connect(out(v),in(u),c);
        capacity[in(v)][out(u)]-=c;
        capacity[in(u)][out(v)]-=c;
    }
    cout<<networkFlow(out(0),in(N-1));
}
