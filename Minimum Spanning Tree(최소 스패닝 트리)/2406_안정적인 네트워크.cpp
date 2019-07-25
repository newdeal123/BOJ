#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1000+2;
int N,M,adj[MAX_N][MAX_N],sum=0,cnt;

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n+1),height.resize(n+1,1);
        for(int i=1;i<=n;i++) parent[i]=i;
    }
    int find(int u)
    {
        if(parent[u]==u) return u;
        return find(parent[u]);
    }
    bool merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v) return false;
        if(height[u]>height[v])swap(u,v);
        parent[u]=v;
        if(height[u]==height[v]) height[v]++;
        return true;
    }
};


vector<pair<int,int>> kruskal(UNION_FIND uf)
{
    vector<pair<int,int>> ret;
    vector <pair<int,pair<int,int>>> edges;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            edges.push_back(make_pair(adj[i][j],make_pair(i,j)));
    sort(edges.begin(),edges.end());

    for(int i=0;cnt;i++)
    {
        int cost=edges[i].first;
        int u=edges[i].second.first,v=edges[i].second.second;
        if(u==1||v==1) continue;
        if(uf.merge(u,v))
        {
            sum+=cost;
            cnt--;
            ret.push_back(make_pair(u,v));
        }
    }
    return ret;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    cnt=N-2;
    UNION_FIND uf(N);
    while(M--)
    {
        int u,v;
        cin>>u>>v;
        if(uf.merge(u,v)) cnt--;
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>adj[i][j];
    vector<pair<int,int>>ans;
    ans=kruskal(uf);
    cout<<sum<<" "<<ans.size()<<"\n";
    for(auto i:ans)
        cout<<i.first<<" "<<i.second<<"\n";
}
