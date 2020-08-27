#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321;

struct SEG_TREE{
    int n;
    vector<int>tree;
    SEG_TREE(vector<int>&v){
        n=v.size()+1;
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
    int update(const int idx,const int value,int left,int right,int node)
    {
        if(right<idx||idx<left)return tree[node];
        if(left==right)return tree[node]=tree[node]+value;
        int mid=(left+right)/2;

        return tree[node]=update(idx,value,left,mid,node*2)+update(idx,value,mid+1,right,node*2+1);
    }
    int query(int left,int right){return query(left,right,0,n-1,1);}
    int query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(nodeRight<left||right<nodeLeft)return 0;
        if(left<=nodeLeft&&nodeRight<=right)return tree[node];
        int mid=(nodeLeft+nodeRight)/2;

        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N;
    vector<int>v(N);
    for(auto&i:v)cin>>i;

    SEG_TREE seg(v);
    cin>>M;
    while(M--)
    {
        int type;
        cin>>type;
        if(type==1){
            int a,b;
            cin>>a>>b;
            seg.update(a-1,b);
        }
        else{
            int num;
            cin>>num;
            int left=0,right=N-1,ret=-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                int value=seg.query(0,mid);
                if(value>=num)
                {
                    ret=mid;
                    right=mid-1;
                }
                else left=mid+1;
            }
            cout<<ret+1<<"\n";
        }
    }
}
