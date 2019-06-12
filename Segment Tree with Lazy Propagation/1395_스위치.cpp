#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1000000+2;
int N,M;

struct SEG_TREE
{
    int n;
    vector <int> tree;
    vector <bool> lazy;
    SEG_TREE(){;};
    SEG_TREE(int s)
    {
        n=s;
        tree.resize(n*4,0),lazy.resize(n*4,0);
    }
    void propagate(int nodeLeft,int nodeRight,int node)
    {
        if(lazy[node])
        {
            if(nodeLeft!=nodeRight)
            {
                lazy[node*2]=!lazy[node*2];
                lazy[node*2+1]=!lazy[node*2+1];
            }
            tree[node]=(nodeRight-nodeLeft+1)-tree[node];
            lazy[node]=0;
        }
    }
    int update(int left,int right)
    {
        return update(left,right,0,n-1,1);
    }
    int update(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        propagate(nodeLeft,nodeRight,node);
        if(nodeRight<left||right<nodeLeft) return tree[node];
        if(left<=nodeLeft&&nodeRight<=right)
            {
                lazy[node]=!lazy[node];
                propagate(nodeLeft,nodeRight,node);
                return tree[node];
            }
        int mid=(nodeLeft+nodeRight)/2;
        return tree[node]=update(left,right,nodeLeft,mid,node*2)+update(left,right,mid+1,nodeRight,node*2+1);
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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    SEG_TREE seg(N);
    while(M--)
    {
        int order,a,b;
        cin>>order;
        if(order==0)
        {
            cin>>a>>b;
            seg.update(a-1,b-1);
        }
        else
        {
            cin>>a>>b;
            cout<<seg.query(a-1,b-1)<<"\n";
        }
    }
}

