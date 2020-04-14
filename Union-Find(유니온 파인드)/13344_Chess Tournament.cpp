#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
int N,M;
vector<int>ans,adj[50001];
bool visited[50001],finished[50001];
vector<pair<int,int>>bigger;

struct UNION_FIND
{
    vector <int> parent,height;
    UNION_FIND(){;};
    UNION_FIND(int n)
    {
        parent.resize(n+1),height.resize(n+1,1);
        for(int i=0;i<n;i++)
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
        if(height[u]==height[v])
            height[v]++;
    }
};

bool dfs(int u)
{
    visited[u]=true;
    bool ret=true;
    for(auto v:adj[u])
    {
        if(!visited[v])
            ret=min(ret,dfs(v));
        else if(!finished[v])ret=false;
    }
    finished[u]=true;
    return ret;
}

bool isEqual(UNION_FIND& uf)
{
    for(auto i:bigger)
    {
        int u=i.first,v=i.second;
        if(uf.find(u)==uf.find(v))return false;
        adj[uf.find(u)].push_back(uf.find(v));
    }
    for(int i=0;i<N;i++)
        if(!visited[i]&&!dfs(i))return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    UNION_FIND uf(N);
    while(M--)
    {
        int u,v;
        char type;
        cin>>u>>type>>v;
        if(type=='=')
            uf.merge(u,v);
        else bigger.push_back({u,v});
    }
    if(isEqual(uf))cout<<"consistent";
    else cout<<"inconsistent";
}


