#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=20+2,INF=987654321;
int H,W,N,cache[MAX_N][MAX_N][MAX_N],goY[4]={-1,0,1,0},goX[4]={0,-1,0,1};
char board[MAX_N][MAX_N];
vector<char>order[MAX_N];

int type(char c)
{
    if(c=='W')return 0;
    else if(c=='A')return 1;
    else if(c=='S')return 2;
    else return 3;
}

bool is_in_board(int y,int x)
{
    if(y<1||y>H||x<1||x>W)return false;
    return true;
}

int f(int y,int x,int time)
{
    if(board[y][x]=='Z')return true;
    if(time==N)return false;
    int&ret=cache[y][x][time];
    ret=false;

    for(auto i:order[time])
    {
        int nextY=y+goY[type(i)],nextX=x+goX[type(i)];
        if(!is_in_board(nextY,nextX)||board[nextY][nextX]=='@')continue;
        ret=max(ret,f(nextY,nextX,time+1));
    }
    return ret;
}

void output(int y,int x,int time)
{
    if(board[y][x]=='Z'||time==N)return ;
    char ans;
    for(auto i:order[time])
    {
        int nextY=y+goY[type(i)],nextX=x+goX[type(i)];
        if(!is_in_board(nextY,nextX)||board[nextY][nextX]=='@')continue;
        if(f(nextY,nextX,time+1))ans=i;
    }
    cout<<ans;
    output(y+goY[type(ans)],x+goX[type(ans)],time+1);
}

int main()
{
    memset(cache,-1,sizeof(cache));
    int startY,startX;
    cin>>H>>W;
    for(int i=1;i<=H;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=W;j++)
        {
            board[i][j]=s[j-1];
            if(board[i][j]=='D')startY=i,startX=j;
        }
    }
    cin>>N;
    for(int i=0;i<N;i++)
    {
        char a,b;
        cin>>a>>b;
        order[i].push_back(a),order[i].push_back(b);
    }
    if(f(startY,startX,0))
    {
        cout<<"YES\n";
        output(startY,startX,0);
    }
    else cout<<"NO\n";
}
