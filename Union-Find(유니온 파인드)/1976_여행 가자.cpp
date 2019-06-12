#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1000000+2;

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
        if(u==v) return;
        if(height[u]>height[v])
            swap(u,v);
        parent[u]=v;
        if(height[u]==height[v])
            height[v]++;
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    UNION_FIND uf(N);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
    {
        bool tmp;
        cin>>tmp;
        if(tmp) uf.merge(i,j);
    }
    int city,root;
    cin>>city;
    root=uf.find(city);
    for(int i=1;i<M;i++)
    {
        cin>>city;
        if(uf.find(city)!=root)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

}
