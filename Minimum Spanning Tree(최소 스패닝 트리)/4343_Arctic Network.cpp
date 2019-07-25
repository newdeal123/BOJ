#include<bits/stdc++.h>
using namespace std;
int S,P;
vector<pair<int,int>>cdnate;

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n),height.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int u)
    {
        if(parent[u]==u) return u;
        return find(parent[u]);
    }
    int merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v) return 0;
        if(height[u]>height[v])swap(u,v);
        parent[u]=v;
        if(height[u]==height[v]) height[v]++;
        return 1;
    }
};

double getDist(pair<int,int>a,pair<int,int>b)
{
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

double kruskal()
{
    vector <pair<double,pair<int,int>>> edges;
    for(int i=0;i<P;i++)
        for(int j=i+1;j<P;j++)
            edges.push_back(make_pair(getDist(cdnate[i],cdnate[j]),make_pair(i,j)));
    sort(edges.begin(),edges.end());
    UNION_FIND uf(P);
    int cnt=P-S;
    double ret=0.0;
    for(int i=0;cnt;i++)
    {
        ret=edges[i].first;
        int u=edges[i].second.first,v=edges[i].second.second;
        cnt-=uf.merge(u,v);
    }
    return ret;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cdnate.clear();
        cin>>S>>P;
        for(int i=0;i<P;i++)
        {
            int x,y;
            cin>>x>>y;
            cdnate.push_back(make_pair(x,y));
        }
        cout.precision(2);
        cout<<fixed;
        cout<<kruskal()<<"\n";

    }
}
