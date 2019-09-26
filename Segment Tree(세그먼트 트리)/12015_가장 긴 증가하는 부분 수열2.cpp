#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;

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
 	    if(left==right)return tree[node]=value;
 	    int mid=(left+right)/2;
 	    return tree[node]=max(update(idx,value,left,mid,node*2),update(idx,value,mid+1,right,node*2+1));
 	}
 	int query(int left,int right) { return query(left,right,1,0,n-1);};
 	int query(const int left,const int right,int node,int nodeLeft,int nodeRight)
 	{
 		if (right<nodeLeft||left>nodeRight) return 0;
 		if (left<=nodeLeft&&right>=nodeRight) return tree[node];
 		int mid=(nodeLeft+nodeRight)/2;

 		int leftMax=query(left,right,node*2,nodeLeft,mid);
 		int rightMax=query(left,right,node*2+1,mid+1,nodeRight);

 		return max(leftMax, rightMax);
 	}
 	int answer(){return tree[1];}

 };
bool compare(pair<int,int> p1,pair<int,int> p2)
{
    if (p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int findLIS(vector<int> arr, int n)
{
    pair<int, int> p[n];
    for (int i=0;i<n;i++)
    {
        p[i].first=arr[i];
        p[i].second=i;
    }
    sort(p,p+n,compare);
    SEG_TREE seg(n);
    for (int i=0;i<n;i++)
        seg.update(p[i].second,seg.query(0,p[i].second)+1);

    return seg.answer();
}

 int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int N;
     cin>>N;
     vector<int>v(N);
     for(int i=0;i<N;i++)cin>>v[i];
     cout<<findLIS(v,N);
 }

