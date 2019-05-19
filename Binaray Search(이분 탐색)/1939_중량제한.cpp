#include  <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 987654321;
const int MAX_N = 100000 + 2;
int N, M, start, fin;
vector<pair<int, int>> node[MAX_N];

bool can_bfs(int weight)
{
	bool visited[MAX_N] = { 0, };
	queue <int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (auto next : node[now])
		{
			if (next.second < weight || visited[next.first]) continue;
			visited[next.first] = true;
			q.push(next.first);
		}
	}
	if (visited[fin])
		return true;
	else
		return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int maxW = 0;
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		maxW = max(maxW, c);
		node[a].push_back(make_pair(b, c));
		node[b].push_back(make_pair(a, c));
	}
	cin >> start >> fin;
	int left = 1, right = maxW;
	int ret = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (can_bfs(mid))
		{
			ret = max(ret, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ret;
}