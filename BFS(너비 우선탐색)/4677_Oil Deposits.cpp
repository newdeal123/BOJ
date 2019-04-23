#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
#pragma warning(disable:4996)
using namespace std;
const int INF = 987654321;
const int MAX_N = 100 + 2;
int N, M;
char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int goY[8] = { 0,0,1,-1,1,-1,1,-1 };
int goX[8] = { 1,-1,0,0,1,-1,-1,1 };

bool is_in_board(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

void bfs(int y, int x)
{
	queue <pair<int,int>> q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		int nowY = q.front().first, nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];
			if (!is_in_board(nextY, nextX))
				continue;
			if (board[nextY][nextX] != '*' && !visited[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				q.push(make_pair(nextY, nextX));
			}
		}
	}
}

int main()
{
	while (true)
	{
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		cin >> N >> M;
		if (!N && !M)
			break;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				cin >> board[i][j];
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (!visited[i][j] && board[i][j] == '@')
				{
					cnt++;
					bfs(i, j);
				}
		cout << cnt << "\n";
	}
}
