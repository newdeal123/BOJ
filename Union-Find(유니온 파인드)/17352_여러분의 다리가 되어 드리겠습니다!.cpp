#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n+1),height.resize(n+1,1);
        for(int i=1;i<=n;i++) parent[i]=i;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    UNION_FIND uf(N);
    for(int i=0;i<N-2;i++)
    {
        int u,v;
        cin>>u>>v;
        uf.merge(u,v);
    }
    for(int i=1;i<=N;i++)
    {
        if(uf.find(1)==uf.find(i)) continue;
        cout<<1<<" "<<i<<"\n";
        uf.merge(1,i);
    }

}
