#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD=1000007;
int w,h,Tx,Ty;
int cache[201][201][2];

bool is_in_range(int x,int y)
{
    if(x<1||x>w||y<1||y>h)return false;
    return true;
}

int f(int x,int y,bool visited)
{
    if(!is_in_range(x,y))return 0;
    if(x==w&&y==h)return (visited);
    int&ret=cache[x][y][visited];
    if(ret!=-1)return ret%MOD;
    
    visited=max(visited,(x==Tx&&y==Ty));
    return ret=(f(x,y+1,visited)+f(x+1,y,visited))%MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>w>>h>>Tx>>Ty;
    cout<<f(1,1,0);
}
