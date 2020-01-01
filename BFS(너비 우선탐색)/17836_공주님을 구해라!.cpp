#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int INF=987654321;
int N,M,T,board[101][101];
const int goY[4]={0,0,1,-1};
const int goX[4]={1,-1,0,0};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M)return false;
    return true;
}

int BFS(int finY,int finX)
{
    int visited[101][101]={0,};
    queue<pair<int,int>>q;
    q.push({1,1});
    visited[1][1]=1;
    while(!q.empty())
    {
        int nowY=q.front().first,nowX=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(is_in_board(nextY,nextX)&&!visited[nextY][nextX]&&board[nextY][nextX]!=1)
            {
                visited[nextY][nextX]=visited[nowY][nowX]+1;
                q.push({nextY,nextX});
            }
        }
    }
    return (visited[finY][finX]==0 ? INF:visited[finY][finX]-1);
}

int main()
{
    int swordY,swordX;
    cin>>N>>M>>T;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            cin>>board[i][j];
            if(board[i][j]==2)swordY=i,swordX=j;
        }
    int minTime=min(BFS(swordY,swordX)+abs(N-swordY)+abs(M-swordX),BFS(N,M));
    if(minTime<=T)cout<<minTime;
    else cout<<"Fail";
}
