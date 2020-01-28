#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
const int MAX_N=30;
int N;
vector<pair<int,int>>adj[MAX_N];

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(int s)
    {
        n=s;
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
    int ret=0;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<N;i++)
    for(auto j:adj[i])edges.push_back({j.second,{i,j.first}});
    sort(edges.begin(),edges.end());
    UNION_FIND uf(N);
    for(auto i:edges)
    {
        int u=i.second.first,v=i.second.second,cost=i.first;
        if(uf.find(u)==uf.find(v))continue;
        ret+=cost;
        uf.merge(u,v);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(true)
    {
        cin>>N;
        if(N==0)break;

        for(int i=0;i<MAX_N;i++)adj[i].clear();

        for(int i=0;i<N-1;i++)
        {
            char u;
            int t;
            cin>>u>>t;
            while(t--)
            {
                char v;
                int dist;
                cin>>v>>dist;
                adj[u-'A'].push_back({v-'A',dist});
            }
        }
        cout<<kruskal()<<"\n";
    }
}
