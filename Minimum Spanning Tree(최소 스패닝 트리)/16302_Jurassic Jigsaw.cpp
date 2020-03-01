#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=1000+2;
int N,M;
vector<pair<int,int>>adj[MAX_N];
vector<pair<int,int>>ans;

struct UNION_FIND
{
    int n;
    vector <int> parent,height;
    UNION_FIND(){;};
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n),height.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int u)
    {
        if(u==parent[u]) return u;
        return find(parent[u]);
    }
    void merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v) return;

        if(height[u]>height[v]) swap(u,v);
        parent[u]=v;
        if(height[u]==height[v]) height[v]++;
    }
};

ll kruskal()
{
    ll ret=0;
    UNION_FIND uf(N);
    vector <pair<int,pair<int,int>>> edges;
    for(int i=0;i<N;i++)
        for(auto j:adj[i]) edges.push_back({j.second,{i,j.first}});
    sort(edges.begin(),edges.end());

    for(auto i:edges)
    {
        int dist=i.first;
        int u=i.second.first,v=i.second.second;
        if(uf.find(u)!=uf.find(v))
        {
            ret+=dist;
            uf.merge(u,v);
            ans.push_back({u,v});
        }
    }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    vector<string>v(N);
    for(auto&s:v)cin>>s;

    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
    {
        int cnt=0;
        for(int k=0;k<M;k++)
            if(v[i][k]!=v[j][k])cnt++;
        adj[i].push_back({j,cnt});
    }

    cout<<kruskal()<<"\n";
    for(auto i:ans)cout<<i.first<<" "<<i.second<<"\n";
}
