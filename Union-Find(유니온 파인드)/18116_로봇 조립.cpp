#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

struct UNION_FIND
{
    int n;
    vector<int>parent,height,sum;
    UNION_FIND(){;};
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n+1),height.resize(n+1,1);
        sum.resize(n+1,1);
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
        sum[v]+=sum[u];
        if(height[u]==height[v])height[v]++;
    }
    int getSum(int u)
    {
        return sum[find(u)];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    UNION_FIND uf((int)1e6);
    int t;
    cin>>t;
    while(t--)
    {
        char type;
        int a,b;
        cin>>type;
        if(type=='I')
        {
            cin>>a>>b;
            uf.merge(a,b);
        }
        else
        {
            cin>>a;
            cout<<uf.getSum(a)<<"\n";
        }
    }
}
