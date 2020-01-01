#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=100+2,INF=987654321;
int R,C,cache[10000+2][MAX_N];

int f(int r,int c)
{
    if(r==c)return 1;

    int&ret=cache[r][c];
    if(ret!=-1)return ret;
    ret=INF;
    if(r>=c*3) return ret=f(r-c,c)+1;
    for(int i=1;i<=r/2;i++)
        ret=min(ret,f(i,c)+f(r-i,c));
    for(int i=1;i<=c/2;i++)
        ret=min(ret,f(r,i)+f(r,c-i));
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>R>>C;
    cout<<f(R,C);
}
