#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;


struct SEG_TREE
{
	int n;
	vector <ll> sum;
	SEG_TREE() { ; };
	SEG_TREE(const vector <ll>& arr)
	{
		n = arr.size();
		sum.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}

	ll init(const vector <ll>& arr, int left, int right, int node)
	{
		if (left == right)
			return sum[node] = arr[left];
		int mid = (left + right) / 2;
		ll leftSum = init(arr, left, mid, node * 2);
		ll rightSum = init(arr, mid + 1, right, node * 2 + 1);
		return sum[node] = leftSum + rightSum;
	}

	ll output(const int left, const int right, int node, int nodeLeft, int nodeRight)
	{
		if (nodeRight < left || nodeLeft > right)
			return 0;
		if (left <= nodeLeft && nodeRight <= right)
			return sum[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return output(left, right, node * 2, nodeLeft, mid) + output(left, right, node * 2 + 1, mid + 1, nodeRight);
	}

	ll update(int idx, int newValue, int node, int nodeLeft, int nodeRight)
	{
		if (nodeLeft > idx || idx > nodeRight)
			return sum[node];
		if (nodeLeft == nodeRight)
			return sum[node] = newValue;

		int mid = (nodeLeft + nodeRight) / 2;
		return sum[node] = update(idx, newValue, node * 2, nodeLeft, mid) + update(idx, newValue, node * 2 + 1, mid + 1, nodeRight);
	}

	ll output(int left, int right) { return output(left, right, 1, 0, n - 1); };
	ll update(int idx, int newValue) { return update(idx, newValue, 1, 0, n - 1); };
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	vector <ll> v;
	while (N--)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	SEG_TREE seg(v);
	int t = M + K;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			seg.update(b - 1, c);
		if (a == 2)
			cout << seg.output(b - 1, c - 1) << "\n";

	}
}