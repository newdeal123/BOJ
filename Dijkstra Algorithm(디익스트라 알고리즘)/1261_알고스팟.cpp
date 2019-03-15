//알고스팟 운영진이 모두 미로에 갇혔다.미로는 N*M 크기이며, 총 1 * 1크기의 방으로 이루어져 있다.\
//미로는 빈 방 또는 벽으로 이루어져 있고, 빈 방은 자유롭게 다닐 수 있지만, 벽은 부수지 않으면 이동할 수 없다.
//
//알고스팟 운영진은 여러명이지만, 항상 모두 같은 방에 있어야 한다.즉, 여러 명이 다른 방에 있을 수는 없다.
//어떤 방에서 이동할 수 있는 방은 상하좌우로 인접한 빈 방이다.즉, 현재 운영진이(x, y)에 있을 때, 
//이동할 수 있는 방은(x + 1, y), (x, y + 1), (x - 1, y), (x, y - 1) 이다.단, 미로의 밖으로 이동 할 수는 없다.
//
//벽은 평소에는 이동할 수 없지만, 알고스팟의 무기 AOJ를 이용해 벽을 부수어 버릴 수 있다.벽을 부수면, 빈 방과 동일한 방으로 변한다.
//
//만약 이 문제가 알고스팟에 있다면, 운영진들은 궁극의 무기 sudo를 이용해 벽을 한 번에 다 없애버릴 수 있지만,
//안타깝게도 이 문제는 Baekjoon Online Judge에 수록되어 있기 때문에, sudo를 사용할 수 없다.
//
//현재(1, 1)에 있는 알고스팟 운영진이(N, M)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 미로의 크기를 나타내는 가로 크기 M, 세로 크기 N(1 ≤ N, M ≤ 100)이 주어진다.
//다음 N개의 줄에는 미로의 상태를 나타내는 숫자 0과 1이 주어진다. 0은 빈 방을 의미하고, 1은 벽을 의미한다.
//
//(1, 1)과(N, M)은 항상 뚫려있다.
//
//출력
//첫째 줄에 알고스팟 운영진이(N, M)으로 이동하기 위해 벽을 최소 몇 개 부수어야 하는지 출력한다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
const int MAX_N = 100 + 2;
const int INF = 987654321;
int map[MAX_N][MAX_N];
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

bool isinmap(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

int dijkstra()
{
	int dist[MAX_N][MAX_N];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dist[i][j] = INF;

	dist[1][1] = 0;
	priority_queue <pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(1, 1)));
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int nowY = pq.top().second.first;
		int nowX = pq.top().second.second;
		pq.pop();
		if (cost > dist[nowY][nowX])
			continue;
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i];
			int nextX = nowX + goX[i];
			if (!isinmap(nextY, nextX))
				continue;
			int nextDist = cost + map[nextY][nextX];
			if (nextDist < dist[nextY][nextX])
			{
				dist[nextY][nextX] = nextDist;
				pq.push(make_pair(-nextDist, make_pair(nextY, nextX)));
			}
		}
	}

	return dist[N][M];
}


int main()
{
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf_s("%1d", &map[i][j]);
	
	cout << dijkstra();
	
}
