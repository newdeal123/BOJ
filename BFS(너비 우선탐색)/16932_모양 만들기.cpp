#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 1000;
int N, M;
bool board[MAX_N + 2][MAX_N + 2];
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };
int visited[MAX_N + 2][MAX_N + 2] = { 0, };

bool can_go(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	if (board[y][x] == 0)
		return false;
	return true;
}

int bfs(int y,int x, int tmp)
{
	queue <pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = tmp;
	int cnt = 0;
	while (!q.empty())
	{
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];
			if (visited[nextY][nextX]  < tmp && can_go(nextY, nextX))
			{
				visited[nextY][nextX] = tmp;
				q.push(make_pair(nextY, nextX));
			}
		}
		cnt++;
	}
	return cnt;
}

bool isborder(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int searchY = y + goY[i], searchX = x + goX[i];
		if (board[searchY][searchX] == 1)
			return true;
	}
	return false;
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	}
	int max_range = 0, tmp = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j] == 1)
				continue;
			if (!isborder(i, j))
				continue;
			board[i][j] = 1;
			max_range = max(max_range, bfs(i, j, tmp++));
			board[i][j] = 0;
		}
	}
	cout << max_range;
}