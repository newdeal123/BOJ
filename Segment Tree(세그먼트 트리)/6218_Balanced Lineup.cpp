#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int INF = (int)1E9 + 1;

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

	pair<int,int> get_query(int left, int right) { return query(left, right, 1, 0, n - 1); };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,Q;
    cin>>N>>Q;
    vector<int>v(N);
    for(auto&i:v)cin>>i;
    SEG_TREE seg(v);
    while(Q--)
    {
        int a,b;
        cin>>a>>b;
        pair<int,int>ans=seg.get_query(a-1,b-1);
        cout<<ans.second-ans.first<<"\n";
    }
}
