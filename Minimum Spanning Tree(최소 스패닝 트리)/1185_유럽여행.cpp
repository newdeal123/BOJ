#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=10000+2;
int N,M;
vector<pair<int,int>>adj[MAX_N];
vector<int>cost;

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
    int adjCnt[MAX_N]={0,};
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
            uf.merge(u,v);
            adjCnt[u]++,adjCnt[v]++;
            ret+=dist-cost[u]-cost[v];
           // cout<<dist<<" "<<u<<","<<v<<"\n";
        }
    }
    for(int i=0;i<N;i++)ret+=cost[i]*adjCnt[i];
    int minN=INF;
    for(int i=0;i<N;i++)minN=min(minN,cost[i]);
    return ret+minN;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    cost.resize(N);
    for(auto&i:cost)cin>>i;
    while(M--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        u--,v--;
        adj[u].push_back({v,c*2+cost[u]+cost[v]});
    }
    cout<<kruskal();
}
