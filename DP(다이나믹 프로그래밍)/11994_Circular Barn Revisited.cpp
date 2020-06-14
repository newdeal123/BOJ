#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const ll INF=987654321987654321;
ll cache[101][101][8];
int N,K,start;
vector<int>v;

ll f(int now,int time,int keys)
{
    now=(now==N?0:now);
    if(now==start)return 0;
    ll&ret=cache[now][time][keys];
    if(ret!=-1)return ret;
    ret=INF;
    ret=min(ret,f(now+1,time+1,keys)+v[now]*time);
    if(keys)ret=min(ret,f(now+1,1,keys-1));
    return ret;
}


int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>K;
    v.resize(N);
    for(auto&i:v)cin>>i;
    ll ans=INF;
    for(int i=0;i<N;i++)
    {
        memset(cache,-1,sizeof(cache));
        start=i;
        ans=min(ans,f(i+1,1,K-1));
    }
    cout<<ans;
}
