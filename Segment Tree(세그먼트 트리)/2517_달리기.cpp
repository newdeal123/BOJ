#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

struct SEG_TREE
{
    int n;
    vector<int>tree;
    SEG_TREE(){;}
    SEG_TREE(vector<int>&v)
    {
        n=v.size();
        tree.resize(n*4,0);
    }
    int query(int left,int right){return query(left,right,0,n-1,1);}
    int query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(nodeRight<left||right<nodeLeft)return 0;
        if(left<=nodeLeft&&nodeRight<=right)return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
    int update(int idx){return update(idx,0,n-1,1);}
    int update(const int idx,int left,int right,int node)
    {
        if(idx<left||right<idx)return tree[node];
        if(left==right)return tree[node]=1;
        int mid=(left+right)/2;
        return tree[node]=update(idx,left,mid,node*2)+update(idx,mid+1,right,node*2+1);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    vector<int>v(N),ans(N);
    for(auto&i:v)cin>>i;
    SEG_TREE seg(v);

    vector<pair<int,int>>arr;
    for(int i=0;i<N;i++)
        arr.push_back({v[i],i});
    sort(arr.rbegin(),arr.rend());
    for(auto&i:arr)
    {
        ans[i.second]=seg.query(0,i.second);
        seg.update(i.second);
    }
    for(int i=0;i<N;i++)cout<<ans[i]+1<<"\n";
}
