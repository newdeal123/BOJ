#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <unordered_map>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,cnt=0;
    cin>>N;
    unordered_map<int,int>mp;
    vector<int>loc(N+1,0);
    vector<pair<int,int>>v;
    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        mp.insert({num,cnt});
        loc[cnt++]=i;
    }
    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        v.push_back({loc[mp[num]],i});
    }
    sort(v.begin(),v.end());
    ll sum=0;
    SEG_TREE seg(N+1);
    for(auto i:v)
    {
        sum+=seg.query(i.second+1,N);
        seg.update(i.second);
    }

    cout<<sum;

}
