#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD=1000000007;
int N,M;
vector<int>v(N);

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
    cin>>N>>M;
    for(auto &i:v)cin>>i;
    UNION_FIND uf(N);
    while(M--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        for(int i=l;i<=r-k;i++)uf.merge(i,i+k);
    }
    int ans=1;
    for(int i=1;i<=N;i++)if(uf.find(i)==i) ans=(ans*2)%MOD;
    cout<<ans;
}
