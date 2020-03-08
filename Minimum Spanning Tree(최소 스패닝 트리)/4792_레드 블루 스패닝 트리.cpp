#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=1000+2;
int N,M,K;
vector<pair<int,char>>adj[MAX_N];

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

struct NODE
{
    int dist,u,v;
    char c;
};

bool compare(NODE a,NODE b)
{
    return a.dist<b.dist;
}

int kruskal(char stand)
{
    int ret=0;
    UNION_FIND uf(N);
    vector <NODE> edges;
    for(int i=0;i<N;i++)
        for(auto j:adj[i]) edges.push_back({(stand==j.second?1:0),i,j.first,j.second});

    sort(edges.begin(),edges.end(),compare);

    for(auto i:edges)
    {
        if(uf.find(i.u)!=uf.find(i.v))
        {
            uf.merge(i.u,i.v);
            if(i.c=='B')ret++;
        }
    }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(true)
    {
        cin>>N>>M>>K;
        if(!N)break;
        for(int i=0;i<MAX_N;i++)adj[i].clear();
        while(M--)
        {
            char c;
            int u,v;
            cin>>c>>u>>v;
            u--,v--;
            adj[u].push_back({v,c});
        }
        int minN=kruskal('B'),maxN=kruskal('R');
        //cout<<minN<<","<<maxN<<" ";
        if(minN<=K&&K<=maxN)cout<<"1\n";
        else cout<<"0\n";
    }

}
