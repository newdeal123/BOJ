//N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.
//
//어느 날 이 N명의 학생이 X(1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다.
//이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.
//
//각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다.
//하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.
//
//이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다.
//N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.
//
//입력
//첫째 줄에 N(1 <= N <= 1, 000), M(1 <= M <= 10, 000), X가 공백으로 구분되어 입력된다.
//두 번째 줄부터 M + 1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다.
//
//모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.
//
//출력
//첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, X;
const int MAX_N = 1000 + 2;
const int INF = 987654321;

vector <pair<int, int>> node[MAX_N];
int distSum[MAX_N] = { 0, };

int dijkstra(int start,int fin)
{
	vector <int> dis(N + 1, INF);
	dis[start] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > dis[now])
			continue;
		for (int i = 0; i < node[now].size(); i++)
		{
			int next = node[now][i].first;
			int nextDist = node[now][i].second + cost;
			if (nextDist < dis[next])
			{
				dis[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
	return dis[fin];
}

int main()
{
	int maxDist = 0;
	cin >> N >> M >> X;
	while (M--)
	{
		int start, fin, cost;
		cin >> start >> fin >> cost;
		node[start].push_back(make_pair(fin, cost));
	}
	for (int i = 1; i <= N; i++)
	{
		distSum[i] += dijkstra(i, X) + dijkstra(X, i);
		maxDist = max(maxDist, distSum[i]);
	}

	cout << maxDist;
}