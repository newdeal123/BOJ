#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
const int INF=987654321,MAX_N=2000+2;
int N,Q,A[MAX_N],cache[MAX_N];

void dijkstra(int start)
{
    priority_queue<pair<int,int>>pq;
    vector<int>dist(N,INF);
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])continue;

        for(int i=0;i<N;i++)
        {
            int next=i,nextDist=INF;
            if(now!=i)
            {
                if(now>next&&A[now-next])nextDist=cost+A[now-next];
                if(next>now&&A[N+now-next])nextDist=cost+A[N+now-next];
            }
            if(nextDist<dist[next])
            {
                dist[next]=nextDist;
                pq.push({-nextDist,next});
            }
        }
    }
    for(int i=1;i<N;i++)cache[N-i]=(dist[i]==INF?-1:dist[i]);
    return ;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<N;i++)cin>>A[i];
    dijkstra(0);
    cin>>Q;
    //for(int i=1;i<N;i++)cout<<"cache"<<i<<"="<<cache[i]<<endl;
    while(Q--)
    {
        int u,v;
        cin>>u>>v;
        if(u>v)cout<<cache[u-v]<<"\n";
        else cout<<cache[N+u-v]<<"\n";
    }

}
