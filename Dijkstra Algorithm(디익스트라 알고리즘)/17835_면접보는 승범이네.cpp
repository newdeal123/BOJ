#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
typedef long long ll;
const int MAX_N=100000+2;
const ll INF=LONG_MAX-100;
int N,M,K;
vector<pair<ll,ll>>adj[MAX_N];
vector<int>target;

pair<ll,ll> dijkstra()
{
    priority_queue<pair<ll,ll>>pq;
    vector<ll>dist(N+1,INF);
    for(auto i:target)
    {
        pq.push({0,i});
        dist[i]=0;
    }
    while(!pq.empty())
    {
        ll now=pq.top().second,cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])continue;
        for(auto i:adj[now])
        {
            ll next=i.first,nextDist=cost+i.second;
            if(nextDist<dist[next])
            {
                pq.push({-nextDist,next});
                dist[next]=nextDist;
            }
        }
    }
    ll ans=-1,city=INF;
    for(int i=1;i<=N;i++)
    {
        if(ans<dist[i])ans=dist[i],city=i;
        else if(ans==dist[i])city=min(city,(ll)i);
    }

    return make_pair(city,ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>K;
    for(int i=0;i<M;i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        adj[v].push_back({u,c});
    }
    target.resize(K);
    for(auto &i:target)cin>>i;
    pair<ll,ll>ans=dijkstra();
    cout<<ans.first<<endl<<ans.second;
}
