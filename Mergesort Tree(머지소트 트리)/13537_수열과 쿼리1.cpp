#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int MAX_N=100000+2;

struct SEG_TREE
{
    int n;

    vector<int>tree[MAX_N*4];
    SEG_TREE(){;}
    SEG_TREE(vector<int>&v)
    {
        n=v.size();
        for(int i=0;i<n;i++)
           init(i,v[i],0,n-1,1);
        for(int i=0;i<MAX_N*4;i++)
            sort(tree[i].begin(),tree[i].end());
    }
    void init(const int idx,const int num,int left,int right,int node)
    {
        if(right<idx||idx<left)return;
        tree[node].push_back(num);
        if(left==right)return ;

        int mid=(left+right)/2;
        init(idx,num,left,mid,node*2);
        init(idx,num,mid+1,right,node*2+1);
    }
    int query(int left,int right,int k){return query(left,right,k,0,n-1,1);}
    int query(const int left,const int right,const int k,int nodeLeft,int nodeRight,int node)
    {
        if(nodeRight<left||right<nodeLeft)return 0;
        if(left<=nodeLeft&&nodeRight<=right)
            return tree[node].end()-upper_bound(tree[node].begin(),tree[node].end(),k);
        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,k,nodeLeft,mid,node*2)+query(left,right,k,mid+1,nodeRight,node*2+1);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int>v(N);
    for(int i=0;i<N;i++)cin>>v[i];
    SEG_TREE seg(v);
    int q;
    cin>>q;
    while(q--)
    {
        int left,right,k;
        cin>>left>>right>>k;
        left--,right--;
        cout<<seg.query(left,right,k)<<"\n";
    }

}
