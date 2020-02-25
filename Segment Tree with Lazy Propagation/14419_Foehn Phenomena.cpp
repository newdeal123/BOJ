#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
const int INF=987654321;
typedef long long ll;
struct SEG_TREE
{
    int n;
    vector<ll>tree,lazy;
    SEG_TREE(vector<ll>&v)
    {
        n=v.size();
        tree.resize(n*4,0),lazy.resize(n*4,0);
        init(v,0,n-1,1);
    }
    ll init(vector<ll>&v,int left,int right,int node)
    {
        if(left==right)return tree[node]=v[left];
        int mid=(left+right)/2;
        return tree[node]=init(v,left,mid,node*2)+init(v,mid+1,right,node*2+1);
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
            tree[node]+=(ll)lazy[node]*(right-left+1);
            lazy[node]=0;
        }
    }
    ll query(int left,int right){return query(left,right,0,n-1,1);}
    ll query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft)return 0;
        if(left<=nodeLeft&&nodeRight<=right)return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
    ll update(int left,int right,int k){return update(left,right,k,0,n-1,1);}
    ll update(const int left,const int right,const int k,int nodeLeft,int nodeRight,int node)
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
        return tree[node]=update(left,right,k,nodeLeft,mid,node*2)+update(left,right,k,mid+1,nodeRight,node*2+1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,Q,S,T;
    cin>>N>>Q>>S>>T;
    vector<ll>v(N+1);
    for(auto&i:v)cin>>i;
    ll ans=0;
    for(int i=1;i<=N;i++)
    {
        if(v[i-1]<v[i])ans-=abs(v[i-1]-v[i])*S;
        else ans+=abs(v[i-1]-v[i])*T;
    }
    SEG_TREE seg(v);
    while(Q--)
    {
        int l,r,value;
        cin>>l>>r>>value;
        seg.update(l,r,value);
        ll nowL=seg.query(l,l),nowR=seg.query(r,r);
        ll pastL=nowL-value,pastR=nowR-value;
        if(l!=0)
        {
            ll left=seg.query(l-1,l-1);
            if(left<pastL)ans+=abs(pastL-left)*S;
            else ans-=abs(pastL-left)*T;
            if(left<nowL)ans-=abs(nowL-left)*S;
            else ans+=abs(nowL-left)*T;
        }
        if(r!=N)
        {
            ll right=seg.query(r+1,r+1);
            if(pastR<right)ans+=abs(pastR-right)*S;
            else ans-=abs(pastR-right)*T;
            if(nowR<right)ans-=abs(nowR-right)*S;
            else ans+=abs(nowR-right)*T;
        }
        cout<<ans<<"\n";
    }
}
