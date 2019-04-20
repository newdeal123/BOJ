#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
const int MAX_N = 20 + 2;
int N, M; //세로,가로
char board[MAX_N][MAX_N];
int cache[MAX_N][MAX_N][1 << 10];
int bfs_cache[MAX_N][MAX_N][MAX_N][MAX_N];
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };
vector <pair<int, int>> to_clean;

bool is_in_board(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

int bfs(int startY, int startX, int finY, int finX)
{
	int&ret = bfs_cache[startY][startX][finY][finX];
	if (ret != -1)
		return ret;

	int visited[MAX_N][MAX_N] = { 0, };
	queue <pair<int, int>> q;
	visited[startY][startX] = 1;
	q.push(make_pair(startY, startX));
	while (!q.empty())
	{
		int nowY = q.front().first, nowX = q.front().second;
		q.pop();

		if (nowY == finY && nowX == finX)
			return ret = visited[nowY][nowX] - 1;

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];
			if (!is_in_board(nextY, nextX))
				continue;
			if (!visited[nextY][nextX] && board[nextY][nextX] != 'x')
			{
				visited[nextY][nextX] = visited[nowY][nowX] + 1;
				q.push(make_pair(nextY, nextX));
			}
		}
	}
	return ret = INF;
}

int f(int y, int x, int bit)
{
	if (bit == (1 << to_clean.size()) - 1)
		return 0;

	int&ret = cache[y][x][bit];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = 0; i < to_clean.size(); i++)
	{
		if (bit & (1 << i))
			continue;
		int nextY = to_clean[i].first, nextX = to_clean[i].second;
		int dist = bfs(y, x, nextY, nextX);
		if (dist == INF)
			continue;
		ret = min(ret, f(nextY, nextX, bit | (1 << i)) + dist);
	}
	return ret;
}

int main()
{
	while (true)
	{
		to_clean.clear();
		memset(bfs_cache, -1, sizeof(bfs_cache));
		memset(cache, -1, sizeof(cache));
		int startY, startX;
		cin >> M >> N;
		if (!M && !N)
			break;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '*')
					to_clean.push_back(make_pair(i, j));
				if (board[i][j] == 'o')
					startY = i, startX = j;
			}

		int dist = f(startY, startX, 0);
		if (dist == INF)
			cout << "-1\n";
		else
			cout << dist << "\n";
	}
}