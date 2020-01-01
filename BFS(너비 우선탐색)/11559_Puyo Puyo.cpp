#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int goY[4]={0,0,1,-1};
int goX[4]={1,-1,0,0};
bool visited[13][7];

bool is_in_board(int y,int x)
{
    if(y<1||y>12||x<1||x>6)return false;
    return true;
}

int DFS(int board[][7],int y,int x)
{
    visited[y][x]=true;
    int ret=0;
    for(int i=0;i<4;i++)
    {
        int nextY=y+goY[i],nextX=x+goX[i];
        if(!is_in_board(y,x)||board[y][x]!=board[nextY][nextX]||visited[nextY][nextX])continue;
        ret+=DFS(board,nextY,nextX)+1;
    }
    return ret;
}

bool canCombo(int board[][7])
{
    for(int i=1;i<=12;i++)
        for(int j=1;j<=6;j++)
            if(board[i][j]!=0)
            {
                memset(visited,0,sizeof(visited));
                int ret=DFS(board,i,j);
                if(ret>=3)return true;
            }
    return false;
}

void boardErase(int board[][7],int y,int x)
{
    int targetN=board[y][x];
    queue<pair<int,int>>q;
    bool BFSvisited[13][7]={0,};
    q.push({y,x});
    BFSvisited[y][x]=true;
    board[y][x]=0;
    while(!q.empty())
    {
        int nowY=q.front().first,nowX=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(is_in_board(nextY,nextX)&&targetN==board[nextY][nextX]&&!BFSvisited[nextY][nextX])
            {
                BFSvisited[nextY][nextX]=true;
                q.push({nextY,nextX});
                board[nextY][nextX]=0;
            }
        }
    }
    return ;
}

void getCombo(int board[][7])
{
     for(int i=1;i<=12;i++)
        for(int j=1;j<=6;j++)
            {
                memset(visited,0,sizeof(visited));
                if(board[i][j]!=0 && DFS(board,i,j)>=3) boardErase(board,i,j);
            }

}

void Gravity(int board[][7],int y,int x)
{
    int nextY=y+1,nextX=x;
    if(!is_in_board(nextY,nextX)||board[nextY][nextX]!=0)return ;
    swap(board[y][x],board[nextY][nextX]);
    return Gravity(board,nextY,nextX);
}

int main()
{
    int board[13][7];
    for(int i=1;i<=12;i++)
        for(int j=1;j<=6;j++)
    {
        char c;
        cin>>c;
        if(c=='R')board[i][j]=1;
        else if(c=='G')board[i][j]=2;
        else if(c=='B')board[i][j]=3;
        else if(c=='P')board[i][j]=4;
        else if(c=='Y')board[i][j]=5;
        else board[i][j]=0;
    }
    int cnt=0;
    for(int i=12;i>=1;i--)
        for(int j=1;j<=6;j++)if(board[i][j]!=0)Gravity(board,i,j);

    while(canCombo(board))
    {
        cnt++;
        getCombo(board);
        for(int i=12;i>=1;i--)
            for(int j=1;j<=6;j++)if(board[i][j]!=0)Gravity(board,i,j);

        //for(int i=1;i<=12;i++,cout<<endl)
            //for(int j=1;j<=6;j++)cout<<board[i][j]<<" ";

    }
    cout<<cnt;
}
