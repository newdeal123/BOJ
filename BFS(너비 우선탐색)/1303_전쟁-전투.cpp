#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 100 + 2;
int N, M;
char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N] = { 0, };
int goY[4] = { 1,-1,0,0 };
int goX[4] = { 0,0,1,-1 };

bool is_in_board(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

int bfs(int y, int x)
{
	int cnt = 0;
	char ours = board[y][x];
	visited[y][x] = 1;
	queue <pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		int nowY = q.front().first, nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];
			if (is_in_board(nextY, nextX) && !visited[nextY][nextX] && board[nextY][nextX] == ours)
			{
				visited[nextY][nextX] = 1;
				q.push(make_pair(nextY, nextX));
			}
		}
		cnt++;
	}
	return cnt;
}


int main()
{
	int Wsum = 0, Bsum = 0;
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (!visited[i][j])
			{
				int n = bfs(i, j);
				if (board[i][j] == 'W')
					Wsum += n*n;
				else
					Bsum += n*n;
			}
		}
	cout << Wsum << " " << Bsum;
}