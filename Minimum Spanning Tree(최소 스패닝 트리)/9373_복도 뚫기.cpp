#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=1002+2;
int N,W;
vector<pair<int,double>>adj[MAX_N];

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


double kruskal()
{
    double ret=0;
    UNION_FIND uf(N+2);
    vector <pair<double,pair<int,int>>> edges;
    for(int i=0;i<=N;i++)
        for(auto j:adj[i]) edges.push_back({j.second,{j.first,i}});

    sort(edges.begin(),edges.end());

    for(auto i:edges)
    {
        double dist=i.first;
        int u=i.second.first,v=i.second.second;
        if(uf.find(u)!=uf.find(v))
        {
            uf.merge(u,v);
            ret=dist;
            if(uf.find(N)==uf.find(N+1))break;
        }
    }
    return ret;
}
struct NODE
{
  int x,y,r;
};

double getDist(NODE a,NODE b)
{
    return sqrt((ll)(a.x-b.x)*(a.x-b.x)+(ll)(a.y-b.y)*(a.y-b.y));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed;
    cout.precision(6);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>W>>N;
        for(int i=0;i<MAX_N;i++)adj[i].clear();
        vector<NODE>v;
        for(int i=0;i<N;i++)
        {
            int x,y,r;
            cin>>x>>y>>r;
            v.push_back({x,y,r});
        }
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
        {
            adj[i].push_back({j,max(0.0,getDist(v[i],v[j])-v[i].r-v[j].r)});
        }
        adj[N].push_back({N+1,W});
        for(int i=0;i<N;i++)
        {
            adj[i].push_back({N,max(0,v[i].x-v[i].r)});
            adj[i].push_back({N+1,max(0,W-v[i].x-v[i].r)});
        }
        cout<<kruskal()/2.0<<"\n";
    }

}
