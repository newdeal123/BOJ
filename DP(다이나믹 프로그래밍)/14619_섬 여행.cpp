#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N, M;
int height[101], cache[101][501];
vector<int>adj[101];

int f(int now, int move)
{
	if (move == 0)return height[now];
	
	int&ret = cache[now][move];
	if (ret != -1)return ret;
	ret = INF;

	for (auto next : adj[now])
		ret = min(ret, f(next, move - 1));
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++)cin >> height[i];
	while (M--)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int now, K;
		cin >> now >> K;
		int ans = f(now - 1, K);
		cout << (ans==INF?-1:ans) << "\n";
	}
}