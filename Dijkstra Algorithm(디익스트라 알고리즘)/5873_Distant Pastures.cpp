#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
const int INF=987654321,MAX_N=30+2;
int N,A,B,goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};
char board[MAX_N][MAX_N];

bool is_in_board(pair<int,int>a)
{
    if(a.first<1||a.first>N||a.second<1||a.second>N)return false;
    return true;
}

int dijktra(pair<int,int>start)
{
    int ret=0;
    priority_queue<pair<int,pair<int,int>>>pq;
    int dist[MAX_N][MAX_N];
    for(int i=0;i<MAX_N;i++)
        for(int j=0;j<MAX_N;j++)dist[i][j]=INF;
    pq.push({0,start});
    dist[start.first][start.second]=0;
    while(!pq.empty())
    {
        pair<int,int>now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now.first][now.second])continue;

        for(int i=0;i<4;i++)
        {
            pair<int,int>next=now;
            next.first+=goY[i],next.second+=goX[i];
            if(!is_in_board(next))continue;
            int nextDist=cost+(board[now.first][now.second]==board[next.first][next.second]?A:B);
            if(nextDist<dist[next.first][next.second])
            {
                dist[next.first][next.second]=nextDist;
                pq.push({-nextDist,next});
            }
        }
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)if(dist[i][j]!=INF)ret=max(ret,dist[i][j]);
    return ret;
}

int main()
{
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=N;j++)board[i][j]=s[j-1];
    }
    int ans=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
        {
            int d=dijktra({i,j});
            if(d!=INF)ans=max(ans,d);
        }
    cout<<ans;
}
