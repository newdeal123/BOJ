#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=1000+2;
int N,M,board[MAX_N][MAX_N],cache[MAX_N][MAX_N][4];
int goY[3]={1,1,1};
int goX[3]={1,0,-1};

bool is_in_board(int y,int x)
{
    if(y<1||y>N+1||x<1||x>M)return false;
    return true;
}

int f(int y,int x,int last)
{
    if(y==N+1)return 0;

    int&ret=cache[y][x][last];
    if(ret!=-1)return ret;
    ret=INF;
    for(int i=0;i<3;i++)
    {
        int nextY=y+goY[i],nextX=x+goX[i];
        if(!is_in_board(nextY,nextX)||last==i)continue;
        ret=min(ret,f(nextY,nextX,i)+board[y][x]);
    }
    return ret;
}


int main()
{
    memset(cache,-1,sizeof(cache));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)cin>>board[i][j];
    int ret=INF;
    for(int i=1;i<=M;i++)ret=min(ret,f(1,i,4));
    cout<<ret;
}
