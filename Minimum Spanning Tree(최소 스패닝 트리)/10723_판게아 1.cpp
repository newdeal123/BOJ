#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
int n,m;
vector<pair<int,ll>>adj[2001];

struct UNION_FIND
{
    int n;
    vector<int>height,parent;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s;
        height.resize(n,1),parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int u)
    {
        if(u==parent[u]) return u;
        return find(parent[u]);
    }
    void merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v)return ;
        if(height[u]>height[v])swap(u,v);
        parent[u]=v;
        if(height[u]==height[v])height[v]++;
    }
};

ll kruskal()
{
    ll ans=0;
    vector<pair<ll,pair<int,int>>> edges;
    for(int i=0;i<n;i++)
        for(auto j:adj[i]) edges.push_back(make_pair(j.second,make_pair(i,j.first)));
    sort(edges.begin(),edges.end());
    UNION_FIND uf(n);
    for(auto i:edges)
    {
        int u=i.second.first,v=i.second.second;
        ll cost=i.first;
        if(uf.find(u)==uf.find(v))continue;
        ans+=cost;
        uf.merge(u,v);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<2001;i++)adj[i].clear();
        cin>>n>>m;
        for(int u=1;u<n;u++)
        {
            int v;
            ll c;
            cin>>v>>c;
            adj[u].push_back(make_pair(v,c));
        }
        int u,v;
        ll c;
        cin>>u>>v>>c;
        adj[u].push_back(make_pair(v,c));
        ll ans=kruskal();
        m--;
        while(m--)
        {
            cin>>u>>v>>c;
            adj[u].push_back(make_pair(v,c));
            ans=ans^kruskal();
        }
        cout<<ans<<"\n";
    }
}
