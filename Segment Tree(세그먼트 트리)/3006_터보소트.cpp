#include<bits/stdc++.h>
using namespace std;
const int MAX_N=(int)1e5+2;
int arr[MAX_N],loc[MAX_N];

struct SEG_TREE
{
    int n;
    vector<int>tree;
    SEG_TREE(){;}
    SEG_TREE(int s)
    {
        n=s;
        tree.resize(n*4,0);
        init(0,n-1,1);
    }
    int init(int left,int right,int node)
    {
        if(left==right)return tree[node]=1;
        int mid=(left+right)/2;
        return tree[node]=init(left,mid,node*2)+init(mid+1,right,node*2+1);
    }
    int update(int loc) {return update(loc,0,n-1,1);}
    int update(const int loc,int left,int right,int node)
    {
        if(loc<left||right<loc) return tree[node];
        if(left==right) return tree[node]-=1;
        int mid=(left+right)/2;
        return tree[node]=update(loc,left,mid,node*2)+update(loc,mid+1,right,node*2+1);

    }
    int query(int left,int right){return query(left,right,0,n-1,1);}
    int query(const int left,const int right,int nodeLeft,int nodeRight,int node)
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
    int N;
    cin>>N;
    SEG_TREE seg(N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        loc[arr[i]]=i;
    }
    for(int q=1;q<=N;q++)
    {
        if(q%2==1)
        {
            int tmp=q/2+1;
            seg.update(loc[tmp]);
            cout<<seg.query(0,loc[tmp])<<"\n";
        }
        else
        {
            int tmp=N-(q/2-1);
            seg.update(loc[tmp]);
            cout<<seg.query(loc[tmp],N-1)<<"\n";
        }
    }
}
