#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
const int INF=987654321;
const int MAX_N=1000+2;
int V,E;
vector<pair<int,int>> adj[MAX_N],treeAdj[MAX_N];
int visited[MAX_N];

struct UNION_FIND
{
    vector <int> parent,height;
    UNION_FIND(){;};
    UNION_FIND(int n)
    {
        parent.resize(n+1),height.resize(n+1,1);
        for(int i=1;i<=n;i++)
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
        if(u==v)
            return;
        if(height[u]>height[v])
            swap(u,v);
        parent[u]=v;
        if(height[u]==height[v])
            height[v]++;
    }
};

int kruskal()
{
    int ret=0;
    vector <pair<int,pair<int,int>>> edges;
    for(int i=0;i<V;i++)
        for(auto j:adj[i])
            edges.push_back(make_pair(j.second,make_pair(i,j.first)));
    sort(edges.begin(),edges.end());
    UNION_FIND uf(V);
    for(auto i:edges)
    {
        int cost=i.first,u=i.second.first,v=i.second.second;
        if(uf.find(u)==uf.find(v)) continue;
        uf.merge(u,v);
        treeAdj[u].push_back({v,cost});
        treeAdj[v].push_back({u,cost});
        ret+=cost;
    }
    return ret;
}

void dfs(int now){

    for(auto i:treeAdj[now]){
        int next=i.first,nextDist=i.second+visited[now];
        if(visited[next]==-1){
            visited[next]=nextDist;
            dfs(next);
        }
    }

    return ;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>V>>E;
    while(E--){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    cout<<kruskal()<<"\n";
    memset(visited,-1,sizeof(visited));
    visited[0]=0;
    dfs(0);
    int left=0,maxN=0;
    for(int i=0;i<V;i++)
    if(maxN<visited[i]){
        maxN=visited[i];
        left=i;
    }
    memset(visited,-1,sizeof(visited));
    visited[left]=0;
    dfs(left);
    maxN=0;
    for(int i=0;i<V;i++)
     maxN=max(maxN,visited[i]);
    cout<<maxN;
}
