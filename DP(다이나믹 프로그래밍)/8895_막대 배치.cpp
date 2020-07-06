#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int N,L,R;
ll cache[21][21][21];

ll f(int n,int left,int right)
{
    if(n==1){return((left==right&&left==1)? 1:0);}
    ll& ret=cache[n][left][right];
    if(ret!=-1)return ret;

    ret=f(n-1,left,right)*(n-2);
    if(left>1)ret+=f(n-1,left-1,right);
    if(right>1)ret+=f(n-1,left,right-1);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N>>L>>R;
        cout<<f(N,L,R)<<"\n";
    }
}
