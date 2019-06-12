#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=1000000+2;
int N,M,K;

struct SEG_TREE
{
    int n;
    vector <ll> tree,lazy;
    SEG_TREE(){;};
    SEG_TREE(vector<ll> &arr)
    {
        n=arr.size();
        tree.resize(n*4,0),lazy.resize(n*4,0);
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
        if(lazy[node])
        {
            if(nodeLeft!=nodeRight)
            {
                lazy[node*2]+=lazy[node];
                lazy[node*2+1]+=lazy[node];
            }
            tree[node]+=lazy[node]*(nodeRight-nodeLeft+1);
            lazy[node]=0;
        }
    }
    ll update(int left,int right,int value)
    {
        return update(left,right,value,0,n-1,1);
    }
    ll update(const int left,const int right,const int value,int nodeLeft,int nodeRight,int node)
    {
        propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft) return tree[node];
        if(left<=nodeLeft&&nodeRight<=right)
            {
                lazy[node]+=value;
                propagate(nodeLeft,nodeRight,node);
                return tree[node];
            }
        int mid=(nodeLeft+nodeRight)/2;
        return tree[node]=update(left,right,value,nodeLeft,mid,node*2)+update(left,right,value,mid+1,nodeRight,node*2+1);
    }
    ll query(int left,int right)
    {
        return query(left,right,0,n-1,1);
    }
    ll query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
         propagate(nodeLeft,nodeRight,node);
         if(nodeRight<left||right<nodeLeft) return 0;
        if(left<=nodeLeft&&nodeRight<=right) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
};


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>K;
    vector<ll>v(N);
    for(int i=0;i<N;i++)
        cin>>v[i];
    SEG_TREE seg(v);
    int t=M+K;
    while(t--)
    {
        int order,a,b,c;
        cin>>order;
        if(order==1)
        {
            cin>>a>>b>>c;
            seg.update(a-1,b-1,c);
        }
        else
        {
            cin>>a>>b;
            cout<<seg.query(a-1,b-1)<<"\n";
        }
    }
}
