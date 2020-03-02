#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=200,MAX_V=MAX_N*2+2,INF=987654321;
int S=MAX_V-2,E=MAX_V-1,N,M,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V],cost[MAX_V][MAX_V];
vector<int>adj[MAX_V];

pair<int,int> networkFlow(int source,int sink)
{
    memset(flow,0,sizeof(flow));
    int totalSum=0,turn=0;
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
        turn++;
    }
    return {turn,totalSum};
}

struct LINE
{
    int y,x,dist,weight;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(capacity,0,sizeof(capacity));
        memset(flow,0,sizeof(flow));
        memset(cost,0,sizeof(cost));
        for(int i=0;i<MAX_V;i++)adj[i].clear();
        cin>>N>>M;
    vector<LINE>wid,len;
    for(int i=0;i<N;i++)
    {
        int x,y,x2,y2,w;
        cin>>x>>y>>x2>>y2>>w;
        wid.push_back({y,min(x,x2),abs(x-x2),w});
        capacity[S][i]=1;
        adj[S].push_back(i);
        adj[i].push_back(S);
    }
    for(int i=0;i<M;i++)
    {
        int x,y,x2,y2,w;
        cin>>x>>y>>x2>>y2>>w;
        len.push_back({min(y,y2),x,abs(y-y2),w});
        capacity[i+MAX_N][E]=1;
        adj[i+MAX_N].push_back(E);
        adj[E].push_back(i+MAX_N);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
    {
        if(wid[i].x<=len[j].x&&len[j].x<=wid[i].x+wid[i].dist &&
        len[j].y<=wid[i].y&&wid[i].y<=len[j].y+len[j].dist)
        {
            capacity[i][j+MAX_N]=1;
            adj[i].push_back(j+MAX_N);
            adj[j+MAX_N].push_back(i);
            cost[i][j+MAX_N]=-wid[i].weight*len[j].weight;
            cost[j+MAX_N][i]=-cost[i][j+MAX_N];
        }
    }
    pair<int,int>ans=networkFlow(S,E);
    cout<<ans.first<<" "<<-ans.second<<"\n";
    }
}
