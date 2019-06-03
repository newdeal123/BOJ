#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
const int MAX_N = 50 + 2;
int N, M, board[MAX_N][MAX_N];
int goY[4] = { -1,0,1,0 };
int goX[4] = { 0,-1,0,1 };
string order[8] = { "FORWARD" ,"BACKWARD" ,"RIGHT" ,"LEFT","STOP","FASTER", "SLOWER" ,"NOOB" };

struct CAR
{
    int y, x, direct, speed;
};

void Order(CAR& c, string s)
{
    if (s == "FORWARD")
        if (c.speed == 0)c.speed = 1;
    if (s == "BACKWARD")
        if (c.speed == 0)c.speed = -1;
    if (s == "RIGHT")
        if (c.speed == 0)c.direct = (c.direct + 1) % 4;
    if (s == "LEFT")
        if (c.speed == 0)c.direct = (c.direct + 3) % 4;
    if (s == "STOP")
        c.speed = 0;
    if (s == "FASTER")
        if (c.speed>0) c.speed = min(5, c.speed + 1);
    if (s == "SLOWER")
        if (c.speed>0) c.speed -= 1;
    c.y = c.y + goY[c.direct] * c.speed, c.x = c.x + goX[c.direct] * c.speed;
}

bool is_in_board(int y, int x)
{
    if (y<1 || y>N || x<1 || x>M) return false;
    return true;
}

bool can_go(int y,int x,int y2,int x2)
{
    if(y>y2) swap(y,y2);
    if(x>x2) swap(x,x2);
    for(int i=y;i<=y2;i++)
        for(int j=x;j<=x2;j++)
            if(board[i][j]==1) return false;
    return true;
}


int bfs(int startY, int startX, int finY, int finX)
{
    int visited[MAX_N][MAX_N][6][11] = { 0, };
    queue <CAR> q;
    CAR startC = { startY,startX,0,0 };
    q.push(startC);
    visited[startC.y][startC.x][startC.direct][startC.speed] = 1;
    while (!q.empty())
    {
        CAR nowC = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            CAR nextC = nowC;
            Order(nextC, order[i]);
           // cout << nextC.y << " " << nextC.x << " " << nextC.direct << " " << nextC.speed << endl;
            if (is_in_board(nextC.y, nextC.x) && !visited[nextC.y][nextC.x][nextC.direct][nextC.speed]
                && board[nextC.y][nextC.x] != 1 && can_go(nowC.y,nowC.x,nextC.y,nextC.x))
            {
                //cout << nextC.y << " " << nextC.x << " " << nextC.direct << " " << nextC.speed << endl;
                visited[nextC.y][nextC.x][nextC.direct][nextC.speed] = visited[nowC.y][nowC.x][nowC.direct][nowC.speed] + 1;
                q.push(nextC);
            }
        }
    }
    int ret = INF;
    for (int i = 0; i < 6; i++)
            if (visited[finY][finX][i][0])
                ret = min(ret, visited[finY][finX][i][0]-1);

    return ret == INF ? -1 : ret;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, cnt = 1;
    cin >> t;
    while (t--)
    {
        memset(board, 0, sizeof(board));
        int startY, startX, finY, finX;
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
        {
            string s;
            cin >> s;
            for (int j = 1; j <= M; j++)
            {
                if (s[j - 1] == 'P') board[i][j] = 1;
                else if (s[j - 1] == 'R') startY = i, startX = j;
                else if (s[j - 1] == 'D') finY = i, finX = j;
            }
        }
        int ret= bfs(startY, startX, finY, finX);
        if(ret !=-1)
         cout <<"Data Set "<<cnt++<<":\n" << ret << "\n\n";
        else
         cout <<"Data Set "<<cnt++<<":\nImpossible\n\n";
    }
    return 0;
}
