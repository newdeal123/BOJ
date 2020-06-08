#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int INF=987654321;
int N,cost[4][4]={{100,70,40,0},{70,50,30,0},{40,30,20,0},{0,0,0,0}};
char board[11][11];
int cache[11][1<<11][1<<11];

int f(int y,int nowBits,int downBits)
{
    if(y==N)return (nowBits==0?0:-INF);

    int&ret=cache[y][nowBits][downBits];
    if(ret!=-1)return ret;
    ret=f(y+1,downBits,0);

    for(int i=0;i<N;i++)
    {
        if(nowBits&(1<<i))continue;
        int nextBits=nowBits|(1<<i);
        if(i!=N-1&&!(nowBits&(1<<(i+1))))ret=max(ret,f(y,nextBits|(1<<(i+1)),downBits)+cost[board[y][i]-'A'][board[y][i+1]-'A']);
        if(y!=N-1&&!(downBits&(1<<i)))ret=max(ret,f(y,nextBits,downBits|(1<<i))+cost[board[y][i]-'A'][board[y+1][i]-'A']);
    }
    return ret;
}

int main()
{
    cin>>N;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<N;j++)board[i][j]=(s[j]=='F'?'D':s[j]);
    }
    cout<<f(0,0,0);
}
