#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int N,M,cache[101][101];

int canWin(int a,int b)
{
    if(a==1&&b==1)return false;

    int&ret=cache[a][b];
    if(ret!=-1)return ret;
    if(a!=1)
        for(int i=1;i<a;i++)if(!canWin(i,a-i))return ret=true;
    if(b!=1)
        for(int i=1;i<b;i++)if(!canWin(i,b-i))return ret=true;
    return ret=false;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
   if(canWin(N,M))cout<<"A";
   else cout<<"B";
}
