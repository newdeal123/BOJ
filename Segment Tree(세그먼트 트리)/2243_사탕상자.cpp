#include <bits/stdc++.h>
using namespace std;
int N;
const int MAX_N=(int)1E6+1;

struct SEG_TREE
{
    int n;
    bool found;
    vector<int> pSum;
    SEG_TREE(){;};
    SEG_TREE(int N)
    {
        n=N;
        pSum.resize(n*4,0);
    }
    int query(int k)
    {
        found=false;
        return query(k,0,n-1,1);
    }
    int query(int k,int nodeLeft,int nodeRight,int node)
    {
        if(!found && nodeLeft==nodeRight)
        {
            found=true;
            return nodeLeft;
        }

        int mid=(nodeLeft+nodeRight)/2;
        if(!found && node*2<=pSum.size() && k<=pSum[node*2])
            return query(k,nodeLeft,mid,node*2);
        else if(!found)
            return query(k-pSum[node*2],mid+1,nodeRight,node*2+1);

    }
    int update(int k,int value) {return update(k,value,0,n-1,1);}
    int update(const int k,const int value,int nodeLeft,int nodeRight,int node)
    {
        if(k>nodeRight || k<nodeLeft) return pSum[node];
        if(nodeLeft==nodeRight) return pSum[node]+=value;

        int mid=(nodeLeft+nodeRight)/2;
        return pSum[node]=update(k,value,nodeLeft,mid,node*2)+update(k,value,mid+1,nodeRight,node*2+1);
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    SEG_TREE seg(MAX_N);
    while(N--)
    {
        int type,a,b;
        cin>>type;
        if(type==1)
        {
            cin>>a;
           int idx=seg.query(a);
           cout<<idx<<"\n";
           seg.update(idx,-1);
        }
        else
        {
            cin>>a>>b;
            seg.update(a,b);
        }
    }
}
