#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int INF=987654321;
int N,M;
struct SEG_TREE
{
	int n;
	vector <int> tree;
	SEG_TREE() { ; };
	SEG_TREE(const vector <int>& v)
	{
		n = v.size();
		tree.resize(n * 4);
		init(v, 0, n - 1, 1);
	};
	int init(const vector <int> &arr, int left, int right, int node)
	{
		if (left == right) return tree[node] = arr[left];
		int mid = (left + right) / 2;
		return tree[node]=min(init(arr,left,mid,node*2),init(arr,mid+1,right,node*2+1));
	}
	int query(int left,int right) { return query(left, right, 1, 0, n - 1); };
	int query(const int left, const int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || left > nodeRight)return INF;
		if (left <= nodeLeft && right >= nodeRight)return tree[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left,right,node*2,nodeLeft,mid),query(left,right,node*2+1,mid+1,nodeRight));
	}
	int update(int idx,int value){return update(idx,value,0,n-1,1);}
	int update(const int idx,const int value,int left,int right,int node)
	{
	    if(right<idx||idx<left)return tree[node];
	    if(left==right)return tree[node]=value;
	    int mid=(left+right)/2;
	    return tree[node]=min(update(idx,value,left,mid,node*2),update(idx,value,mid+1,right,node*2+1));
	}
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    vector<int>v(N);
    for(auto &i:v)cin>>i;
    SEG_TREE seg(v);
    cin>>M;
    while(M--)
    {
        int order,a,b;
        cin>>order;
        if(order==1)
        {
            cin>>a>>b;
            seg.update(a-1,b);
        }
        else
        {
            cin>>a>>b;
            cout<<seg.query(a-1,b-1)<<"\n";
        }


    }
}
