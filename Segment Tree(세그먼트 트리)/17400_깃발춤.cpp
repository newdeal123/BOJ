#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

struct SEG_TREE
{
	int n;
	vector<ll>tree;
	SEG_TREE() { ; }
	SEG_TREE(vector<int>&v)
	{
		n = v.size();
		tree.resize(n * 4);
		init(v, 0, n - 1, 1);
	}
	ll init(vector<int>&v, int left, int right, int node)
	{
		if (left == right)return tree[node] = v[left];
		int mid = (left + right) / 2;
		return tree[node] = init(v, left, mid, node * 2) + init(v, mid + 1, right, node * 2 + 1);
	}
	ll query(int left, int right) { return query(left, right, 0, n - 1, 1); }
	ll query(const int left, const int right, int nodeLeft, int nodeRight, int node)
	{
		if (nodeRight<left || right<nodeLeft) return 0;
		if (left <= nodeLeft&&nodeRight <= right)return tree[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, nodeLeft, mid, node * 2) + query(left, right, mid + 1, nodeRight, node * 2 + 1);
	}
	ll update(int idx, int value) { return update(idx, value, 0, n - 1, 1); }
	ll update(const int idx, const int value, int left, int right, int node)
	{
		if (idx<left || right<idx)return tree[node];
		if (left == right)return tree[node] += value;
		int mid = (left + right) / 2;
		return tree[node] = update(idx, value, left, mid, node * 2) + update(idx, value, mid + 1, right, node * 2 + 1);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, q;
	cin >> N >> q;
	vector<int>v(N), EVEN(N, 0), ODD(N, 0);
	for (int i = 0; i<N; i++)cin >> v[i];
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)EVEN[i] = v[i];
		else ODD[i] = v[i];
	}
	SEG_TREE even_seg(EVEN), odd_seg(ODD);
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int left, right, sum = 0;
			cin >> left >> right;
			left--, right--;
			cout << abs(even_seg.query(left, right) - odd_seg.query(left, right)) << "\n";
		}
		else
		{
			int k, value;
			cin >> k >> value;
			k--;
			if (k % 2 == 0)even_seg.update(k, value);
			else odd_seg.update(k, value);
		}
	}

}
