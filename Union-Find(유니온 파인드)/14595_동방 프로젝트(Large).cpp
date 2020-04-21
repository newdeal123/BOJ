#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
const int INF=987654321;

struct UNION_FIND
{
    int n;
    vector<int>parent,height;
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n),height.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
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
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,Q,ans=0;
    cin>>N>>Q;
    vector<pair<int,int>>range;
    while(Q--)
    {
        int l,r;
        cin>>l>>r;
        range.push_back({l,r});
    }
    sort(range.begin(),range.end());
    UNION_FIND uf(N+1);
    if(!range.empty())
    {
        int left=range.front().first,right=range.front().second;
        for(int i=1;i<range.size();i++)
        {
            if(right<range[i].first)
            {
                for(int j=left;j<=right;j++)
                    uf.merge(left,j);
                left=range[i].first;
                right=range[i].second;
            }
            else right=max(right,range[i].second);
        }
        for(int i=left;i<=right;i++)
            uf.merge(left,i);
    }
    set<int>st;
    for(int i=1;i<=N;i++)
    {
        int parent=uf.find(i);
        if(st.find(parent)==st.end())
        {
            st.insert(parent);
            ans+=1;
        }
    }
    cout<<ans;

}
