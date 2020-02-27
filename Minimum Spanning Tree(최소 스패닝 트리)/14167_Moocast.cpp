#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=1000+2;
int N,C;
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
    int maxN=-1;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<N;i++)
        for(auto j:adj[i])
            edges.push_back({j.second,{i,j.first}});
    sort(edges.begin(),edges.end());
    UNION_FIND uf(N);
    for(auto i:edges)
    {
        int u=i.second.first,v=i.second.second;
        int cost=i.first;
        if(uf.find(u)==uf.find(v))continue;
        maxN=max(maxN,cost);
        uf.merge(u,v);
    }
    return maxN;
}

int getDist(pair<int,int>a,pair<int,int>b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    vector<pair<int,int>>v(N);
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        v[i]={a,b};
    }
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
    {
        int dist=getDist(v[i],v[j]);
        adj[i].push_back({j,dist});
        adj[j].push_back({i,dist});
    }
    cout<<kruskal();

}
