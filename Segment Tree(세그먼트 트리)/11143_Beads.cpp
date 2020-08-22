#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

 struct SEG_TREE
 {
 	int n;
 	vector <int> tree;
 	SEG_TREE() {;};
 	SEG_TREE(int len)
 	{
 		n = len;
 		tree.resize(n*4,0);
 	};
    int update(int idx,int value){return update(idx,value,0,n-1,1);}
 	int update(const int idx,const int value,int left,int right,int node)
 	{
 	    if(idx<left||right<idx)return tree[node];
 	    if(left==right)return tree[node]+=value;
 	    int mid=(left+right)/2;
 	    return tree[node]=update(idx,value,left,mid,node*2)+update(idx,value,mid+1,right,node*2+1);
 	}
 	int query(int left,int right) { return query(left,right,1,0,n-1);};
 	int query(const int left,const int right,int node,int nodeLeft,int nodeRight)
 	{
 		if (right<nodeLeft||left>nodeRight) return 0;
 		if (left<=nodeLeft&&right>=nodeRight) return tree[node];
 		int mid=(nodeLeft+nodeRight)/2;
 		return query(left,right,node*2,nodeLeft,mid)+query(left,right,node*2+1,mid+1,nodeRight);

 	}
 };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int N,P,Q;
        cin>>N>>P>>Q;
        SEG_TREE seg(N+1);

        for(int i=0;i<P+Q;i++)
        {
            char type;
            int a,b;
            cin>>type>>a>>b;
            if(type=='P') seg.update(a,b);
            else cout<<seg.query(a,b)<<"\n";
        }
    }

}
