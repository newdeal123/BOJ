#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
const int INF = 987654321;
int N, M;
vector<pair<int, int>>adj[500 + 2];

bool discoverd[502], finished[502];
bool cycle = false;

void dfs(int u)
{
	discoverd[u] = true;
	for (auto v : adj[u])
	{
		if (v.second > 0)continue;
		if (!discoverd[v.first]) dfs(v.first);
		else if (!finished[v.first]) cycle = true;
	}
	finished[u] = true;
}

vector<int>bellmanFord()
{
	vector<int>upper(N + 1, INF);
	upper[1] = 0;
	bool updated = false;
	for (int i = 1; i <= N; i++)
	{
		updated = false;
		for (int now = 1; now <= N; now++)
			for (auto j : adj[now])
			{
				int next = j.first, cost = j.second;
				if (upper[now] != INF&&upper[next]>upper[now] + cost)
				{
					upper[next] = upper[now] + cost;
					updated = true;
				}
			}
		if (!updated)break;
	}
	if (updated)upper.clear();
	return upper;
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	bool allM = true;
	while (M--)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ v,cost });
	}
	dfs(1);
	if (cycle) { cout << -1; return 0; }
	vector<int>ans = bellmanFord();
	if (ans.empty())cout << -1;
	else
	{
		for (int i = 2; i <= N; i++)cout << (ans[i] == INF ? -1 : ans[i]) << "\n";
	}
}
