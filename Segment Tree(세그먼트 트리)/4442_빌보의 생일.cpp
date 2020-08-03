#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
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
    while(true)
    {
        int N,cnt=1;
        cin>>N;
        if(N==0)break;
        map<string,int>mp;
        vector<int>v1,loc(N+1,0);
        vector<pair<int,int>>v2;
        for(int i=0;i<N;i++)
        {
            string s;
            cin>>s;
            mp.insert({s,cnt++});
            v1.push_back(mp[s]);
            loc[mp[s]]=i;
        }
        SEG_TREE seg(N+2);
        for(int i=0;i<N;i++)
        {
            string s;
            cin>>s;
            v2.push_back({loc[mp[s]],i});
        }
        sort(v2.begin(),v2.end());
        ll sum=0;
        for(auto i:v2)
        {
            sum+=seg.query(i.second+1,N+1);
            seg.update(i.second);
        }
        cout<<sum<<"\n";
    }
}
