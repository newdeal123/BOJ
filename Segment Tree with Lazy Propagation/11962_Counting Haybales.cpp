#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long ll;
const ll INF=LLONG_MAX-1000;

struct SEG_TREE
{
    int n;
    vector<ll>lazy;
    vector<pair<ll,ll>>tree;
    SEG_TREE(vector<ll>&v)
    {
        n=v.size();
        tree.resize(n*4),lazy.resize(n*4,0);
        init(v,0,n-1,1);
    }
    pair<ll,ll> init(vector<ll>&v,int left,int right,int node)
    {
        if(left==right)return tree[node]={v[left],v[left]};
        int mid=(left+right)/2;
        pair<ll,ll>l=init(v,left,mid,node*2);
        pair<ll,ll>r=init(v,mid+1,right,node*2+1);
        return tree[node]={l.first+r.first,min(l.second,r.second)};
    }
    void propagate(int left,int right,int node)
    {
        if(lazy[node])
        {
            if(left!=right)
            {
                lazy[node*2]+=lazy[node];
                lazy[node*2+1]+=lazy[node];
            }
            pair<ll,ll>next={tree[node].first+lazy[node]*(right-left+1),tree[node].second+lazy[node]};
            tree[node]=next;
            lazy[node]=0;
        }
    }
    pair<ll,ll> query(int left,int right){return query(left,right,0,n-1,1);}
    pair<ll,ll> query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft)return {0,INF};
        if(left<=nodeLeft&&nodeRight<=right)return tree[node];
        int mid=(nodeLeft+nodeRight)/2;

        pair<ll,ll>l=query(left,right,nodeLeft,mid,node*2);
        pair<ll,ll>r=query(left,right,mid+1,nodeRight,node*2+1);

        return {l.first+r.first,min(l.second,r.second)};
    }
    pair<ll,ll> update(int left,int right,int k){return update(left,right,k,0,n-1,1);}
    pair<ll,ll> update(const int left,const int right,const int k,int nodeLeft,int nodeRight,int node)
    {
        propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft)return tree[node];
        if(left<=nodeLeft&&nodeRight<=right)
        {
            lazy[node]+=k;
            propagate(nodeLeft,nodeRight,node);
            return tree[node];
        }
        int mid=(nodeLeft+nodeRight)/2;

        pair<ll,ll>l=update(left,right,k,nodeLeft,mid,node*2);
        pair<ll,ll>r=update(left,right,k,mid+1,nodeRight,node*2+1);

        return tree[node]={l.first+r.first,min(l.second,r.second)};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,Q;
    cin>>N>>Q;
    vector<ll>v(N);
    for(auto&i:v)cin>>i;
    SEG_TREE seg(v);
    while(Q--)
    {
        char type;
        int a,b,c;
        cin>>type>>a>>b;
        if(type=='M')
        {
            pair<ll,ll>ans=seg.query(a-1,b-1);
            cout<<ans.second<<"\n";
        }
        else if(type=='S')
        {
            pair<ll,ll>ans=seg.query(a-1,b-1);
            cout<<ans.first<<"\n";
        }
        else
        {
            cin>>c;
            seg.update(a-1,b-1,c);
        }
    }
}
