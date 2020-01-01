#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int IMP=(int)1e6,INF=987654321;
int N,M;
vector<vector<pair<int,int>>>adj;
bool same_comp[1000+2];

int dijkstra()
{
    vector<int>dis(N+1,INF);
    dis[0]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,0});

    while(!pq.empty())
    {
        int cost=-pq.top().first,now=pq.top().second;
        pq.pop();
        if(cost>dis[now]) continue;
        for(auto i:adj[now])
        {
            int next=i.first,nextDist=i.second+cost;
            if(nextDist<dis[next])
            {
                dis[next]=nextDist;
                pq.push({-nextDist,next});
            }
        }
    }
    return dis[M];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    adj.resize(N);
    for(int i=0;i<N;i++)cin>>same_comp[i];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            int tmp;
            cin>>tmp;
            if(tmp)
            {
                if(same_comp[i]==same_comp[j])
                    adj[i].push_back({j,tmp});
                else adj[i].push_back({j,tmp+IMP});
            }
        }

    int ans=dijkstra();
    cout<<ans/IMP<<" "<<ans%IMP;

}
