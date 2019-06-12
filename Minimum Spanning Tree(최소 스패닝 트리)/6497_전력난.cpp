#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=200000+2;
int N,M;
vector <pair<int,int>> adj[MAX_N];

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
    vector<pair<int,pair<int,int> >> edge;
    for(int i=0;i<N;i++)
        for(auto j:adj[i])
        edge.push_back(make_pair(j.second,make_pair(i,j.first)));
    sort(edge.begin(),edge.end());
    UNION_FIND uf(N);
    for(auto i:edge)
    {
        int cost=i.first,u=i.second.first,v=i.second.second;
        if(uf.find(u)==uf.find(v)) continue;
        uf.merge(u,v);
        ret+=cost;
    }
    return ret;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true)
    {
        for(int i=0;i<MAX_N;i++)
            adj[i].clear();
        int sum=0;
        cin>>N>>M;
        if(!N&&!M) break;
        while(M--)
        {
            int x,y,z;
            cin>>x>>y>>z;
            adj[x].push_back(make_pair(y,z));
            sum+=z;
        }
        cout<< sum-kruskal()<<"\n";
    }
}
