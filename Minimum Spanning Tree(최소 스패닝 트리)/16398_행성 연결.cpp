#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=1000+2;
int N;
int cost[MAX_N][MAX_N];

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
    vector <pair<int,pair<int,int>>> edges;
    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++)
            if(i!=j) edges.push_back(make_pair(cost[i][j],make_pair(i,j)));
    sort(edges.begin(),edges.end());
    for(auto i:edges)
    {
        int dist=i.first;
        int u=i.second.first,v=i.second.second;
        if(uf.find(u)!=uf.find(v))
        {
            ret+=dist;
            uf.merge(u,v);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>cost[i][j];
    cout<<kruskal();
}
