#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SEG_TREE
{
    int n;
    vector<ll> tree;
    SEG_TREE(){;};
    SEG_TREE(int N)
    {
        n=N;
        tree.resize(n*4,0);
    }
    ll query(int left,int right){return query(left,right,0,n-1,1);}
    ll query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(left>nodeRight || right<nodeLeft) return 0;
        if(left<=nodeLeft && nodeRight<=right) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;

        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
    ll update(int k,ll value) {return update(k,value,0,n-1,1);}
    ll update(const int k,const ll value,int nodeLeft,int nodeRight,int node)
    {
        if(k>nodeRight || k<nodeLeft) return tree[node];
        if(nodeLeft==nodeRight) return tree[node]=value;

        int mid=(nodeLeft+nodeRight)/2;
        return tree[node]=update(k,value,nodeLeft,mid,node*2)+update(k,value,mid+1,nodeRight,node*2+1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,M;
    cin>>N>>M;
    SEG_TREE seg(N);
    while(M--)
    {
        ll type,a,b;
        cin>>type>>a>>b;
    
        if(!type)
            {
                if(a>b) swap(a,b);
                cout<<seg.query(a-1,b-1)<<"\n";
            }
        else
            seg.update(a-1,b);
    }

}
