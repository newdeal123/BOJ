#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s+1;
        parent.resize(n),height.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int u)
    {
        if(parent[u]==u)return u;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,k,m;
        cin>>n>>k;
        UNION_FIND uf(n);
        while(k--)
        {
            int a,b;
            cin>>a>>b;
            uf.merge(a,b);
        }
        cin>>m;
        cout<<"Scenario "<<tc<<":\n";
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            if(uf.find(a)==uf.find(b))cout<<"1\n";
            else cout<<"0\n";
        }
        cout<<"\n";
    }
}
