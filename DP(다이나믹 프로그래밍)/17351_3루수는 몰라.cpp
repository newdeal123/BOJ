#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int MAX_N=500+2;
int N,cache[MAX_N][MAX_N][4];
string S="MOLA";
char board[MAX_N][MAX_N];
int goY[2]={1,0};
int goX[2]={0,1};

bool is_in_board(int y,int x)
{
    if(y<1||y>N||x<1||x>N) return false;
    return true;
}

int f(int y,int x,int idx)
{
    if(!is_in_board(y,x)) return 0;
    int&ret=cache[y][x][idx];
    if(ret!=-1) return ret;
    ret=0;
    bool toPlus=false;
    if(S[idx]==board[y][x]) idx++;
    else if(S[0]==board[y][x]) idx=1;
    else idx=0;

    if(idx==4) idx=0,toPlus=true;



    for(int i=0;i<2;i++)
    {
        int nextY=y+goY[i],nextX=x+goX[i];
        ret=max(ret,f(nextY,nextX,idx)+toPlus);
    }

    return ret;

}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>board[i][j];

    cout<<f(1,1,0);
}
