#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=(int)1e6+2;
int N,arr[MAX_N];
ll sum[MAX_N];
vector<pair<ll,ll>> v;

struct UNION_FIND
{
    int n;
    vector<int>parent,height,Sum;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s;
        parent.resize(n),height.resize(n,1),Sum.resize(n,1);
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
        if(u==v) return;
        if(height[u]>height[v]) swap(u,v);
        parent[u]=v;
        Sum[v]+=Sum[u];
        if(height[u]==height[v]) height[v]++;
    }
    int getSum(int u)
    {
        return Sum[find(u)];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    UNION_FIND uf(N),uf2(N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++)
    {
        int idx=v[i].second;
        ll left=0,right=0;
        if(idx>0 && arr[idx-1]<=arr[idx])
        {
            left=uf.getSum(idx-1);
            uf.merge(idx-1,idx);
        }
        if(idx<N-1 && arr[idx]>arr[idx+1])
        {
            right=uf.getSum(idx+1);
            uf.merge(idx,idx+1);
        }
        //cout<<v[i].first<<"*"<<left+1<<"*"<<right+1<<endl;
        sum[i]+=v[i].first*(left+1)*(right+1);
    }
    for(int i=N-1;i>=0;i--)
    {
        int idx=v[i].second;
        ll left=0,right=0;
        if(idx>0 && arr[idx-1]>arr[idx])
        {
            left=uf2.getSum(idx-1);
            uf2.merge(idx-1,idx);
        }
        if(idx<N-1 && arr[idx]<=arr[idx+1])
        {
            right=uf2.getSum(idx+1);
            uf2.merge(idx,idx+1);
        }
        //cout<<v[i].first<<"*"<<left+1<<"*"<<right+1<<endl;
        sum[i]-=v[i].first*(left+1)*(right+1);
    }
    ll ret=0;
    for(int i=0;i<N;i++)ret+=sum[i];
    cout<<ret;

}
