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
    vector<int>parent,height,sum;
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n),height.resize(n,1);
        sum.resize(n,1);
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
        sum[v]+=sum[u];
        if(height[u]==height[v])height[v]++;
    }
    int getMaxSum()
    {
        int ret=0;
        for(int i=0;i<n;i++)ret=max(ret,sum[i]);
        return ret;
    }
};

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    int op = a.first*b.second + b.first*c.second + c.first*a.second;
    op -= (a.second*b.first + b.second*c.first + c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}

int isIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y)
{
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0)
    {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return (c <= b&&a <= d);
    }
    return (ab <= 0 && cd <= 0);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<pair<int,int>,pair<int,int>>>edge;
    int N,cnt=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int x,y,x2,y2;
        cin>>x>>y>>x2>>y2;
        edge.push_back({{x,y},{x2,y2}});
    }
    UNION_FIND uf(N);
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            if(isIntersect(edge[i],edge[j])) uf.merge(i,j);
    set<int>st;
    for(int i=0;i<N;i++)
    {
        if(st.find(uf.find(i))==st.end())
        {
            st.insert(uf.find(i));
            cnt++;
        }
    }
    cout<<cnt<<endl<<uf.getMaxSum();
}
