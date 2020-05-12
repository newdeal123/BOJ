#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
const int INF=987654321,MAX_N=100+2,IMP=1e4;
int N,M,item[MAX_N];
vector<pair<int,int>>adj[MAX_N];

struct point{
    int time,items,node;
    point(){time=INF;}
    point(int t,int i,int n){time=t,items=i,node=node=n;}
};
bool operator <(point a,point b){
    if(a.time!=b.time)return a.time<b.time;
    else return a.items>b.items;
}

point dijkstra(int start,int fin)
{
    priority_queue<point>pq;
    vector<point>dist(N+1);
    for(int i=1;i<=N;i++)
        dist[i]=point(INF,0,i);
    dist[start]=point(0,item[start],start);
    pq.push(dist[start]);
    while(!pq.empty())
    {
        point now=pq.top();
        pq.pop();
        if(now.time>dist[now.node].time)continue;

        for(auto i:adj[now.node])
        {
            point next=point(now.time+i.second,now.items+item[i.first],i.first);
            if(next<dist[next.node])
            {
                dist[next.node]=next;
                pq.push(next);
            }
        }
    }
    return dist[fin];
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++)cin>>item[i];
    cin>>M;
    while(M--)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    point ans=dijkstra(1,N);
    if(ans.time==INF)cout<<"impossible";
    else cout<<ans.time<<" "<<ans.items;

}
