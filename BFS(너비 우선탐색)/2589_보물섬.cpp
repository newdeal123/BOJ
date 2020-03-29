#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,M,board[51][51]={0,};
int goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M)return false;
    return true;
}

int bfs(int y,int x)
{
    queue<pair<int,int>>q;
    int visited[51][51]={0,};
    q.push({y,x});
    visited[y][x]=1;
    while(!q.empty())
    {
        int nowY=q.front().first,nowX=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(is_in_board(nextY,nextX)&&board[nextY][nextX]==1&&!visited[nextY][nextX])
            {
                q.push({nextY,nextX});
                visited[nextY][nextX]=visited[nowY][nowX]+1;
            }
        }

    }

    int maxN=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)maxN=max(maxN,visited[i][j]);
    return maxN;
}

int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
    {
        char c;
        cin>>c;
        if(c=='L')board[i][j]=1;
    }
    int ret=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)if(board[i][j]==1)ret=max(ret,bfs(i,j));
    cout<<ret-1;
}
