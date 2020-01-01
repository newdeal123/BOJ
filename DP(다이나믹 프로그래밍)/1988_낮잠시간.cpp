#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
const int INF=987654321;
int N,M,cache[3001][3001][2],str[3001];

int f(int idx,int sum,bool rest)
{
    if(idx==N)return 0;
    if(idx>=N+1)return -INF;

    int&ret=cache[idx][sum][rest];
    if(ret!=-1)return ret;

    if(sum==0)return ret=f(idx+1,sum,0);

    if(rest) return ret=max(f(idx+1,sum-1,1)+str[idx],f(idx+1,sum,0));
    else return ret=max(f(idx+1,sum-1,1),f(idx+1,sum,0));

}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    for(int i=0;i<N;i++)cin>>str[i];
    cout<<f(0,M,0);
}
