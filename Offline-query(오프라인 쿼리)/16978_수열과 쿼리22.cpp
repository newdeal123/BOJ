#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=100000+2;
typedef long long ll;
vector<vector<int>>query1;
ll ans[MAX_N]={0,};

struct queryNode
{
    int k,left,right,idx;
    bool operator<(const queryNode&O)const{
    if(k!=O.k)return k<O.k;
    else return (idx<O.idx);
    }
};
vector<queryNode>query2;

struct SEG_TREE
{
    int n;
    vector<ll> tree;
    SEG_TREE(){;};
    SEG_TREE(vector<int>&v)
    {
        n=v.size();
        tree.resize(n*4,0);
        init(v,0,n-1,1);
    }
    ll init(vector<int>&v,int left,int right,int node)
    {
        if(left==right)return tree[node]=v[left];
        int mid=(left+right)/2;
        return tree[node]=init(v,left,mid,node*2)+init(v,mid+1,right,node*2+1);
    }
    ll query(int left,int right){return query(left,right,0,n-1,1);}
    ll query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(left>nodeRight || right<nodeLeft) return 0;
        if(left<=nodeLeft && nodeRight<=right) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;

        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
    ll update(int k,ll value) {return update(k,value,0,n-1,1);}
    ll update(const int k,const ll value,int nodeLeft,int nodeRight,int node)
    {
        if(k>nodeRight || k<nodeLeft) return tree[node];
        if(nodeLeft==nodeRight) return tree[node]=value;

        int mid=(nodeLeft+nodeRight)/2;
        return tree[node]=update(k,value,nodeLeft,mid,node*2)+update(k,value,mid+1,nodeRight,node*2+1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,M,cnt=0;
    cin>>N;
    vector<int>v(N);
    for(auto&i:v)cin>>i;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int idx,v;
            cin>>idx>>v;
            vector<int>tmp;
            tmp.push_back(idx-1),tmp.push_back(v);
            query1.push_back(tmp);
        }
        else
        {
            int k,l,r;
            cin>>k>>l>>r;
            query2.push_back({k,l-1,r-1,cnt++});
        }
    }
    sort(query2.begin(),query2.end());
    int lastK=0;
    SEG_TREE seg(v);
    for(auto i:query2)
    {
        while(lastK<i.k)
        {
            seg.update(query1[lastK][0],query1[lastK][1]);
            lastK++;
        }
        ans[i.idx]=seg.query(i.left,i.right);
    }
    for(int i=0;i<MAX_N;i++)
    {
        if(ans[i]==0)break;
        cout<<ans[i]<<"\n";
    }
}
