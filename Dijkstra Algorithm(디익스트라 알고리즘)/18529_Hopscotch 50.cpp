#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int INF=987654321;
const int MAX_N=2500+2;
int N,K,board[51][51];

int dijkstra()
{
    priority_queue<pair<int,pair<int,int>>>pq;
    int dist[51][51];
    for(int i=0;i<51;i++)
        for(int j=0;j<51;j++)dist[i][j]=INF;

     for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)if(board[i][j]==1){pq.push({0,{i,j}});dist[i][j]=0;}
    while(!pq.empty())
    {
        int nowY=pq.top().second.first;
        int nowX=pq.top().second.second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[nowY][nowX])continue;

        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            if(board[i][j]==board[nowY][nowX]+1)
            {
                int nextDist=cost+abs(i-nowY)+abs(j-nowX);
                if(dist[i][j]>nextDist)
                {
                    dist[i][j]=nextDist;
                    pq.push({-nextDist,{i,j}});
                }
            }

    }
    int ret=INF;
    for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)if(board[i][j]==K)ret=min(ret,dist[i][j]);
    return (ret==INF?-1:ret);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)cin>>board[i][j];
    cout<<dijkstra();
}
