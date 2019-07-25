#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
const int MAX_V = 100 + 2;
int N, M, dist[MAX_V][MAX_V];

struct UNION_FIND
{
	vector <int>parent, height;
	UNION_FIND() { ; };
	UNION_FIND(int n)
	{
		parent.resize(n + 1), height.resize(n + 1, 1);
		for (int i = 0; i <= n; i++) parent[i] = i;
	}
	int find(int n)
	{
		if (n == parent[n]) return n;
		return find(parent[n]);
	}
	void merge(int u, int v)
	{
		u = find(u), v = find(v);
		if (u == v) return;
		if (height[u] > height[v]) swap(u, v);
		parent[u] = v;
		if (height[u] == height[v]) height[v]++;
	}
	void getUnion(vector<vector<int>> &v)
	{
		vector<int> p;
		for (int i = 1; i <= N; i++)
		{
			bool flag = false;
			for (auto j : p) if (j == find(i)) flag = true;
			if (!flag) p.push_back(find(i));
		}
		v.resize(p.size());
		for (int i=0;i<p.size();i++)
		{
			for (int j = 1; j <= N; j++) if (find(j) == p[i]) v[i].push_back(j);
		}
	}
};

void floyd()
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
	for (int i = 0; i < MAX_V; i++)
		for (int j = 0; j < MAX_V; j++)
			dist[i][j] = i == j ? 0 : INF;
	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	floyd();
	UNION_FIND disjoint(N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (dist[i][j] != INF) disjoint.merge(i, j);
	vector<vector<int>> ans;
	vector<int>v;
	disjoint.getUnion(ans);
	cout << ans.size() << endl;
	for (int n = 0; n < ans.size(); n++)
	{
		int center, minN = INF;
		for (auto i : ans[n])
		{
			int tmp = 0;
			for (int j = 1; j <= N; j++)
				if (dist[i][j] != INF)
				{
					tmp = max(tmp, dist[i][j]);
				}
			if (tmp < minN) center = i, minN = tmp;
		}
		v.push_back(center);
	}
	sort(v.begin(), v.end());
	for (auto i : v) cout << i << "\n";
}