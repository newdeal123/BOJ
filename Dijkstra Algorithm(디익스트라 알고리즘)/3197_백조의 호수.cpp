#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
const int INF=987654321;
int N,M;
int board[1500][1500],goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};
int dist[1500][1500];
bool visited[1500][1500];

bool is_in_board(int y,int x)
{
    if(y<0||y>=N||x<0||x>=M)return false;
    return true;
}

void bfs()
{
    queue<pair<int,int>>q;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        if(board[i][j]==0)
    {
        for(int k=0;k<4;k++)
        {
            int nextY=i+goY[k],nextX=j+goX[k];
            if(is_in_board(nextY,nextX)&&board[nextY][nextX]==1&&!visited[nextY][nextX])
                {
                    q.push({nextY,nextX});
                    visited[nextY][nextX]=true;
                }
        }
    }

    while(!q.empty())
    {
        pair<int,int>now=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nextY=now.first+goY[i],nextX=now.second+goX[i];
            if(is_in_board(nextY,nextX)&&board[nextY][nextX]==1&&!visited[nextY][nextX])
            {
                q.push({nextY,nextX});
                visited[nextY][nextX]=true;
                board[nextY][nextX]=board[now.first][now.second]+1;
            }
        }
    }
}

int dijkstra(pair<int,int>start,pair<int,int>fin)
{
    priority_queue<pair<int,pair<int,int>>>pq;
    for(int i=0;i<N;i++)
       for(int j=0;j<M;j++)dist[i][j]=INF;

    pq.push({0,{start.first,start.second}});
    dist[start.first][start.second]=0;

    while(!pq.empty())
    {
        int cost=-pq.top().first;
        pair<int,int>now=pq.top().second;
        pq.pop();
        if(now==fin)return cost;
        for(int i=0;i<4;i++)
        {
            int nextY=now.first+goY[i],nextX=now.second+goX[i];
            if(!is_in_board(nextY,nextX))continue;
            int nextDist=max(cost,board[nextY][nextX]);
            if(nextDist<dist[nextY][nextX])
            {
                dist[nextY][nextX]=nextDist;
                pq.push({-nextDist,{nextY,nextX}});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    vector<pair<int,int>>start;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<M;j++)
        {
            if(s[j]=='.')
                board[i][j]=0;
            else if(s[j]=='X') board[i][j]=1;
            else
            {
                start.push_back({i,j});
                board[i][j]=0;
            }
        }
    }
    bfs();
    //for(int i=0;i<N;i++,cout<<endl)
    //    for(int j=0;j<M;j++)cout<<board[i][j];

    cout<<dijkstra(start[0],start[1]);
}
