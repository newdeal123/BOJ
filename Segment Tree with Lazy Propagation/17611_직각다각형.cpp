#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=500000+2;
int N;
vector<pair<int,int>>v;

struct SEG_TREE
{
    int n;
    vector <int> tree,lazy;
    SEG_TREE(){;};
    SEG_TREE(int len)
    {
        n=len;
        tree.resize(n*4,0),lazy.resize(n*4,0);
    }
    void propagate(int nodeLeft,int nodeRight,int node)
    {
        if(lazy[node])
        {
            if(nodeLeft!=nodeRight)
            {
                lazy[node*2]+=lazy[node];
                lazy[node*2+1]+=lazy[node];
            }
            tree[node]+=lazy[node]*(nodeRight-nodeLeft+1);
            lazy[node]=0;
        }
    }
    int update(int left,int right,int value)
    {
        return update(left,right,value,0,n-1,1);
    }
    int update(const int left,const int right,const int value,int nodeLeft,int nodeRight,int node)
    {
        propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft) return tree[node];
        if(left<=nodeLeft&&nodeRight<=right)
            {
                lazy[node]+=value;
                propagate(nodeLeft,nodeRight,node);
                return tree[node];
            }
        int mid=(nodeLeft+nodeRight)/2;
        return tree[node]=update(left,right,value,nodeLeft,mid,node*2)+update(left,right,value,mid+1,nodeRight,node*2+1);
    }
    int query(int left,int right)
    {
        return query(left,right,0,n-1,1);
    }
    int query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
         propagate(nodeLeft,nodeRight,node);
         if(nodeRight<left||right<nodeLeft) return 0;
        if(left<=nodeLeft&&nodeRight<=right) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    SEG_TREE segY(MAX_N*2),segX(MAX_N*2);
    for(int i=0;i<N;i++)
    {
        int y,x;
        cin>>y>>x;
        v.push_back({y,x});
    }
    v.push_back(v[0]);
    for(int i=1;i<=N;i++)
    {
        if(v[i].first==v[i-1].first)
            segX.update(min(v[i-1].second,v[i].second)+1+MAX_N,max(v[i-1].second,v[i].second)+MAX_N,1);
        else
            segY.update(min(v[i-1].first,v[i].first)+1+MAX_N,max(v[i-1].first,v[i].first)+MAX_N,1);
    }
    int ans=0;
    for(int i=-MAX_N;i<MAX_N;i++)ans=max(ans,(int)max(segY.query(i+MAX_N,i+MAX_N),segX.query(i+MAX_N,i+MAX_N)));
    cout<<ans;
}
