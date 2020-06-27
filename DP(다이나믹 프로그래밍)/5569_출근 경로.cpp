#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
const int MOD=1e5;
int W,H,cache[101][101][2][2];
int goX[2]={1,0},goY[2]={0,1};

bool is_in_board(int x,int y)
{
    if(x<1||x>W||y<1||y>H)return false;
    return true;
}

int f(int x,int y,bool llast,bool last)
{
    if(!is_in_board(x,y))return false;
    if(x==W&&y==H)return 1;

    int&ret=cache[x][y][llast][last];
    if(ret!=-1)return ret%MOD;
    ret=0;
    if(x==1&&y==1)return ret=(f(x+goX[0],y+goY[0],0,0)+f(x+goX[1],y+goY[1],1,1))%MOD;

    if(llast!=last)ret+=f(x+goX[last],y+goY[last],last,last)%MOD;
    else ret+=(f(x+goX[0],y+goY[0],last,0)+f(x+goX[1],y+goY[1],last,1))%MOD;
    return ret%MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>W>>H;
    cout<<f(1,1,0,0);
}
