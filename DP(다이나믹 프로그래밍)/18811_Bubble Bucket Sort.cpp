#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll cache[202][202][202];
const ll INF=(ll)1e18+2;
int N,K;
vector<ll>v;

ll f(int idx,int sum,int last,ll minN,ll maxN)
{
    if(idx==N+1)return(last==N?0:INF);
    if(sum==0)return INF;

    ll&ret=cache[idx][sum][last];
    if(ret!=-1)return ret;

    minN=min(minN,v[idx]);
    maxN=max(maxN,v[idx]);
    return ret=min(f(idx+1,sum,last,minN,maxN),
                   f(idx+1,sum-1,idx,INF,0)+(maxN-minN)*(maxN-minN));
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>K;
    v.resize(N+1);
    v[0]=0;
    for(int i=1;i<=N;i++)cin>>v[i];
    sort(v.begin(),v.end());
    cout<<f(1,K,0,INF,0);
}
