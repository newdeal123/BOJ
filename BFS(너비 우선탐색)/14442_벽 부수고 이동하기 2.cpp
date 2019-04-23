#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int MAX_N = 1000 + 5;
const int INF = 987654321;
int N, M, K;
int board[MAX_N][MAX_N];
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

bool is_in_board(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

struct MAP
{
	int y, x, punch;
};

int bfs()
{
	queue <MAP> q;
	int visited[MAX_N][MAX_N][11] = { 0, };
	int min_dist = INF;
	visited[1][1][K] = 1;
	q.push({ 1,1,K });
	while (!q.empty())
	{
		int nowY = q.front().y, nowX = q.front().x, nowK = q.front().punch;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];
			
			if (!is_in_board(nextY, nextX))
				continue;
			//벽을 부술수 있다면
			if (nowK > 0 && board[nextY][nextX]==1)
				if (!visited[nextY][nextX][nowK - 1])
				{
					visited[nextY][nextX][nowK - 1] = visited[nowY][nowX][nowK] + 1;
					q.push({ nextY,nextX,nowK - 1 });
				}

			if (!visited[nextY][nextX][nowK] && board[nextY][nextX] !=1)
			{
				visited[nextY][nextX][nowK] = visited[nowY][nowX][nowK] + 1;
				q.push({ nextY,nextX,nowK });
			}
		}
	}
	for (int i = 0; i < 11; i++)
		if (visited[N][M][i] != 0)
			min_dist = min(min_dist, visited[N][M][i]);
	if (min_dist == INF)
		return -1;
	else
		return min_dist;

}
int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &board[i][j]);

	cout << bfs();
}