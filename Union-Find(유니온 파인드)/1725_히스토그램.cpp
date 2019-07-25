#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<bool>visited;
vector<pair<int,int>>h;

struct UNION_FIND
{
    int n;
    vector<int>parent,height,sum;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n),height.resize(n,1),sum.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
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
    int ret=0;
    cin>>N;
    visited.resize(N,0),h.resize(N);
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        h[i]=make_pair(tmp,i);
    }
    sort(h.rbegin(),h.rend());
    UNION_FIND uf(N);

    for(auto i:h)
    {
        int idx=i.second,height=i.first;
        visited[idx]=1;
        ret=max(ret,height);
        if(idx-1>=0 && visited[idx-1])
        {
            uf.merge(idx-1,idx);
            ret=max(ret,height*uf.getSum(idx));
        }
        if(idx+1<N && visited[idx+1])
        {
            uf.merge(idx,idx+1);
            ret=max(ret,height*uf.getSum(idx+1));
        }
    }
    cout<<ret;
}
