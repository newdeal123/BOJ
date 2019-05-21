#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int INF = 987654321;
int init(const vector <int> &arr, int start, int fin, int n);

struct SEG_TREE
{
	int n;
	vector <int> rangeMin;
	SEG_TREE() { ; };
	SEG_TREE(const vector <int>& v)
	{
		n = v.size();
		rangeMin.resize(n * 4);
		init(v, 0, n - 1, 1);
	};

	int init(const vector <int> &arr, int left, int right, int node)
	{
		if (left == right)
			return rangeMin[node] = arr[left];

		int mid = (left + right) / 2;
		int leftMin = init(arr, left, mid, node * 2);
		int rightMin = init(arr, mid + 1, right, node * 2 + 1);

		return rangeMin[node] = min(rightMin, leftMin);
	}

	int query(const int left, const int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || left > nodeRight)
			return INF;
		if (left <= nodeLeft && right >= nodeRight)
			return rangeMin[node];

		int mid = (nodeLeft + nodeRight) / 2;
		int leftMin = query(left, right, node * 2, nodeLeft, mid);
		int rightMin = query(left, right, node * 2 + 1, mid + 1, nodeRight);

		return min(leftMin, rightMin);
	}

	int get_query(int left, int right) { return query(left, right, 1, 0, n - 1); };
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector <int> v;
	while (N--)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	SEG_TREE tree(v);
	while (M--)
	{
		int left, right;
		cin >> left >> right;
		cout << tree.get_query(left-1, right-1) << "\n";
	}
}