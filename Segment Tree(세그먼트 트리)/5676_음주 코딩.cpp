#include <bits/stdc++.h>
using namespace std;

int change(int n)
{
    if(n>0) return 1;
    else if(n<0) return -1;
    else return 0;
}

struct SEG_TREE
{
    int n;
    vector<int> tree;
    SEG_TREE(){;};
    SEG_TREE(vector<int>&arr)
    {
        n=arr.size();
        tree.resize(n*4,0);
        init(arr,0,n-1,1);
    }
    int init(vector<int>&arr,int left,int right,int node)
    {
        if(left==right) return tree[node]=arr[left];
        int mid=(left+right)/2;
        return tree[node]=init(arr,left,mid,node*2)*init(arr,mid+1,right,node*2+1);
    }
    int query(int left,int right){return query(left,right,0,n-1,1);}
    int query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(left>nodeRight || right<nodeLeft) return 1;
        if(left<=nodeLeft && nodeRight<=right) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;

        return query(left,right,nodeLeft,mid,node*2)*query(left,right,mid+1,nodeRight,node*2+1);
    }
    int update(int k,int value) {return update(k,value,0,n-1,1);}
    int update(const int k,const int value,int nodeLeft,int nodeRight,int node)
    {
        if(k>nodeRight || k<nodeLeft) return tree[node];
        if(nodeLeft==nodeRight) return tree[node]=value;

        int mid=(nodeLeft+nodeRight)/2;
        return tree[node]=update(k,value,nodeLeft,mid,node*2)*update(k,value,mid+1,nodeRight,node*2+1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N,K;
    while(cin>>N>>K)
    {
        vector<int> v(N);
        for(int i=0;i<N;i++)
        {
            int tmp;
            cin>>tmp;
            v[i]=change(tmp);
        }
        SEG_TREE seg(v);
        string s;
        while(K--)
        {
            char c;
            int a,b;
            cin>>c>>a>>b;
            if(c=='C')
                seg.update(a-1,change(b));
            else
            {
                int type=seg.query(a-1,b-1);
                if(type>0) s+="+";
                else if(type<0) s+="-";
                else s+="0";
            }
        }
        cout<<s<<"\n";
    }
}
