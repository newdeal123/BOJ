#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=10000+2;
int n,d,c;
vector<pair<int,int>> adj[MAX_N]; //node,cost

pair<int,int> dijkstra()
{
    pair<int,int> ret=make_pair(0,0);
    vector<int> dist(n+1,INF);
    dist[c]=0;
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(0,c));
    while(!pq.empty())
    {
        int now=pq.top().second,cost=-pq.top().first;
        pq.pop();
        if(dist[now]<cost) continue;
        for(auto i:adj[now])
        {
            int next=i.first,nextDist=i.second+cost;
            if(dist[next]>nextDist)
            {
                pq.push(make_pair(-nextDist,next));
                dist[next]=nextDist;
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(dist[i]!=INF)
        {
            ret.first++;
            ret.second=max(ret.second,dist[i]);
        }
    return ret;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<MAX_N;i++) adj[i].clear();
        cin>>n>>d>>c;
        while(d--)
        {
            int to,from,second;
            cin>>to>>from>>second;
            adj[from].push_back(make_pair(to,second));
        }
        pair<int,int> ans=dijkstra();
        cout<<ans.first<<" "<<ans.second<<"\n";
    }
}
