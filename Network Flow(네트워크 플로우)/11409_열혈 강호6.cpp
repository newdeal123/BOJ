#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=400,MAX_V=MAX_N*2+2,INF=987654321;
int S=MAX_V-2,E=MAX_V-1,N,M,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V],cost[MAX_V][MAX_V];
vector<int>adj[MAX_V];

pair<int,int> networkFlow(int source,int sink)
{
    memset(flow,0,sizeof(flow));
    int work=0,totalSum=0;
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
           // cout<<"now:"<<now<<endl;
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
        work++;
    }
    return {work,totalSum};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        capacity[S][i]=1;
        adj[S].push_back(i);
        adj[i].push_back(S);
    }
    for(int i=MAX_N;i<MAX_N+M;i++)
    {
        capacity[i][E]=1;
        adj[i].push_back(E);
        adj[E].push_back(i);
    }
    for(int i=0;i<N;i++)
    {
        int t;
        cin>>t;
        while(t--)
        {
            int idx,c;
            cin>>idx>>c;
            idx=MAX_N+idx-1;
            c=-c;
            cost[i][idx]=c;
            cost[idx][i]=-c;
            capacity[i][idx]=INF;
            adj[i].push_back(idx);
            adj[idx].push_back(i);
        }
    }
    pair<int,int> ans=networkFlow(S,E);
    cout<<ans.first<<"\n"<<-ans.second;
}
