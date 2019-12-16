#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
const int MAX_N=100000+2;
int N,M;
vector<pair<int,ll>>adj[MAX_N];
bool canTgo[MAX_N]={0,};

ll dijkstra()
{
    priority_queue <pair<ll,int>> pq;
    vector <ll> dist(N+1,LLONG_MAX-100);
    dist[0]=0;
    pq.push(make_pair(0,0));
    while(!pq.empty())
    {
        ll Pcost=-pq.top().first;
        int now=pq.top().second;
        pq.pop();
        if(Pcost>dist[now]) continue;
        for(auto j:adj[now])
        {
            int next=j.first,nCost=j.second;
            if(canTgo[next])continue;
            if(Pcost+nCost<dist[next])
            {
                dist[next]=Pcost+nCost;
                pq.push(make_pair(-dist[next],next));
            }
        }
    }
    return (dist[N-1]==LLONG_MAX-100 ? -1:dist[N-1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++)cin>>canTgo[i];
    canTgo[N-1]=false;
    while(M--)
    {
        int u,v;
        ll cost;
        cin>>u>>v>>cost;
        adj[u].push_back(make_pair(v,cost));
        adj[v].push_back(make_pair(u,cost));
    }
    cout<<dijkstra();
}
