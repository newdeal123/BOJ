#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
const int INF=987654321;
int N,M;

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n),height.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int u)
    {
        if(u==parent[u])return u;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    int start,fin,ans=INF;
    cin>>start>>fin;
    vector<pair<int,pair<int,int>>>edge;
    while(M--)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        edge.push_back({-cost,{u,v}});
    }

    UNION_FIND uf(N);
    sort(edge.begin(),edge.end());
    for(auto i:edge)
    {
        if(uf.find(start)==uf.find(fin))break;

        int cost=-i.first;
        int u=i.second.first,v=i.second.second;
        uf.merge(u,v);
        ans=min(ans,cost);
    }
    cout<<ans;
}
