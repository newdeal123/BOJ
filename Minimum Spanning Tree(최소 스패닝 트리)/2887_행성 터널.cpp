#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=10000+2;
int N;
struct PLANET
{
    int x,y,z,name;
};
vector <PLANET> planet;


bool compareX(PLANET a,PLANET b)
{
    return a.x<b.x;
}
bool compareY(PLANET a,PLANET b)
{
    return a.y<b.y;
}
bool compareZ(PLANET a,PLANET b)
{
    return a.z<b.z;
}

int getDist(PLANET a,PLANET b)
{
    return min(abs(a.z-b.z),min(abs(a.y-b.y),abs(a.x-b.x)));
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

int kruskal()
{
    int ret=0;
    vector<pair<int,pair<int,int> >> edge;
    sort(planet.begin(),planet.end(),compareX);
    for(int i=1;i<planet.size();i++)
        edge.push_back(make_pair(getDist(planet[i],planet[i-1]),make_pair(planet[i].name,planet[i-1].name)));
    sort(planet.begin(),planet.end(),compareY);
    for(int i=1;i<planet.size();i++)
        edge.push_back(make_pair(getDist(planet[i],planet[i-1]),make_pair(planet[i].name,planet[i-1].name)));
    sort(planet.begin(),planet.end(),compareZ);
    for(int i=1;i<planet.size();i++)
        edge.push_back(make_pair(getDist(planet[i],planet[i-1]),make_pair(planet[i].name,planet[i-1].name)));
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
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        planet.push_back({a,b,c,i});
    }
    cout<<kruskal();
}
