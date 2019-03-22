#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int N, M;
const int MAX_N = 100 + 2;
int board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

bool isinboard(int y,int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

//밖은-1로 표기
void board_set()
{
	queue <pair<int, int>> q;
	memset(visited, 0, sizeof(visited));
	visited[1][1] = 1;
	board[1][1] = -1;
	q.push(make_pair(1, 1));
	while (!q.empty())
	{
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i];
			int nextX = nowX + goX[i];
			if (isinboard(nextY, nextX) && board[nextY][nextX] != 1 && !visited[nextY][nextX])
			{
				visited[nextY][nextX] = 1;
				board[nextY][nextX] = -1;
				q.push(make_pair(nextY, nextX));
			}
		}
	}

}

void dlt_cheese()
{
	vector<pair<int, int>> v;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j] == 1)
			{
				int cnt = 0;
				for (int d = 0; d < 4; d++)
				{
					int nextY = i + goY[d];
					int nextX = j + goX[d];
					if (isinboard(nextY, nextX) && board[nextY][nextX] == -1)
						cnt++;
				}
				if (cnt >= 2)
					v.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
		board[v[i].first][v[i].second] = 0;
	
}

int main()
{
	int count = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	while (true)
	{
		bool flag = true;
		board_set();
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (board[i][j] == 1)
					flag = false;
		if (flag)
			break;
		dlt_cheese();
		count++;
	}
	cout << count;
}