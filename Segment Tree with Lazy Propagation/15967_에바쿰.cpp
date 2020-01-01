#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N,Q1,Q2,Q;
typedef long long ll;

struct SEG_TREE
{
    int n;
    vector<ll>tree;
    vector<int>lazy;
    SEG_TREE(vector<int>&v)
    {
        n=v.size();
        tree.resize(n*4,0),lazy.resize(n*4,0);
        init(v,0,n-1,1);
    }
    ll init(vector<int>&v,int left,int right,int node)
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
    cin>>N>>Q1>>Q2;
    Q=Q1+Q2;
    vector<int>v(N);
    for(auto&i:v)cin>>i;
    SEG_TREE seg(v);

    while(Q--)
    {
        int type,a,b,c;
        cin>>type;
        if(type==1)
        {
            cin>>a>>b;
            cout<<seg.query(a-1,b-1)<<"\n";
        }
        else
        {
            cin>>a>>b>>c;
            seg.update(a-1,b-1,c);
        }
    }

}
