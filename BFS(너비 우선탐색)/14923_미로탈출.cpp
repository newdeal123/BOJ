#include <iostream>
#include <queue>
using namespace std;
const int MAX_N=1000+2;
int N,M,startY,startX,finY,finX,board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N][2]={0,};
int goY[4]={0,0,1,-1};
int goX[4]={1,-1,0,0};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>M)return false;
    return true;
}

int BFS()
{
    queue<pair<pair<int,int>,bool>> q;
    q.push(make_pair(make_pair(startY,startX),0));
    visited[startY][startX][0]=1;
    while(!q.empty())
    {
        int nowY=q.front().first.first,nowX=q.front().first.second;
        //cout<<nowY<<" "<<nowX<<endl;
        bool used=q.front().second;
        q.pop();
        if(nowY==finY && nowX==finX) return visited[nowY][nowX][used]-1;
        for(int i=0;i<4;i++)
        {
            int nextY=nowY+goY[i],nextX=nowX+goX[i];
            if(is_in_board(nextY,nextX) && board[nextY][nextX]!=1 && !visited[nextY][nextX][used])
            {
                visited[nextY][nextX][used]=visited[nowY][nowX][used]+1;
                q.push(make_pair(make_pair(nextY,nextX),used));
            }
            if(is_in_board(nextY,nextX) && board[nextY][nextX]==1 &&!used && !visited[nextY][nextX][!used])
            {
                visited[nextY][nextX][!used]=visited[nowY][nowX][used]+1;
                q.push(make_pair(make_pair(nextY,nextX),!used));
            }

        }

    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M>>startY>>startX>>finY>>finX;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>board[i][j];
    cout<<BFS();
}
