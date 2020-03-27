#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=200+2,MAX_V=MAX_N*2+2,INF=987654321;
int N,M,S,E,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int in(int n){return n*2;}
int out(int n){return n*2+1;}
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

void connect(int u,int v,int cap)
{
    capacity[u][v]=cap;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(flow,0,sizeof(flow));
        memset(capacity,0,sizeof(capacity));
        for(int i=0;i<MAX_V;i++)adj[i].clear();
        cin>>N>>M;
        S=0,E=N-1;
        while(M--)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            if(u==0||v==N-1)
                connect(out(u),in(v),1);
            else
                connect(out(u),in(v),INF);
        }
        connect(out(S),in(0),INF);
        connect(out(N-1),in(E),INF);
        for(int i=0;i<N;i++)
        {
            connect(out(i),in(i),INF);
            connect(in(i),out(i),INF);
        }
        cout<<networkFlow(out(S),in(E))<<"\n";
    }
}
