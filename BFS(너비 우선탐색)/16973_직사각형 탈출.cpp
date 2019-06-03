#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=1000+2;
int N,M,H,W,board[MAX_N][MAX_N],visited[MAX_N][MAX_N]={0,};
int startY,startX,finY,finX;
int goY[4]={0,0,1,-1};
int goX[4]={1,-1,0,0};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M) return false;
    return true;
}

bool is_possible(int y,int x,int state)
{
    for(int i=0;i<H;i++)
    {
        int nextY=y+i+goY[state],nextX=x+goX[state];
        if(!is_in_board(nextY,nextX)|| board[nextY][nextX])return false;
        nextY=y+i+goY[state],nextX=x+W-1+goX[state];
        if(!is_in_board(nextY,nextX)|| board[nextY][nextX])return false;
    }
     for(int i=0;i<W;i++)
    {
        int nextY=y+goY[state],nextX=x+i+goX[state];
        if(!is_in_board(nextY,nextX)|| board[nextY][nextX])return false;
        nextY=y+H-1+goY[state],nextX=x+i+goX[state];
        if(!is_in_board(nextY,nextX)|| board[nextY][nextX])return false;
    }
    return true;
}

int bfs()
{
    queue <pair<int,int>> q;
    q.push(make_pair(startY,startX));
    visited[startY][startX]=1;
    while(!q.empty())
    {
        int nowY=q.front().first,nowX=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(visited[nextY][nextX] || !is_possible(nowY,nowX,i)) continue;
            visited[nextY][nextX]=visited[nowY][nowX]+1;
            q.push(make_pair(nextY,nextX));
        }
    }
    return visited[finY][finX]==0?INF:visited[finY][finX]-1;
}

int main()
{
    cin >>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        cin >> board[i][j];
    cin >> H>>W>>startY>>startX>>finY>>finX;
    int ret=bfs();
    if(ret == INF) cout <<-1;
    else cout <<ret;
}
