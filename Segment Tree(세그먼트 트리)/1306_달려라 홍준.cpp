#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
        init(v,0,n-1,1);
    }
    int init(vector<int>&v,int left,int right,int node)
    {
        if(left==right) return tree[node]=v[left];
        int mid=(left+right)/2;
        return tree[node]=max(init(v,left,mid,node*2),init(v,mid+1,right,node*2+1));
    }
    int query(int left,int right) {return query(left,right,0,n-1,1);}
    int query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(nodeRight<left || right<nodeLeft) return 0;
        if(left<=nodeLeft && nodeRight<=right) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        return max(query(left,right,nodeLeft,mid,node*2),query(left,right,mid+1,nodeRight,node*2+1));
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int>v(N);
    for(int i=0;i<N;i++) cin>>v[i];
    SEG_TREE seg(v);

    for(int i=M-1;i<=N-M;i++)
    {
        //cout<<i-M+1<<" "<<i+M-1<<endl;
        cout<<seg.query(i-M+1,i+M-1)<<" ";
    }
}
