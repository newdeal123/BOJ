#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int goY[4]={0,0,1,-1},goX[4]={1,-1,0,0};
int N,M;
char board[21][21];

struct POINT
{
    int y1,x1,y2,x2;
};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M)return false;
    return true;
}

int BFS(POINT start)
{
    queue<POINT>q;
    int visited[21][21][21][21];
    visited[start.y1][start.x1][start.y2][start.x2]=1;
    q.push(start);
    while(!q.empty())
    {
        POINT now=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            POINT next={now.y1+goY[i],now.x1+goX[i],now.y2+goY[i],now.x2+goX[i]};
            if(board[next.y1][next.x1]=='#')next.y1=now.y1,next.x1=now.x1;
            if(board[next.y2][next.x2]=='#')next.y2=now.y2,next.x2=now.x2;
            //cout<<next.y1<<","<<next.x1<<"   "<<next.y2<<","<<next.x2<<endl;
            if(!is_in_board(next.y1,next.x1)&&!is_in_board(next.y2,next.x2)) continue;
            if(visited[next.y1][next.x1][next.y2][next.x2]) continue;
            if(is_in_board(next.y1,next.x1)+is_in_board(next.y2,next.x2)==1)
                return visited[now.y1][now.x1][now.y2][now.x2];
            visited[next.y1][next.x1][next.y2][next.x2]=visited[now.y1][now.x1][now.y2][now.x2]+1;
            q.push(next);

        }
    }
    return -1;

}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    bool first=true;
    pair<int,int>x,y;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='o')
            {
                if(first){first=false,x={i,j};}
                else y={i,j};
            }
        }
    cout<<BFS({x.first,x.second,y.first,y.second});
}
