#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(){;};
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n+1),height.resize(n+1,1);
        for(int i=1;i<=n;i++)parent[i]=i;
    }
    int find(int u)
    {
        if(u==parent[u])return u;
        else return find(parent[u]);
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

int getAns(int N,vector<pair<int,int>>&v)
{
    UNION_FIND uf(N+1);
    for(int i=0;i<v.size();i++){
        int a=v[i].first,b=v[i].second;
        if(uf.find(a)==uf.find(b))return i+1;
        uf.merge(a,b);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>>v(M);
    for(auto&i:v)cin>>i.first>>i.second;
    cout<<getAns(N,v);
}
