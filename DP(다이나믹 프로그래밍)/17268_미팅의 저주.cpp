#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
const ll MOD=987654321;
ll cache[10001];


ll f(int n)
{
    if(n==0)return 1;
    ll&ret=cache[n];
    if(ret!=-1)return ret%MOD;
    ret=0;
    for(int i=0;i<n;i++)
        ret=(ret+f(i)*f(n-1-i)%MOD)%MOD;
    return ret%MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    int n;
    cin>>n;
    cout<<f(n/2);
}
