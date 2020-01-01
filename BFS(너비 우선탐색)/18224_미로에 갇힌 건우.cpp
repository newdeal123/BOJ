#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int N,M,board[501][501],goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};
int visited[501][501][2][11];

struct NODE
{
    int y,x;
    bool sun;
    int clock;
};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>N)return false;
    return true;
}

bool can_jump(int& y,int& x,int d)
{
    while(is_in_board(y,x))
    {
        y+=goY[d],x+=goX[d];
        if(board[y][x]==0)return true;
    }
    return false;
}

pair<int,int> bfs()
{
    queue<NODE>q;
    memset(visited,0,sizeof(visited));
    visited[1][1][1][1]=1;
    q.push({1,1,1,1});
    while(!q.empty())
    {
        int nowY=q.front().y,nowX=q.front().x;
        bool nowD=q.front().sun;
        int nowC=q.front().clock;
        q.pop();
        if(nowY==N&&nowX==N)return {visited[nowY][nowX][nowD][nowC],nowD};
        if(nowD)
        {
            for(int i=0;i<4;i++)
            {
                int nextY=nowY+goY[i],nextX=nowX+goX[i];
                bool nextD=((visited[nowY][nowX][nowD][nowC]%M==0)?0:1);
                int nextC=(nowC==M?1:nowC+1);
                if(board[nextY][nextX]==1||!is_in_board(nextY,nextX)||visited[nextY][nextX][nextD][nextC]) continue;
                visited[nextY][nextX][nextD][nextC]=visited[nowY][nowX][nowD][nowC]+1;
                q.push({nextY,nextX,nextD,nextC});
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                int nextY=nowY+goY[i],nextX=nowX+goX[i];
                bool nextD=((visited[nowY][nowX][nowD][nowC]%M==0)?1:0);
                int nextC=(nowC==M?1:nowC+1);
                if(!is_in_board(nextY,nextX)||visited[nextY][nextX][nextD][nextC])continue;
                if(board[nextY][nextX]==1&&!can_jump(nextY,nextX,i))continue;
                if(visited[nextY][nextX][nextD][nextC])continue;
                visited[nextY][nextX][nextD][nextC]=visited[nowY][nowX][nowD][nowC]+1;
                q.push({nextY,nextX,nextD,nextC});
            }
        }

    }
    return {-1,-1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)cin>>board[i][j];
    pair<int,int> ans=bfs();
    //cout<<ans<<"\n";
    if(ans.first!=-1)
    {
        int days=(ans.first-1)/(M*2)+1;
        cout<<days<<" "<<(ans.second==true ?"sun":"moon");
    }
    else cout<<-1;
}
