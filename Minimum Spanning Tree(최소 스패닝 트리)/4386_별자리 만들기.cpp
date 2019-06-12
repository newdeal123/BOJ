#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=1000+2;
int N;

struct PLANET
{
    double x,y;
    int name;
};
vector <PLANET> planet;

double getDist(PLANET a,PLANET b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

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

double kruskal()
{
    double ret=0.0;
    vector<pair<double,pair<int,int> >> edge;
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
        edge.push_back(make_pair(getDist(planet[i],planet[j]),make_pair(planet[i].name,planet[j].name)));
    sort(edge.begin(),edge.end());
    UNION_FIND uf(N);
    for(auto i:edge)
    {
        double cost=i.first;
        int u=i.second.first,v=i.second.second;
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
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        double x,y;
        cin>>x>>y;
        planet.push_back({x,y,i});
    }
    cout<<fixed;
    cout.precision(2);
    cout<<kruskal();
}
