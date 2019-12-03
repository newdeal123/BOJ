#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int N,M,Q;
long long ans=0;
vector<pair<int,int>>query;
vector<int>v;
bool connected[100000+2]={0,};

struct UNION_FIND
{
    int n;
    vector<int>parent,height,sum;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n+1),height.resize(n+1,1),sum.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int find(int u)
    {
        if(u==parent[u]) return u;
        return find(parent[u]);
    }
    void merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v) return ;
        if(height[u]>height[v]) swap(u,v);
        parent[u]=v;
        if(height[u]==height[v]) height[v]++;
        sum[v]+=sum[u];
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
    cin>>N>>M>>Q;
    memset(connected,1,sizeof(connected));
    UNION_FIND uf(N);
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
        query.push_back(make_pair(u,v));
    }
    for(int i=0;i<Q;i++)
    {
        int tmp;
        cin>>tmp;
        connected[tmp-1]=0;
        v.push_back(tmp);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<M;i++)if(connected[i])uf.merge(query[i].first,query[i].second);
    for(auto i:v)
    {
        int u=query[i-1].first,v=query[i-1].second;
        if(uf.find(u)!=uf.find(v))ans+=uf.getSum(u)*uf.getSum(v);
        uf.merge(u,v);
        //cout<<ans<<endl;
    }
    cout<<ans;
}
