#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef long long ll;

struct SEG_TREE{
    int n;
    vector<int>tree;
    SEG_TREE(int len){
        n=len+1;
        tree.resize(n*4,0);
    }
    int update(int idx){return update(idx,0,n-1,1);}
    int update(const int idx,int left,int right,int node)
    {
        if(right<idx||idx<left)return tree[node];
        if(left==right)return tree[node]=tree[node]+1;
        int mid=(left+right)/2;

        return tree[node]=update(idx,left,mid,node*2)+update(idx,mid+1,right,node*2+1);
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

bool comp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)return a.first<b.first;
    else return a.second<b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    SEG_TREE seg(N*2+2);
    vector<pair<int,int>>v;
    while(M--)
    {
        int i,j;
        cin>>i>>j;
        i--,j--;
        v.push_back({i,j});
    }
    sort(v.begin(),v.end());
    ll sum=0;
    for(auto i:v)
    {
        int a=i.first,b=i.second;
        sum+=seg.query(b+1,N*2);
        seg.update(b);
    }
    cout<<sum;
}
