#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321;
int N,Q;

struct NODE
{
    int max1,max2,cnt_max;
    ll sum;
};

struct SEG_TREE
{
    int n;
    vector<NODE>tree;
    SEG_TREE(){;}
    SEG_TREE(vector<int>v)
    {
        n=v.size();
        tree.resize(n*4);
        init(v,0,n-1,1);
    }
    NODE add(NODE a,NODE b)
    {
        if(a.max1==b.max1) return {a.max1,max(a.max2,b.max2),a.cnt_max+b.cnt_max,a.sum+b.sum};
        else if(a.max1>b.max1) return {a.max1,max(a.max2,b.max1),a.cnt_max,a.sum+b.sum};
        else if(b.max1>a.max1) return {b.max1,max(a.max1,b.max2),b.cnt_max,a.sum+b.sum};
    }
    NODE init(vector<int>&v,int left,int right,int node)
    {
        if(left==right)return tree[node]={v[left],-INF,1,v[left]};
        int mid=(left+right)/2;
        return tree[node]=add(init(v,left,mid,node*2),init(v,mid+1,right,node*2+1));
    }
    void lazy_propagation(int left,int right,int node)
    {
        if(left!=right)
            for(int idx=node*2;idx<=node*2+1;idx++)
                if(tree[node].max1<tree[idx].max1)
                {
                    tree[idx].sum-=(ll)tree[idx].cnt_max*(tree[idx].max1-tree[node].max1);
                    tree[idx].max1=tree[node].max1;
                }
    }
    void update(int left,int right,int k){return update(left,right,k,0,n-1,1);}
    void update(const int left,const int right,const int k,int nodeLeft,int nodeRight,int node)
    {
        //cout<<nodeLeft<<" "<<nodeRight<<endl;
        if(nodeRight<left||right<nodeLeft||tree[node].max1<=k) return ;
        lazy_propagation(nodeLeft,nodeRight,node);
        if(left<=nodeLeft&&nodeRight<=right&&tree[node].max2<k)
        {
            tree[node].sum-=(ll)tree[node].cnt_max*(tree[node].max1-k);
            tree[node].max1=k;
            lazy_propagation(nodeLeft,nodeRight,node);
            return ;
        }
        int mid=(nodeLeft+nodeRight)/2;
        update(left,right,k,nodeLeft,mid,node*2);
        update(left,right,k,mid+1,nodeRight,node*2+1);
        tree[node]=add(tree[node*2],tree[node*2+1]);
    }

    int query_max(int left,int right){return query_max(left,right,0,n-1,1);}
    int query_max(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        lazy_propagation(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft)return -INF;
        if(left<=nodeLeft&&nodeRight<=right)return tree[node].max1;
        int mid=(nodeLeft+nodeRight)/2;
        return max(query_max(left,right,nodeLeft,mid,node*2),query_max(left,right,mid+1,nodeRight,node*2+1));
    }

    ll query_sum(int left,int right){return query_sum(left,right,0,n-1,1);}
    ll query_sum(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        lazy_propagation(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft)return 0;
        if(left<=nodeLeft&&nodeRight<=right)return tree[node].sum;
        int mid=(nodeLeft+nodeRight)/2;
        return query_sum(left,right,nodeLeft,mid,node*2)+query_sum(left,right,mid+1,nodeRight,node*2+1);
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    vector<int>v(N);
    for(auto&i:v)cin>>i;
    SEG_TREE seg(v);
    cin>>Q;
    while(Q--)
    {
        int type,left,right,x;
        cin>>type;
        if(type==1)
        {
            cin>>left>>right>>x;
            seg.update(left-1,right-1,x);
        }
        else if(type==2)
        {
            cin>>left>>right;
            cout<<seg.query_max(left-1,right-1)<<"\n";
        }
        else if(type==3)
        {
            cin>>left>>right;
            cout<<seg.query_sum(left-1,right-1)<<"\n";
        }
    }
}
