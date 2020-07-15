#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<pair<int,int>>v;
        vector<int>rad;
        for(int i=0;i<N;i++)
        {
            int x,y,r;
            cin>>x>>y>>r;
            v.push_back({x,y});
            rad.push_back(r);
        }
        UNION_FIND uf(N+1);
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                double dist=sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[j].second-v[i].second)*(v[j].second-v[i].second));
                //cout<<i<<" "<<dist<<"\n";
                if(rad[i]+rad[j]>=dist) uf.merge(i,j);
            }
        }
        int ans=0;
        set<int>st;
        for(int i=0;i<N;i++)
            if(st.find(uf.find(i))==st.end())
        {
            st.insert(uf.find(i));
            ans++;
        }
        cout<<ans<<"\n";


    }
}
