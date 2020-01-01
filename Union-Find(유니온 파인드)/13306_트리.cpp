#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,Q;
vector<vector<int>>query;
vector<int>ans;
int Parent[200000+2];

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND();
    UNION_FIND(int N)
    {
        n=N;
        parent.resize(N+1),height.resize(N+1,1);
        for(int i=1;i<=N;i++)parent[i]=i;
    }
    int find(int u)
    {
        if(u==parent[u])return u;
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
    bool same(int u,int v)
    {
        if(find(u)==find(v))return true;
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>Q;
    UNION_FIND uf(N);
    for(int u=2;u<=N;u++)
    {
        int v;
        cin>>v;
        Parent[u]=v;
    }
    query.resize(N-1+Q);
    for(int i=0;i<N-1+Q;i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int u,v;
            cin>>u>>v;
            query[i]={1,u,v};
        }
        else
        {
            int a;
            cin>>a;
            query[i]={0,a};
        }
    }
    reverse(query.begin(),query.end());

    for(int i=0;i<query.size();i++)
    {
        if(query[i][0]==0)
            uf.merge(query[i][1],Parent[query[i][1]]);
        else
        {
            if(uf.same(query[i][1],query[i][2]))ans.push_back(true);
            else ans.push_back(false);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
    {
        if(i==true)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
