#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
int N,M,A,B,K,G;
pair<int,int> king[1001][1001];
vector<pair<int,int>>adj[1001];

int dijkstra()
{
    int dist[1001];
    for(int i=0;i<1001;i++) dist[i]=INF;
    dist[A]=0;
    priority_queue< pair<int,pair<int,int>>> pq;
    pq.push(make_pair(0,make_pair(A,K)));
    while(!pq.empty())
    {
        int cost=-pq.top().first;
        int now=pq.top().second.first;
        int time=pq.top().second.second;
        pq.pop();
        if(cost>dist[now]) continue;
        for(auto i:adj[now])
        {
            int next=i.first,nextDist=i.second+cost;
            if(king[now][next].first<=time && time<king[now][next].second)
                nextDist+=king[now][next].second-time;
            if(dist[next]>nextDist)
            {
                dist[next]=nextDist;
                pq.push(make_pair(-nextDist,make_pair(next,K+nextDist)));
            }
        }
    }
    //for(int i=1;i<=N;i++)cout<<i<<"="<<dist[i]<<endl;
    return dist[B];
}

int main()
{

    cin>>N>>M>>A>>B>>K>>G;
    vector<int>v(G);
    for(int i=0;i<G;i++)cin>>v[i];
    while(M--)
    {
        int a,b,dist;
        cin>>a>>b>>dist;
        adj[a].push_back(make_pair(b,dist));
        adj[b].push_back(make_pair(a,dist));
    }
    int time=0;
    for(int i=1;i<v.size();i++)
    {
        int dist;
        for(auto j:adj[v[i]])
            if(j.first==v[i-1]) dist=j.second;
        king[v[i]][v[i-1]]=make_pair(time,time+dist);
        king[v[i-1]][v[i]]=make_pair(time,time+dist);
        time+=dist;
    }
    cout<<dijkstra();
}
