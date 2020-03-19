#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<char>card;
vector<pair<int, char>>adj[501];
int N, M, K, cache[1001][501];

int f(int idx, int now) {
	if (idx == N)return 0;

	int&ret = cache[idx][now];
	if (ret != -1)return ret;
	ret = 0;
	char thisCard = card[idx];
	for (auto i : adj[now]) {
		int next = i.first;
		char nextCard = i.second;
		if (thisCard == nextCard)ret = max(ret, f(idx + 1, next) + 10);
		else ret = max(ret, f(idx + 1, next));
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	card.resize(N);
	for (auto&i : card)cin >> i;
	cin >> M >> K;
	while (K--) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	cout << f(0, 1);
}