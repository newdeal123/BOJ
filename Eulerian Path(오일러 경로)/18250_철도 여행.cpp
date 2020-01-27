#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int INF=987654321,MAX_N=200000+2;
int N,M,degree[MAX_N]={0,};
vector<pair<int,int>>V;

struct UNION_FIND
{
    int n;
    vector<int>parent;
public:
    vector<int>height,odd;
    UNION_FIND(int l)
    {
        n=l;
        parent.resize(n+1),height.resize(n+1,1);
        odd.resize(n+1,0);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            odd[i]=(degree[i]%2==1?1:0);
        }

    }
    int find(int u)
    {
        if(u==parent[u])return u;
        else return find(parent[u]);
    }
    bool merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v)return false;
        if(height[u]>height[v])swap(u,v);
        odd[v]+=odd[u];
        parent[u]=v;
        if(height[u]==height[v])height[v]++;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    int ans=0;
    while(M--)
    {
        int u,v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
        V.push_back({u,v});
    }
    UNION_FIND uf(N);
    int cnt=0;
    for(auto i:V)
    {
        int u=i.first,v=i.second;
        uf.merge(u,v);
    }
    set<int>parent;
    for(int i=1;i<=N;i++)
    {
        int p=uf.find(i);
        if(degree[p]==0)continue;
        if(parent.find(p)==parent.end())
        {
            parent.insert(p);
            if(!uf.odd[p])ans++;
            else ans+=uf.odd[p]/2;
        }
    }
    cout<<ans;

}


