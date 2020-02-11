#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD=(ll)1e9+7;

struct SEG_TREE
{
    int n;
    vector <ll> tree;
    vector<pair<ll,ll>> lazy;
    SEG_TREE(){;};
    SEG_TREE(vector<ll> &arr)
    {
        n=arr.size();
        tree.resize(n*4,0),lazy.resize(n*4);
        init(arr,0,n-1,1);
        for(int i=0;i<n*4;i++)lazy[i]={1,0};
    }
    ll init(vector<ll>&arr,int left,int right,int node)
    {
        if(left==right) return tree[node]=arr[left];
        int mid=(left+right)/2;
        return tree[node]=(init(arr,left,mid,node*2)+init(arr,mid+1,right,node*2+1))%MOD;
    }
    void propagate(int nodeLeft,int nodeRight,int node)
    {
        if(lazy[node].first!=1 || lazy[node].second!=0)
        {
            if(nodeLeft!=nodeRight)
            {
                lazy[node*2]={(lazy[node*2].first*lazy[node].first)%MOD,
                    (lazy[node*2].second*lazy[node].first+lazy[node].second)%MOD};
                lazy[node*2+1]={(lazy[node*2+1].first*lazy[node].first)%MOD,
                    (lazy[node*2+1].second*lazy[node].first+lazy[node].second)%MOD};
            }
            tree[node]=(lazy[node].first*tree[node]+lazy[node].second*(nodeRight-nodeLeft+1))%MOD;
            lazy[node]={1,0};
        }
    }
    ll update(int left,int right,int value,bool toPlus)
    {
        return update(left,right,value,toPlus,0,n-1,1)%MOD;
    }
    ll update(const int left,const int right,const int value,const bool toPlus,int nodeLeft,int nodeRight,int node)
    {
        propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft) return tree[node]%MOD;
        if(left<=nodeLeft&&nodeRight<=right)
            {
                if(toPlus)lazy[node].second+=value;
                else lazy[node]={lazy[node].first*value,lazy[node].second*value};
                propagate(nodeLeft,nodeRight,node);
                return tree[node]%MOD;
            }
        int mid=(nodeLeft+nodeRight)/2;
        return tree[node]=(update(left,right,value,toPlus,nodeLeft,mid,node*2)
        +update(left,right,value,toPlus,mid+1,nodeRight,node*2+1))%MOD;
    }
    ll query(int left,int right)
    {
        return query(left,right,0,n-1,1)%MOD;
    }
    ll query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft) return 0;
        if(left<=nodeLeft&&nodeRight<=right) return tree[node]%MOD;
        int mid=(nodeLeft+nodeRight)/2;
        return (query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1))%MOD;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,Q;
    cin>>N;
    vector<ll>v(N);
    for(auto&i:v)cin>>i;
    SEG_TREE seg(v);
    cin>>Q;
    while(Q--)
    {
        int type,x,y,v;
        cin>>type;
        if(type==1)
        {
            cin>>x>>y>>v;
            seg.update(x-1,y-1,v,true);
        }
        else if(type==2)
        {
            cin>>x>>y>>v;
            seg.update(x-1,y-1,v,false);
        }
        else if(type==3)
        {
            cin>>x>>y>>v;
            seg.update(x-1,y-1,0,false);
            seg.update(x-1,y-1,v,true);
        }
        else
        {
            cin>>x>>y;
            cout<<seg.query(x-1,y-1)%MOD<<"\n";
        }
        //for(int i=1;i<=N;i++)
        //    cout<<"tree: "<<seg.query(i-1,i-1)<<" ";
       // cout<<endl;
    }
}
