#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=1000+2;
int N;
vector<pair<int,double>>adj[MAX_N];

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

double kruskal()
{
    double sum=0;
    vector<pair<double,pair<int,int>>>edges;

    for(int i=0;i<N;i++)
        for(auto j:adj[i])
            edges.push_back({j.second,{i,j.first}});
    sort(edges.begin(),edges.end());
    UNION_FIND uf(N);
    for(auto i:edges)
    {
        int u=i.second.first,v=i.second.second;
        double cost=i.first;
        if(uf.find(u)==uf.find(v))continue;
        sum+=cost;
        uf.merge(u,v);
    }

    return sum;
}

double getDist(pair<int,int>a,pair<int,int>b)
{
    return sqrt(pow(abs(a.first-b.first),2)+pow(abs(a.second-b.second),2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed;
    cout.precision(2);
    while(true)
    {
        cin>>N;
        if(!N)break;
        for(int i=0;i<MAX_N;i++)adj[i].clear();

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
            adj[i].push_back({j,getDist(v[i],v[j])});
            adj[j].push_back({i,getDist(v[i],v[j])});
        }
        cout<<kruskal()<<"\n";
    }
}
