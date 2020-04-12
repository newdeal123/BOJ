#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
int N;
ll ans=0;

struct UNION_FIND
{
    vector <int> parent,height,sum;
    UNION_FIND(){;};
    UNION_FIND(int n)
    {
        parent.resize(n+1),height.resize(n+1,1);
        sum.resize(n+1,1);
        for(int i=0;i<=n;i++)
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
    int getSum(int u){return sum[find(u)];}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    vector<pair<int,pair<int,int>>>edge;
    for(int i=0;i<N-1;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        edge.push_back({-cost,{u,v}});
    }
    sort(edge.begin(),edge.end());
    UNION_FIND uf(N+1);
    for(auto i:edge)
    {
        int cost=-i.first;
        int u=i.second.first,v=i.second.second;

        ans+=(ll)cost*uf.getSum(u)*uf.getSum(v);
        uf.merge(u,v);
    }
    cout<<ans;
}


