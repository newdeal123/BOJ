#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
const int MAX_N = 1e5 + 2;

struct Interval{
	int start, fin;
};
bool comp(Interval& a, Interval& b) {
	if (a.start != b.start)return a.start > b.start;
	else return a.fin < b.fin;
}

struct SEG_TREE
{
	int n;
	vector<pair<int,int>>tree;
	SEG_TREE(int len) {
		n = len;
		tree.resize(n * 4, { 0,-1 });
	}
	pair<int,int> query(int right) { return query(1, right, 1, n, 1); }
	pair<int,int> query(const int left, const int right, int nodeLeft, int nodeRight, int node) {
		if (nodeRight < left || right < nodeLeft)return { 0,-1 };
		if (left <= nodeLeft&&nodeRight <= right)return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;
		pair<int, int>leftQuery = query(left, right, nodeLeft, mid, node * 2);
		pair<int, int>rightQuery = query(left, right, mid + 1, nodeRight, node * 2 + 1);
		if (leftQuery.first > rightQuery.first)return leftQuery;
		else return rightQuery;
	}
	pair<int,int> update(int prevIdx,int idx, int value) { return update(prevIdx,idx, value, 1, n, 1); }
	pair<int,int> update(const int prevIdx,const int idx,const int value, int left, int right, int node) {
		if (idx < left || right < idx)	return tree[node];
		if (left == right) return tree[node] = max(tree[node], { value,prevIdx });

		int mid = (left + right) / 2;
		pair<int, int>leftQuery = update(prevIdx, idx, value, left, mid, node * 2);
		pair<int, int>rightQuery = update(prevIdx, idx, value, mid + 1, right, node * 2 + 1);
		if (leftQuery.first > rightQuery.first)return tree[node] = leftQuery;
		else return tree[node] = rightQuery;
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, ret = 0;
	cin >> N;
	vector<Interval>v;
	vector<int>finV;
	for (int i = 0; i < N;i++) {
		int a, b;
		cin >> a >> b;
		//a = i + 1, b = i + 1 + MAX_N;
		v.push_back({ a,b });
		finV.push_back(b);
	}
	sort(v.begin(), v.end(), comp);
	sort(finV.begin(), finV.end());

	map<int, int>cache;
	int cnt = 1;
	for (int i : finV) {
		if (cache.find(i) == cache.end()) 
			cache.insert({ i,cnt++ });
	}

	SEG_TREE seg(MAX_N);
	int idx = -1;
	vector<int>prev(N, -1);
	for (int i = 0; i < N; i++) {
		int fin = cache[v[i].fin];
		pair<int, int>q = seg.query(fin);
		int maxValue = q.first;
		prev[i] = q.second;
		if (ret < maxValue + 1) {
			ret = maxValue + 1;
			idx = i;
		}
		seg.update(i, fin, maxValue + 1);
	}
	cout << ret << "\n";
	for (int i = idx; ; i = prev[i])
	{
		cout << v[i].start << " " << v[i].fin << "\n";
		if (prev[i] == -1)break;
	}
}