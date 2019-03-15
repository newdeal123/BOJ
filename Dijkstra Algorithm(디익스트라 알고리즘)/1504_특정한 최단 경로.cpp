//방향성이 없는 그래프가 주어진다.세준이는 1번 정점에서 N번 정점으로 최단 거리로 이동하려고 한다.
//또한 세준이는 두 가지 조건을 만족하면서 이동하는 특정한 최단 경로를 구하고 싶은데, 그것은 바로 임의로 주어진 두 정점은 반드시 통과해야 한다는 것이다.
//
//세준이는 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 수 있다.
//하지만 반드시 최단 경로로 이동해야 한다는 사실에 주의하라. 1번 정점에서 N번 정점으로 이동할 때,
//주어진 두 정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 정점의 개수 N과 간선의 개수 E가 주어진다. (2 ≤ N ≤ 800, 0 ≤ E ≤ 200, 000) 
//둘째 줄부터 E개의 줄에 걸쳐서 세 개의 정수 a, b, c가 주어지는데, a번 정점에서 b번 정점까지 양방향 길이 존재하며, 
//그 거리가 c라는 뜻이다. (1 ≤ c ≤ 1, 000) 다음 줄에는 반드시 거쳐야 하는 두 개의 서로 다른 정점 번호가 주어진다.
//
//출력
//첫째 줄에 두 개의 정점을 지나는 최단 경로의 길이를 출력한다.그러한 경로가 없을 때에는 - 1을 출력한다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 800 + 2;
const int INF = 987654321;
vector <pair<int, int>> node[MAX_N];
int N, E;

int dijkstra(int start, int fin)
{
	vector <int> dist(N+1, INF);
	dist[start] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (cost > dist[now])
			continue;
		for (int i = 0; i < node[now].size(); i++)
		{
			int next = node[now][i].first;
			int  nextDist = cost + node[now][i].second;
			if (nextDist < dist[next])
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
	cin >> N >> E;
	while (E--)
	{
		int start, fin, cost;
		cin >> start >> fin >> cost;
		node[start].push_back(make_pair(fin, cost));
		node[fin].push_back(make_pair(start, cost));
	}
	int fin1, fin2;
	cin >> fin1 >> fin2;
	int sum = min(dijkstra(1, fin1) + dijkstra(fin1, fin2) + dijkstra(fin2, N), dijkstra(1, fin2) + dijkstra(fin2, fin1) + dijkstra(fin1, N));
	if (sum >= INF || sum < 0)
		cout << "-1";
	else
		cout << sum;
}