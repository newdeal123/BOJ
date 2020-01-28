#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
const int MAX_N=1000+2;
int N,M;
vector<pair<int,int>>adj[MAX_N];

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(int s)
    {
        n=s+1;
        parent.resize(n),height.resize(n,0);
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

int kruskal()
{
    int cnt1=0,cnt2=0;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<=N;i++)
    for(auto j:adj[i])edges.push_back({j.second,{i,j.first}});
    sort(edges.begin(),edges.end());
    UNION_FIND uf1(N),uf2(N);
    for(auto i:edges)
    {
        int u=i.second.first,v=i.second.second,cost=i.first;
        if(uf1.find(u)==uf1.find(v))continue;
        if(cost==0)cnt1++;
        uf1.merge(u,v);
    }
    reverse(edges.begin(),edges.end());
    for(auto i:edges)
    {
        int u=i.second.first,v=i.second.second,cost=i.first;
        if(uf2.find(u)==uf2.find(v))continue;
        if(cost==0)cnt2++;
        uf2.merge(u,v);
    }
    return abs(cnt1*cnt1-cnt2*cnt2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;

    for(int i=0;i<M+1;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }
    cout<<kruskal();
}
