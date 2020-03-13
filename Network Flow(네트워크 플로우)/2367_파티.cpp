#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=200,MAX_V=MAX_N*2+2,INF=987654321;
int N,K,D,S=MAX_V-2,E=MAX_V-1,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

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
    capacity[u][v]=c;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>K>>D;
    memset(capacity,0,sizeof(capacity));
    memset(flow,0,sizeof(flow));
    for(int i=MAX_N;i<MAX_N+D;i++)
    {
        int c;
        cin>>c;
        connect(i,E,c);
    }
    for(int u=0;u<N;u++)
    {
        int cnt;
        cin>>cnt;
        while(cnt--)
        {
            int v;
            cin>>v;
            v=MAX_N+v-1;
            connect(u,v,1);
        }
    }
    for(int i=0;i<N;i++)connect(S,i,K);
    cout<<networkFlow(S,E);
}
