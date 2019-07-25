#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1000+2;
bool board[MAX_N][MAX_N];
int goY[5] = { 0,-1,1,0,0 };
int goX[5] = { 0,0,0,-1,1 };
int state[4],cnt=0;
int r, c, k;

bool is_in_board(int y,int x)
{
    if(y<1||y>r||x<1||x>c) return false;
    return true;
}
int main()
{
    cin>>r>>c>>k;
    memset(board,true,sizeof(board));

    while (k--)
    {
        int y, x;
        cin>>y>>x;
        board[++y][++x] = false;
    }

    int nowY, nowX;
    cin>>nowY>>nowX;
    nowY++; nowX++;

    for(int i=0;i<4;i++)
        cin>>state[i];

    bool move = true;
    while (move)
    {
        int nextY, nextX;
        move = false;

        for (int i = 0; i < 4; i++)
        {
            nextY = nowY + goY[state[(cnt+i)%4]]; nextX = nowX + goX[state[(cnt+ i)%4]];
            if (is_in_board(nextY,nextX) && board[nextY][nextX])
            {
                cnt = (cnt + i) % 4;
                board[nowY][nowX] = false;
                nowY = nextY; nowX = nextX;
                move = true;
                break;
            }
        }
    }

   cout<<--nowY<<" "<<--nowX;
    return 0;
}
