#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
const int INF=987654321;
const int MAX_N=2500+2;
int N,W;
double M;
pair<int,int>loc[1001];
vector<int>adj[1001];

int dijkstra()
{
    priority_queue<pair<double,int>>pq;
    vector<double>dist(N+1,INF);
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        int now=pq.top().second;
        double cost=-pq.top().first;
        //cout<<now<<" "<<cost<<endl;
        pq.pop();
        for(auto next:adj[now])
        {
            double nextDist=cost;
            if(nextDist<dist[next])
            {
                dist[next]=nextDist;
                pq.push({-nextDist,next});
            }
        }
            for(int i=1;i<=N;i++)
            {
                double nextDist=sqrt(pow(loc[now].first-loc[i].first,2)+pow(loc[now].second-loc[i].second,2));
                if(nextDist>M)continue;
                nextDist+=cost;
                if(nextDist<dist[i])
                {
                    dist[i]=nextDist;
                    pq.push({-nextDist,i});
                }
            }

    }
    return dist[N]*1000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>W>>M;
    for(int i=1;i<=N;i++)
    {
        int x,y;
        cin>>x>>y;
        loc[i]={x,y};
    }
    while(W--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<dijkstra();
}
