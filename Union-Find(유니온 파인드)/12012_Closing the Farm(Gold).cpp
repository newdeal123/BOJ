#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=200000+2;
int N,M,arr[MAX_N];
vector<int>ans,query,adj[MAX_N];
vector<pair<int,int>>edges;

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND();
    UNION_FIND(int N)
    {
        n=N;
        parent.resize(N+1),height.resize(N+1,1);
        for(int i=1;i<=N;i++)parent[i]=i;
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
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back(make_pair(u,v));
    }
    query.resize(N);
    for(int i=0;i<N;i++)
    {
        cin>>query[i];
        arr[query[i]]=i;
    }
    reverse(query.begin(),query.end());

    UNION_FIND uf(N);
    for(int i=0;i<M;i++)
    {
        int u=edges[i].first,v=edges[i].second;
        if(arr[u]>arr[v])adj[v].push_back(u);
        else adj[u].push_back(v);
    }
    int cnt=0;
    for(auto u:query)
    {
        cnt++;
        for(auto v:adj[u])
            if(uf.find(u)!=uf.find(v)){uf.merge(u,v);cnt--;}

        if(cnt<=1)ans.push_back(true);
        else ans.push_back(false);
    }
    reverse(ans.begin(),ans.end());

    for(auto i:ans)
    {
        if(i) cout<<"YES\n";
        else cout<<"NO\n";
    }

}
