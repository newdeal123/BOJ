#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N,M,board[301][301];
int goY[2]={0,1};
int goX[2]={1,0};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M) return false;
    return true;
}

int BFS()
{
    queue<pair<int,int>>q;
    int visited[301][301]={0,};
    visited[1][1]=1;
    q.push(make_pair(1,1));
    while(!q.empty())
    {
        int nowY=q.front().first,nowX=q.front().second;
        q.pop();
        for(int i=0;i<2;i++)
        {
            for(int j=1;j<=board[nowY][nowX];j++)
            {
                int nextY=nowY+goY[i]*j,nextX=nowX+goX[i]*j;
                if(is_in_board(nextY,nextX)&&!visited[nextY][nextX])
                {
                    visited[nextY][nextX]=visited[nowY][nowX]+1;
                    q.push(make_pair(nextY,nextX));
                }
            }
        }
    }
    return visited[N][M]-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        cin>>board[i][j];
    cout<<BFS();
}
