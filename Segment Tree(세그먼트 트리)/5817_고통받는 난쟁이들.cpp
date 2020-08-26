#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=987654321;

struct SEG_TREE
{
	int n;
	vector <pair<int, int>> range; //min,max
	SEG_TREE() { ; };
	SEG_TREE(const vector <int>& v)
	{
		n = v.size();
		range.resize(n * 4);
		init(v, 0, n - 1, 1);
	};

	pair<int,int> init(const vector <int> &arr, int left, int right, int node)
	{
		if (left == right)
			return make_pair(range[node].first = arr[left], range[node].second = arr[left]);

		int mid = (left + right) / 2;
		pair <int,int> leftRange = init(arr, left, mid, node * 2);
		pair<int, int> rightRange = init(arr, mid + 1, right, node * 2 + 1);

		int Min = min(leftRange.first, rightRange.first);
		int Max = max(leftRange.second, rightRange.second);

		return range[node] = make_pair(Min, Max);
	}
	pair<int,int>update(const int idx,const int value,int left,int right,int node)
	{
	    if(idx<left||right<idx)return range[node];
	    if(left==right)return range[node]={value,value};
	    int mid=(left+right)/2;
	    pair<int,int> leftRange = update(idx,value,left,mid,node*2);
		pair<int, int> rightRange = update(idx,value,mid+1,right,node*2+1);

		return range[node]={min(leftRange.first,rightRange.first),max(leftRange.second,rightRange.second)};
	}

	pair<int,int> query(const int left, const int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || left > nodeRight)
			return make_pair(INF, 0);
		if (left <= nodeLeft && right >= nodeRight)
			return range[node];

		int mid = (nodeLeft + nodeRight) / 2;
		pair <int, int> leftRange = query(left, right, node * 2, nodeLeft, mid);
		pair <int, int> rightRange = query(left, right, node * 2 + 1, mid + 1, nodeRight);

		return make_pair(min(leftRange.first, rightRange.first), max(leftRange.second, rightRange.second));
	}
    pair<int,int> update(int idx,int value){return update(idx,value,0,n-1,1);}
	pair<int,int> query(int left, int right) { return query(left, right, 1, 0, n - 1); };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;
    vector<int>arr(N+1),loc(N+1);

    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
        loc[arr[i]]=i;
    }
    SEG_TREE seg(loc);
    while(M--)
    {
        int type,a,b;
        cin>>type>>a>>b;
        if(type==1){
            seg.update(arr[a],loc[arr[b]]);
            seg.update(arr[b],loc[arr[a]]);
            swap(loc[arr[a]],loc[arr[b]]);
            swap(arr[a],arr[b]);
        }
        else{
            pair<int,int>ret=seg.query(a,b);
            if(ret.first+(b-a)==ret.second)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

}
