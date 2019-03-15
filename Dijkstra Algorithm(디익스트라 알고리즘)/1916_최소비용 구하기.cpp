#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 1000 + 2;
const int INF = 987654321;
int N;
vector <pair<int, int>> node[MAX_N];

int dijkstra(int start, int fin)
{
	vector <int> dist(N + 1, INF);
	priority_queue <pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost)
			continue;
		for (int i = 0; i < node[now].size(); i++)
		{
			int next = node[now][i].first;
			int nextDist = cost +  node[now][i].second;
			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
	return dist[fin];
}

int main()
{
	int M;
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		int start, fin, cost;
		cin >> start >> fin >> cost;
		node[start].push_back(make_pair(fin, cost));
	}
	int s, f;
	cin >> s >> f;
	cout << dijkstra(s, f);
}
