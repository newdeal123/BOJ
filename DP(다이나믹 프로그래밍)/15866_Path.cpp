#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=3e5+2;
int color[MAX_N];
ll cache[MAX_N][1<<5];
vector<int>adj[MAX_N];
int N,M,K;

ll f(int now,int bits)
{
    ll&ret=cache[now][bits];
    if(ret!=-1)return ret;
    ret=0;

    for(auto next:adj[now])
    {
        if(bits&(1<<color[next]))continue;
        ret+=f(next,bits|(1<<color[next]))+1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)
    {
        cin>>color[i];
        color[i]--;
    }
    for(int i=1;i<=M;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=N;i++)ans+=f(i,(1<<color[i]));
    cout<<ans;
}
