#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,Q;

struct SEG_TREE
{
    int n;
    vector<ll> pSum;
    SEG_TREE(){;};
    SEG_TREE(vector<ll> &arr)
    {
        n=arr.size();
        pSum.resize(n*4,0);
        init(arr,0,n-1,1);
    }
    ll init(vector<ll>&arr,int left,int right,int node)
    {
        if(left==right) return pSum[node]=arr[left];
        int mid=(left+right)/2;
        return pSum[node]=init(arr,left,mid,node*2)+init(arr,mid+1,right,node*2+1);
    }
    ll query(int left,int right){return query(left,right,0,n-1,1);}
    ll query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(left>nodeRight || right<nodeLeft) return 0;
        if(left<=nodeLeft && nodeRight<=right) return pSum[node];

        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
    ll update(int left,int right,ll value) {return update(left,right,value,0,n-1,1);}
    ll update(const int left,const int right,const ll value,int nodeLeft,int nodeRight,int node)
    {
        if(left>nodeRight || right<nodeLeft) return pSum[node];
        if(nodeLeft==nodeRight) return pSum[node]=value;

        int mid=(nodeLeft+nodeRight)/2;
        return pSum[node]=update(left,right,value,nodeLeft,mid,node*2)+update(left,right,value,mid+1,nodeRight,node*2+1);
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>Q;
    vector<ll>v(N);
    for(int i=0;i<N;i++)cin>>v[i];
    SEG_TREE seg(v);
    while(Q--)
    {
        ll a,b;
        cin>>a>>b;
        a--,b--;
        if(a>b)swap(a,b);
        cout<<seg.query(a,b)<<"\n";
        cin>>a>>b;
        a--;
        seg.update(a,a,b);
    }
}
