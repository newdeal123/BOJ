#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=1000+2;
int N,M;
vector<pair<int,int>>node,connected;

struct UNION_FIND
{
    vector<int> parent,h;
    UNION_FIND(){;};
    UNION_FIND(int n)
    {
        parent.resize(n+1),h.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int find(int n)
    {
        if(n==parent[n]) return n;
        return find(parent[n]);
    }
    void merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v) return;
        if(h[u]>h[v]) swap(u,v);
        parent[u]=v;
        if(h[u]==h[v]) h[v]++;
    }
};

long double getDist(pair<int,int>a,pair<int,int>b)
{
    return sqrt((long long)(a.first-b.first)*(a.first-b.first)+(long long)(a.second-b.second)*(a.second-b.second));
}

long double kruskal()
{
    long double ret=0.0;
    vector<pair<long double,pair<int,int>>> edge;
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++)
        edge.push_back(make_pair(getDist(node[i],node[j]),make_pair(i,j)));
    sort(edge.begin(),edge.end());
    UNION_FIND uf(N);
    for(auto i:connected)
    {
        if(uf.find(i.first)==uf.find(i.second)) continue;
        uf.merge(i.first,i.second);
    }
    for(auto i:edge)
    {
        long double cost=i.first;
        int u=i.second.first,v=i.second.second;
        if(uf.find(u)==uf.find(v)) continue;
        ret+=cost;
        uf.merge(u,v);
    }
    return ret;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    node.resize(N+1);
    for(int i=1;i<=N;i++)
    {
        int x,y;
        cin>>x>>y;
        node[i]=make_pair(x,y);
    }
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        connected.push_back(make_pair(a,b));
    }
    cout<<fixed;
    cout.precision(2);
    cout<<kruskal();
}
