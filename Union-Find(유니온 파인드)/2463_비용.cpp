#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const int INF=987654321,MOD=(int)1e9;
int N,M;
vector<pair<int,pair<int,int>>>adj;

struct UNION_FIND
{
public:

    vector <int> parent,height;
    vector<ll>sum;
    UNION_FIND(){;};
    UNION_FIND(int n)
    {
        parent.resize(n+1),height.resize(n+1,1);
        sum.resize(n+1,1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
    }
    int find(int n)
    {
        if(parent[n]==n) return n;
        return find(parent[n]);
    }
    void merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v) return;
        if(height[u]>height[v])
            swap(u,v);
        parent[u]=v;
        sum[v]+=sum[u];
        if(height[u]==height[v])
            height[v]++;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    ll ans=0,sum=0;
    while(M--)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj.push_back({-cost,{u,v}});
        sum+=cost;
    }
    sort(adj.begin(),adj.end());
    UNION_FIND uf(N+1);
    for(auto i:adj)
    {
        int cost=-i.first;
        int u=i.second.second,v=i.second.first;
        if(uf.find(u)!=uf.find(v))
            ans+=(sum*uf.sum[uf.find(u)]*uf.sum[uf.find(v)])%MOD;
        uf.merge(u,v);
        sum-=cost;
    }
    cout<<ans%MOD;
}


