#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=2e6+200;
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
    int query(int value){return query(value,0,n-1,1);}
    int query(int value,int left,int right,int node)
    {
        if(left==right)return left;
        int mid=(left+right)/2;

        if(value<=tree[node*2])return query(value,left,mid,node*2);
        else return query(value-tree[node*2],mid+1,right,node*2+1);
    }
    int update(int idx,int value){return update(idx,value,0,n-1,1);}
    int update(const int idx,const int value,int left,int right,int node)
    {
        if(idx<left||right<idx)return tree[node];
        if(left==right)return tree[node]+=value;
        int mid=(left+right)/2;
        return tree[node]=update(idx,value,left,mid,node*2)+update(idx,value,mid+1,right,node*2+1);
    }

};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int M;
    cin>>M;
    SEG_TREE seg(MAX_N);
    while(M--)
    {
        int type,x;
        cin>>type>>x;
        if(type==1){
            seg.update(x,1);
        }
        else{
            int ret=seg.query(x);
            cout<<ret<<"\n";
            seg.update(ret,-1);
        }
    }
}
