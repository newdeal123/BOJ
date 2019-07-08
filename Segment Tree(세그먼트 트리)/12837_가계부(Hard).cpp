#include<bits/stdc++.h>
using namespace std;
const int MAX_N=(int)1e6+2;
typedef long long ll;

struct SEG_TREE
{
    int n;
    vector<ll>tree;
    SEG_TREE(){;}
    SEG_TREE(int s)
    {
        n=s;
        tree.resize(n*4,0);
    }
    ll update(int day,ll value) {return update(day,value,0,n-1,1);}
    ll update(const int day,const ll value,int left,int right,int node)
    {
        if(day<left||right<day) return tree[node];
        if(left==right) return tree[node]+=value;
        int mid=(left+right)/2;
        return tree[node]=update(day,value,left,mid,node*2)+update(day,value,mid+1,right,node*2+1);

    }
    ll query(int left,int right){return query(left,right,0,n-1,1);}
    ll query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(left>nodeRight || right<nodeLeft) return 0;
        if(left<=nodeLeft && nodeRight<=right) return tree[node];

        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }

};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin>>N>>Q;
    SEG_TREE seg(N);
    while(Q--)
    {
        int type,p,q;
        cin>>type>>p>>q;
        if(type==1)
        {
            p--;
            seg.update(p,q);
        }
        else
        {
            p--;
            q--;
            cout<<seg.query(p,q)<<"\n";
        }
    }
}
