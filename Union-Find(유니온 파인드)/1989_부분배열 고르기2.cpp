#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

struct UNION_FIND
{
    int n;
public:
    vector<int>parent,height,left,right;
    vector<ll>Sum;
    UNION_FIND(){;}
    UNION_FIND(vector<int>v)
    {
        n=v.size();
        parent.resize(n),height.resize(n,1),Sum.resize(n,0);
        left.resize(n),right.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            Sum[i]=v[i];
            left[i]=i;
            right[i]=i;
        }
    }
    int find(int u)
    {
        if(u==parent[u]) return u;
        return find(parent[u]);
    }
    void merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v) return;
        if(height[u]>height[v]) swap(u,v);
        parent[u]=v;
        Sum[v]+=Sum[u];
        left[v]=min(left[v],left[u]);
        right[v]=max(right[v],right[u]);
        if(height[u]==height[v]) height[v]++;
    }
    ll getSum(int idx)
    {
        return Sum[find(idx)];
    }
    int getLeft(int idx){return left[find(idx)];}
    int getRight(int idx){return right[find(idx)];}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    vector<int>v;
    v.resize(N);
    for(auto&i:v)cin>>i;
    UNION_FIND uf(v);
    ll ans=0;
    int left=0,right=0;
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<N;i++)pq.push({v[i],i});

    while(!pq.empty())
    {
        int value=pq.top().first,idx=pq.top().second;
        pq.pop();

        if(idx!=0&&v[idx-1]>=v[idx])
            uf.merge(idx,idx-1);
        if(idx!=N-1&&v[idx]<=v[idx+1])
            uf.merge(idx,idx+1);
            //cout<<uf.getSum(idx)<<"*"<<value<<"\n";
        if(ans<uf.getSum(idx)*value)
        {
            ans=uf.getSum(idx)*value;
            left=uf.getLeft(idx);
            right=uf.getRight(idx);
        }
    }
    cout<<ans<<"\n";
    cout<<left+1<<" "<<right+1;





}
