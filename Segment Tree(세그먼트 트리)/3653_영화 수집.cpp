#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct SEG_TREE
{
    int n;
    vector<int>tree;
    SEG_TREE(vector<int>&v)
    {
        n=v.size();
        tree.resize(n*4,0);
        init(v,0,n-1,1);
    }
    int init(vector<int>&v,int left,int right,int node)
    {
        if(left==right)return tree[node]=v[left];
        int mid=(left+right)/2;

        return tree[node]=init(v,left,mid,node*2)+init(v,mid+1,right,node*2+1);
    }
    int update(int idx,int value){return update(idx,value,0,n-1,1);}
    int update(const int idx,const int value,int nodeLeft,int nodeRight,int node)
    {
        if(idx<nodeLeft || nodeRight<idx)return tree[node];
        if(nodeLeft==nodeRight)return tree[node]=value;

        int mid=(nodeLeft+nodeRight)/2;
        return tree[node]=update(idx,value,nodeLeft,mid,node*2)+update(idx,value,mid+1,nodeRight,node*2+1);
    }
    int query(int left,int right){return query(left,right,0,n-1,1);}
    int query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(right<nodeLeft||nodeRight<left)return 0;
        if(left<=nodeLeft&&nodeRight<=right)return tree[node];

        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int N,M;
        cin>>N>>M;
        vector<int>loc(N+1,0),v(N+M,0);
        for(int i=0;i<N;i++)
        {
            v[i+M]=1;
            loc[i+1]=M+i;
        }
        SEG_TREE seg(v);
        for(int i=1;i<=M;i++)
        {
            int tmp;
            cin>>tmp;
            cout<<seg.query(0,loc[tmp]-1)<<" ";
            seg.update(loc[tmp],0);
            loc[tmp]=M-i;
            seg.update(loc[tmp],1);
        }
        cout<<"\n";
    }
}
