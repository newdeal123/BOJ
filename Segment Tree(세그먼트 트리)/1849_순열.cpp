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
    SEG_TREE(int s)
    {
        n=s;
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

    int N,cnt=1;
    cin>>N;
    vector<int>v(N),ans(N);
    for(auto&i:v)cin>>i;
    SEG_TREE seg(N);

    for(auto i:v)
    {
        int left=0,right=N-1,idx=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(mid-seg.query(0,mid)>=i)
            {
                right=mid-1;
                idx=mid;
            }
            else left=mid+1;
        }
        //cout<<cnt<<":"<<idx<<endl;
        seg.update(idx);
        ans[idx]=cnt++;
    }
    for(auto i:ans)cout<<i<<"\n";
}
