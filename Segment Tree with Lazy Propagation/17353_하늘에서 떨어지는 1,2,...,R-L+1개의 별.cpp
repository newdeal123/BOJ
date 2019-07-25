#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=1000000+2;
int N,M,K;

struct SEG_TREE
{
    int n;
    vector <ll> tree;
    vector<pair<ll,ll>>lazy;
    SEG_TREE(){;};
    SEG_TREE(vector<ll> &arr)
    {
        n=arr.size();
        tree.resize(n*4,0),lazy.resize(n*4);
        for(auto i:lazy)i.first=0,i.second=0;
        init(arr,0,n-1,1);
    }
    ll init(vector<ll>&arr,int left,int right,int node)
    {
        if(left==right) return tree[node]=arr[left];
        int mid=(left+right)/2;
        return tree[node]=init(arr,left,mid,node*2)+init(arr,mid+1,right,node*2+1);

    }
    void propagate(int nodeLeft,int nodeRight,int node)
    {
        if(lazy[node].first)
        {
            if(nodeLeft!=nodeRight)
            {
                int mid=(nodeLeft+nodeRight)/2;
                lazy[node*2].first+=lazy[node].first;
                lazy[node*2].second+=lazy[node].second;
                lazy[node*2+1].first+=lazy[node].first;
                lazy[node*2+1].second+=lazy[node].second+lazy[node].first*(mid+1-nodeLeft);
            }
            else
                tree[node]+=lazy[node].second;
            lazy[node]=make_pair(0,0);
        }
    }
    void update(int left,int right)
    {
        return update(left,right,0,n-1,1);
    }
    void update(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(nodeRight<left||right<nodeLeft) return ;
        if(left<=nodeLeft&&nodeRight<=right)
            {
                lazy[node].first+=1;
                lazy[node].second+=nodeLeft-left+1;
                return ;
            }
        int mid=(nodeLeft+nodeRight)/2;
        update(left,right,nodeLeft,mid,node*2);
        update(left,right,mid+1,nodeRight,node*2+1);
    }
    ll query(int idx)
    {
        return query(idx,0,n-1,1);
    }
    ll query(const int idx,int nodeLeft,int nodeRight,int node)
    {
         propagate(nodeLeft,nodeRight,node);
         if(nodeRight<idx||idx<nodeLeft) return 0;
        if(idx<=nodeLeft&&nodeRight<=idx) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        return query(idx,nodeLeft,mid,node*2)+query(idx,mid+1,nodeRight,node*2+1);
    }
};


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<ll>v(N+1);
    for(int i=1;i<=N;i++) cin>>v[i];

    SEG_TREE seg(v);
    int t;
    cin>>t;
    while(t--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int left,right;
            cin>>left>>right;
            seg.update(left,right);
        }
        else
        {
            int k;
            cin>>k;
            cout<<seg.query(k)<<"\n";
        }
    }
}
