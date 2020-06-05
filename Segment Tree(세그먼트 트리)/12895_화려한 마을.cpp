#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
typedef long long ll;

struct SEG_TREE
{
    int n;
    vector<ll>tree,lazy;
    SEG_TREE();
    SEG_TREE(int s)
    {
        n=s;
        tree.resize(n*4,1);
        lazy.resize(n*4,0);
    }
    void lazy_propagate(int left,int right,int node)
    {
        if(!lazy[node])return ;

        if(left!=right)
        {
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        tree[node]=lazy[node];
        lazy[node]=0;
    }
    void update(int left,int right,ll bit){return update(left,right,bit,0,n-1,1);}
    void update(const int left,const int right,const ll bit,int nodeLeft,int nodeRight,int node)
    {
        lazy_propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft)return ;
        if(left<=nodeLeft&&nodeRight<=right)
        {
            lazy[node]=bit;
            lazy_propagate(nodeLeft,nodeRight,node);
            return ;
        }
        int mid=(nodeLeft+nodeRight)/2;
        update(left,right,bit,nodeLeft,mid,node*2);
        update(left,right,bit,mid+1,nodeRight,node*2+1);
        tree[node]=tree[node*2]|tree[node*2+1];
    }
    ll query(int left,int right){return query(left,right,0,n-1,1);}
    ll query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        lazy_propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft)return 0;
        if(left<=nodeLeft&&nodeRight<=right)return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,nodeLeft,mid,node*2)|query(left,right,mid+1,nodeRight,node*2+1);
    }

};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,T,Q;
    cin>>N>>T>>Q;
    SEG_TREE seg(N);
    while(Q--)
    {
        char type;
        int x,y,z;
        cin>>type;
        if(type=='Q')
        {
            cin>>x>>y;
            if(x>y)swap(x,y);
            ll bits=seg.query(x-1,y-1),cnt=0;
            for(int i=0;i<T;i++)if(bits&(1<<i))cnt++;
            cout<<cnt<<"\n";
        }
        else
        {
            cin>>x>>y>>z;
            if(x>y)swap(x,y);
            seg.update(x-1,y-1,1<<(z-1));
        }
    }
}
