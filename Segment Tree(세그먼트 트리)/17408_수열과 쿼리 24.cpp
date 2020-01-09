#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
const int MAX_N=100000+2;
int N,M;
vector<int>v;

struct SEG_TREE
{
    int n;
    vector<pair<int,int>>tree;
    SEG_TREE(vector<int>&arr)
    {
        n=arr.size();
        tree.resize(n*4);
        init(arr,0,n-1,1);
    }
    pair<int,int> init(vector<int>&arr,int left,int right,int node)
    {
        if(left==right)return tree[node]={arr[left],left};
        int mid=(left+right)/2;
        pair<int,int>l=init(arr,left,mid,node*2),r=init(arr,mid+1,right,node*2+1);
        if(l.first>r.first)return tree[node]=l;
        else return tree[node]=r;
    }
    pair<int,int>update(int idx,int k){return update(idx,k,0,n-1,1);}
    pair<int,int>update(const int idx,const int k,int left,int right,int node)
    {
        if(idx<left||right<idx)return tree[node];
        if(left==right)return tree[node]={k,idx};
        int mid=(left+right)/2;
        pair<int,int>l=update(idx,k,left,mid,node*2),r=update(idx,k,mid+1,right,node*2+1);
        if(l.first>r.first)return tree[node]=l;
        else return tree[node]=r;
    }
    pair<int,int>query(int left,int right){return query(left,right,0,n-1,1);}
    pair<int,int>query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(nodeRight<left||right<nodeLeft)return {0,-1};
        if(left<=nodeLeft&&nodeRight<=right)return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        pair<int,int>l=query(left,right,nodeLeft,mid,node*2),r=query(left,right,mid+1,nodeRight,node*2+1);
        if(l.first>r.first)return l;
        else return r;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(auto&i:v)cin>>i;
    SEG_TREE seg(v);
    cin>>M;
    while(M--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int a,b;
            cin>>a>>b;
            seg.update(a-1,b);
        }
        else
        {
            int l,r;
            pair<int,int>fMax,sLMax,sRMax;
            cin>>l>>r;
            fMax=seg.query(l-1,r-1);
            sLMax=seg.query(l-1,fMax.second-1);
            sRMax=seg.query(fMax.second+1,r-1);
            cout<<fMax.first+max(sLMax.first,sRMax.first)<<"\n";
        }
    }
}
