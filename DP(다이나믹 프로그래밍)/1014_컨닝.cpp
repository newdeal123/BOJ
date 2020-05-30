#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
int N,M,cache[11][11][1<<10][1<<10];
bool canSeat[11][11];

int f(int y,int x,int upBits,int downBits)
{
    if(x==M)return f(y+1,0,downBits,0);
    if(y==N)return 0;

    int&ret=cache[y][x][upBits][downBits];
    if(ret!=-1)return ret;

    ret=f(y,x+1,upBits,downBits);
    if(!canSeat[y][x])return ret;
    if(x-1>=0&&(upBits&(1<<(x-1))||downBits&(1<<(x-1))))return ret;
    if(x+1<M&&(upBits&(1<<(x+1))||downBits&(1<<(x+1))))return ret;
    if(downBits&(1<<x))return ret;
    return ret=max(ret,f(y,x+1,upBits,downBits|(1<<x))+1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
   {
        memset(cache,-1,sizeof(cache));
        cin>>N>>M;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                char c;
                cin>>c;
                if(c=='.')canSeat[i][j]=true;
                else canSeat[i][j]=false;
            }
        cout<<f(0,0,0,0)<<"\n";
   }
}
