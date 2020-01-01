#include <iostream>
#include <string>
#include <string.h>=
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N,M;
int feeling[11][100000+2],cache[100000+2][11];

int f(int day,int last)
{
    if(day==N+1)return 0;
    int&ret=cache[day][last];
    if(ret!=-1)return ret;

    for(int i=1;i<=M;i++)
    {
        if(i==last)ret=max(ret,f(day+1,i)+feeling[i][day]/2);
        else ret=max(ret,f(day+1,i)+feeling[i][day]);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)cin>>feeling[i][j];
    cout<<f(1,0);
}
