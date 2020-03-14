#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF=987654321;
int N,cost[1001];
int dist[1001][251];

int dijkstra()
{
    for(int i=0;i<1001;i++)
        for(int j=0;j<251;j++)dist[i][j]=INF;
    priority_queue<pair<int,pair<int,int>>>pq;
    dist[1][0]=0;
    pq.push({0,{1,0}});
    while(!pq.empty())
    {
        int nowDist=-pq.top().first;
        int now=pq.top().second.first,lastJump=pq.top().second.second;
        pq.pop();
        //cout<<nowDist<<" "<<now<<"\n";
        if(dist[now][lastJump]<nowDist)continue;
        int next=now+lastJump+1,nextJump=lastJump+1;
        if(next>=1&&next<=N)
        {
            int nextDist=nowDist+cost[next];
            if(nextDist<=dist[next][nextJump])
            {
                pq.push({-nextDist,{next,nextJump}});
                dist[next][nextJump]=nextDist;
            }
        }
        next=now-lastJump,nextJump=lastJump;
        if(next>=1&&next<=N)
        {
            int nextDist=nowDist+cost[next];
            if(nextDist<=dist[next][nextJump])
            {
                pq.push({-nextDist,{next,nextJump}});
                dist[next][nextJump]=nextDist;
            }
        }
    }
    int ret=INF;
    for(int i=0;i<1001;i++)ret=min(ret,dist[N][i]);
    return ret;
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)cin>>cost[i];
    cout<<dijkstra();
}
