#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=50+2;
int N,M;
char board[MAX_N][MAX_N];
int goY[4]={0,0,1,-1};
int goX[4]={1,-1,0,0};

struct Player
{
    int y,x,bits;
};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M) return false;
    return true;
}

int BFS(int startY,int startX)
{
    int ans=INF;
    int visited[MAX_N][MAX_N][(1<<6)]={0,};
    queue<Player>q;
    q.push({startY,startX,0});
    visited[startY][startX][0]=1;
    while(!q.empty())
    {
        int nowY=q.front().y,nowX=q.front().x,nowBits=q.front().bits;
        q.pop();
        if(board[nowY][nowX]=='1')  ans=min(ans,visited[nowY][nowX][nowBits]-1);
        for(int i=0;i<4;i++)
        {
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(!is_in_board(nextY,nextX) || board[nextY][nextX]=='#') continue;
            if(board[nextY][nextX]>='A' && board[nextY][nextX]<='F' && !(nowBits&(1<< board[nextY][nextX]-'A'))) continue;
            if(board[nextY][nextX]>='a'&& board[nextY][nextX]<='f' && !visited[nextY][nextX][nowBits|(1<< board[nextY][nextX]-'a')])
            {
                visited[nextY][nextX][nowBits|(1<< board[nextY][nextX]-'a')]=visited[nowY][nowX][nowBits]+1;
                q.push({nextY,nextX,nowBits|(1<< board[nextY][nextX]-'a')});
            }
            else if(!visited[nextY][nextX][nowBits])
            {
                visited[nextY][nextX][nowBits]=visited[nowY][nowX][nowBits]+1;
                q.push({nextY,nextX,nowBits});
            }

        }
    }
    return (ans==INF ? -1 : ans);
}

int main()
{
    int startY,startX;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            {
                cin>>board[i][j];
                if(board[i][j]=='0') startY=i,startX=j;
            }
    cout<<BFS(startY,startX);
}
