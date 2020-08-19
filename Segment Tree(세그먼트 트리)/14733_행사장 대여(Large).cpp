#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_M=5e4;
const int MAX_N=MAX_M*2+2;

struct SEG_TREE
{
    int n;
    vector<int>tree,cnt;
    SEG_TREE(int len)
    {
        n=len;
        tree.resize(n*4,0),cnt.resize(n*4,0);
    }
    void update(int left,int right,int value){return update(left,right,value,0,n-1,1);}
    void update(const int left,const int right,const int value,int nodeLeft,int nodeRight,int node)
    {
        if(right<nodeLeft||nodeRight<left)return ;
        if(left<=nodeLeft&&nodeRight<=right)cnt[node]+=value;
        else
        {
            int mid=(nodeLeft+nodeRight)/2;
            update(left,right,value,nodeLeft,mid,node*2);
            update(left,right,value,mid+1,nodeRight,node*2+1);
        }

        if(cnt[node])tree[node]=(nodeRight-nodeLeft+1);
        else
        {
            if(nodeLeft==nodeRight)tree[node]=0;
            else tree[node]=tree[node*2+1]+tree[node*2];
        }
    }
    int query(int node){return tree[node];}

};

struct NODE
{
    int x,dy,uy,value;
};

bool compare(NODE a,NODE b)
{
    return a.x<b.x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll sum=0;
    int N;
    cin>>N;
    vector<NODE>v;
    for(int i=0;i<N;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1+=MAX_M,y1+=MAX_M,x2+=MAX_M,y2+=MAX_M;
        v.push_back({x1,y1,y2-1,1});
        v.push_back({x2,y1,y2-1,-1});
    }
    sort(v.begin(),v.end(),compare);
    SEG_TREE seg(MAX_N);
    int lastX=-1;
    for(auto i:v)
    {
        if(lastX!=-1)
            sum+=(i.x-lastX)*seg.query(1);

        seg.update(i.dy,i.uy,i.value);
        lastX=i.x;
    }
    cout<<sum;
}
