#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MOD=(int)1e9+9;
int N,cache[33333+3][3];

int f(int n,int sum)
{
    if(n==1) return 1;
    int&ret=cache[n][sum];
    if(ret!=-1)return ret%MOD;
    ret=0;
    for(int i=0;i<3;i++)
        ret=(long long)(ret+f(n-1,i))%MOD;
    return ret%MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    long long ans=(f(n,0)-f(n-1,0)+MOD)%MOD;
    cout<<ans;
}
