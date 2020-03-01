#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=1000+2;
int N,e,p;
vector<pair<int,double>>adj[MAX_N];
vector<pair<int,int>>connected;
vector<pair<double,double>>v(N);

struct UNION_FIND
{
    int n;
public:
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

double kruskal()
{
    double ans=0;
    vector<pair<double,pair<int,int>>>edges;
    for(int i=0;i<N;i++)
        for(auto j:adj[i])
            edges.push_back({j.second,{i,j.first}});
    sort(edges.begin(),edges.end());
    UNION_FIND uf(N);
    for(int i=0;i<e;i++)uf.merge(0,i);
    for(auto i:connected)uf.merge(i.first,i.second);

    for(auto i:edges)
    {
        int u=i.second.first,v=i.second.second;
        double cost=i.first;
        if(uf.find(u)==uf.find(v))continue;
        ans+=cost;
        uf.merge(u,v);
    }
    return ans;
}

double getDist(pair<double,double>a,pair<double,double>b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>e>>p;
    for(int i=0;i<N;i++)
    {
        double a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
    {
        double dist=getDist(v[i],v[j]);
        adj[i].push_back({j,dist});
    }
    while(p--)
    {
        int u,v;
        cin>>u>>v;
        connected.push_back({u-1,v-1});
    }
    cout<<fixed;
    cout.precision(3);

    cout<<kruskal();

}
