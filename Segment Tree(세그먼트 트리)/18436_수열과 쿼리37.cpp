#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int INF=987654321,MAX_N=30000+2;

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
    int N,M;
    cin>>N;
    vector<int>v(N);
    for(auto&i:v)cin>>i;
    cin>>M;
    SEG_TREE odd(N),even(N);
    for(int i=0;i<N;i++)
    {
        if(v[i]%2==0)even.update(i,1);
        else odd.update(i,1);
    }
    while(M--)
    {
        int type,a,b;
        cin>>type>>a>>b;
        if(type==1)
        {
            if(v[a-1]%2==0)even.update(a-1,-1);
            else odd.update(a-1,-1);

            if(b%2==0)even.update(a-1,1);
            else odd.update(a-1,1);
            v[a-1]=b;
        }
        else if(type==2) cout<<even.query(a-1,b-1)<<"\n";
        else cout<<odd.query(a-1,b-1)<<"\n";
    }
}
