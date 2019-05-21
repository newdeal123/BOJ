#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

struct SEG_TREE
{
	int n;
	vector <ll> pMultiple;
	SEG_TREE() { ; };
	SEG_TREE(vector <ll> &v)
	{
		n = v.size();
		pMultiple.resize(n * 4);
		init(v, 0, n - 1, 1);
	}
	ll init(vector <ll>&arr, int left, int right, int node)
	{
		if (left == right)
			return pMultiple[node] = arr[left] % MOD;

		int mid = (left + right) / 2;
		ll leftRange = init(arr, left, mid, node * 2) % MOD;
		ll rightRange = init(arr, mid + 1, right, node * 2 + 1) % MOD;

		return pMultiple[node] = leftRange*rightRange%MOD;
	}

	ll output(const int left, const int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left) return 1;
		if (left <= nodeLeft && nodeRight <= right) return pMultiple[node] % MOD;

		int mid = (nodeLeft + nodeRight) / 2;
		ll leftRange = output(left, right, node * 2, nodeLeft, mid) % MOD;
		ll rightRange = output(left, right, node * 2 + 1, mid + 1, nodeRight) % MOD;

		return leftRange*rightRange%MOD;
	}
	ll output(int left, int right) { return output(left, right, 1, 0, n - 1); };

	ll update(const int idx, const int newValue, int nodeLeft, int nodeRight, int node)
	{
		if (idx < nodeLeft || nodeRight < idx) return pMultiple[node] % MOD;
		if (nodeLeft == nodeRight) return pMultiple[node] = newValue%MOD;

		int mid = (nodeLeft + nodeRight) / 2;
		ll leftRange = update(idx, newValue, nodeLeft, mid, node * 2) % MOD;
		ll rightRange = update(idx, newValue, mid + 1, nodeRight, node * 2 + 1) % MOD;

		return pMultiple[node] = leftRange*rightRange%MOD;
	}

	ll update(int idx, int newValue) { return update(idx, newValue, 0, n - 1, 1); };
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
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	SEG_TREE st(v);
	int t = M + K;
	while (t--)
	{
		int state;
		cin >> state;
		if (state == 1)
		{
			int idx, newValue;
			cin >> idx >> newValue;
			st.update(idx - 1, newValue);
		}
		else
		{
			int left, right;
			cin >> left >> right;
			cout << st.output(left - 1, right - 1) << "\n";
		}
	}
}