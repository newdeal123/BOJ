#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
const int INF=987654321,MAX_N=1000+2;
int N,M,Q,board[MAX_N][MAX_N], dist[MAX_N][MAX_N];
int goY[8]={-1,-1,0,1,1,1,0,-1};
int goX[8]={0,1,1,1,0,-1,-1,-1};

bool is_in_board(pair<int,int>a)
{
    if(a.first<1||a.first>N||a.second<1||a.second>M)return false;
    return true;
}

int dijkstra(pair<int,int>start,pair<int,int>fin)
{
    priority_queue<pair<int,pair<int,int>>>pq;
    for(int i=0;i<MAX_N;i++)
        for(int j=0;j<MAX_N;j++)dist[i][j]=INF;
        
    dist[start.first][start.second]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int>now=pq.top().second;
        int cost=-pq.top().first;
        //cout<<cost<<" "<<now.first<<","<<now.second<<endl;
        pq.pop();
        if(cost>dist[now.first][now.second]) continue;
        if(now==fin)return cost;

        for(int i=0;i<8;i++)
        {
            pair<int,int>next=now;
            next.first+=goY[i],next.second+=goX[i];
            if(!is_in_board(next))continue;
            int nextDist=cost+(board[now.first][now.second]==i?0:1);
            if(nextDist<dist[next.first][next.second])
            {
                dist[next.first][next.second]=nextDist;
                pq.push({-nextDist,next});
            }
        }
    }
    return -1;
}

int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)scanf("%1d",&board[i][j]);
    cin>>Q;
    while(Q--)
    {
        int y,x,y2,x2;
        cin>>y>>x>>y2>>x2;
        cout<<dijkstra({y,x},{y2,x2})<<"\n";
    }
}
