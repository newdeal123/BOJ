#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int K, N, R;
const int MAX_N = 10000 + 2, INF = 987654321;
struct Edge {
	int v, len, cost;
};
vector<Edge>adj[MAX_N];

bool operator <(Edge a, Edge b) {
	return a.cost < b.cost;
}

int dijkstra() {
	priority_queue<Edge>pq;
	pq.push({ 1,0,K });
	vector<int>dist[101];
	for (int i = 1; i <= N; i++) {
		dist[i].resize(K+1,INF);
	}
	dist[1][K] = 0;
	while (!pq.empty()) {
		int now = pq.top().v;
		int nowLen = pq.top().len, nowCost = pq.top().cost;
		pq.pop();
		//cout << now << "\n";
		if (nowLen > dist[now][nowCost])continue;
		for (auto i : adj[now]) {
			int next = i.v, nextLen = i.len + nowLen, nextCost = nowCost - i.cost;
			if (nextCost < 0 || dist[next][nextCost] < nextLen)continue;
			pq.push({ next,nextLen,nextCost });
			dist[next][nextCost] = nextLen;
		}
	}
	int ret = INF;
	for (int i = 0; i <= K; i++)ret = min(ret, dist[N][i]);
	return (ret == INF ? -1 : ret);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> K >> N >> R;
	while (R--) {
		int u, v, l, t;
		cin >> u >> v >> l >> t;
		adj[u].push_back({ v,l,t });
	}
	cout << dijkstra();
	
}