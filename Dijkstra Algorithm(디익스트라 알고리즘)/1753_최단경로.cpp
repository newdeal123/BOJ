//방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오.
//단, 모든 간선의 가중치는 10 이하의 자연수이다.
//
//입력
//첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20, 000, 1≤E≤300, 000) 모든 정점에는
//1부터 V까지 번호가 매겨져 있다고 가정한다.둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다.
//셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수(u, v, w)가 순서대로 주어진다.
//이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다.u와 v는 서로 다르며 w는 10 이하의 자연수이다.
//서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.
//
//출력
//첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다.
//시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 20000 + 2;
const int INF = 987654321;
int V, E, start;
vector <pair<int, int>> node[MAX_V];

vector <int> dijkstra()
{
	vector <int> dis(V + 1, INF);
	dis[start] = 0;
	priority_queue < pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
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
	return dis;
}

int main()
{
	cin >> V >> E;
	cin >> start;
	while (E--)
	{
		int s, f, c;
		cin >> s >> f >> c;
		node[s].push_back(make_pair(f, c));
	}
	vector <int> answer = dijkstra();
	for (int i = 1; i < answer.size(); i++)
	{
		if (answer[i] != INF)
			cout << answer[i] << "\n";
		else
			cout <<"INF" << "\n";
	}
}