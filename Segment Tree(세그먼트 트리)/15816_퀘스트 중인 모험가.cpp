#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=1000000+2;
vector<int>tmp;
int Q[MAX_N][3];

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
        if(nodeRight<left||right<nodeLeft) return 0;
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

int cache(int n)
{
    return lower_bound(tmp.begin(),tmp.end(),n)-tmp.begin();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,cnt=1;
    cin>>N;
    vector<int>v(N);
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
        tmp.push_back(v[i]);
    }
    cin>>M;
    for(int i=0;i<M;i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x;
            cin>>x;
            tmp.push_back(x);
            Q[i][0]=type,Q[i][1]=x;
        }
        if(type==2)
        {
            int left,right;
            cin>>left>>right;
            tmp.push_back(left),tmp.push_back(right);
            Q[i][0]=type,Q[i][1]=left,Q[i][2]=right;
        }
    }
    sort(tmp.begin(),tmp.end());
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
    SEG_TREE seg(tmp.size());

    for(int i=0;i<v.size();i++)
        seg.update(cache(v[i]));


    for(int i=0;i<M;i++)
    {
        if(Q[i][0]==1)
        {
            int x=cache(Q[i][1]);
            seg.update(x);
        }
        else
        {
            int left=cache(Q[i][1]),right=cache(Q[i][2]);
            cout<<Q[i][2]-Q[i][1]+1-seg.query(left,right)<<"\n";
        }
    }
}
