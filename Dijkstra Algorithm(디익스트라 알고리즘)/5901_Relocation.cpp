#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
const int INF=987654321,MAX_N=10000+2;
int N,M,K,ans=INF,market[5];
vector<pair<int,int>>adj[MAX_N];


vector<int> dijktra(int start)
{
    priority_queue<pair<int,int>>pq;
    vector<int>dist(MAX_N,INF);
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty())
    {
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])continue;
        for(auto i:adj[now])
        {
            int next=i.first;
            int nextDist=cost+i.second;
            if(nextDist<dist[next])
            {
                dist[next]=nextDist;
                pq.push({-nextDist,next});
            }
        }
    }
    return dist;
}

int main()
{
    cin>>N>>M>>K;
    for(int i=0;i<K;i++)cin>>market[i];
    while(M--)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    vector<vector<int>>marketTotown;
    for(int i=0;i<K;i++)
        marketTotown.push_back(dijktra(market[i]));
    vector<int>order;
    for(int i=0;i<K;i++)order.push_back(i);
    do
    {
        int sum=0;
        for(int i=0;i<K-1;i++)
        {
            int u=order[i],v=order[i+1];
            sum+=marketTotown[u][market[v]];
        }
        //find start
        for(int i=1;i<=N;i++)
        {
            bool isMarket=false;
            for(int j=0;j<K;j++)if(i==market[j])isMarket=true;
            if(isMarket)continue;

            ans=min(ans,sum+marketTotown[order.front()][i]+marketTotown[order.back()][i]);
        }
    }while(next_permutation(order.begin(),order.end()));
    cout<<ans;
}
