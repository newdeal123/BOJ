#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll MOD=1000000007;
int N,L,R;
ll cache[101][101][101];

ll f(int n,int left,int right)
{
    if(n==1){return((left==right&&left==1)? 1:0);}
    ll& ret=cache[n][left][right];
    if(ret!=-1)return ret%MOD;

    ret=f(n-1,left,right)*(n-2)%MOD;
    if(left>1)ret=(ret+f(n-1,left-1,right))%MOD;
    if(right>1)ret=(ret+f(n-1,left,right-1))%MOD;
    return ret%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));

    cin>>N>>L>>R;
    cout<<f(N,L,R);

}
