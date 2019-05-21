#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 15 + 2;
int N, M, D, maxSum = 0;
int board[MAX_N][MAX_N];
int board_cpy[MAX_N][MAX_N];
vector <pair<int, int>> archer;
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

bool Vcompare(pair<pair <int,int>,int> &a, pair<pair<int, int>,int> &b)
{
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first.second < b.first.second;
}

bool is_in_board(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

void board_print()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cout << board[i][j];
		cout << endl;
	}
	cout << endl;
}

void board_recover()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			board[i][j] = board_cpy[i][j];
}

void board_move()
{
	int tmp_board[MAX_N][MAX_N];
	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
			for (int j = 1; j <= M; j++)
				tmp_board[i][j] = 0;
		else
			for (int j = 1; j <= M; j++)
				tmp_board[i][j] = board[i - 1][j];
	}
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			board[i][j] = tmp_board[i][j];
}

void board_remove( vector <pair<int,int>> &deleted)
{
	for (auto i : deleted)
		board[i.first][i.second] = 0;
	
}

int bfs()
{
	vector <pair<int, int>> deleted;
	for (int i = 0; i < 3; i++)
	{
		int archerY = archer[i].first, archerX = archer[i].second;
		vector <pair < pair<int,int> ,int> > can_delete;
		int visited[MAX_N][MAX_N] = { 0, };
		queue <pair<int, int>> q;
		visited[archerY][archerX] = 1;
		q.push(make_pair(archerY, archerX));
		while (!q.empty())
		{
			int nowY = q.front().first;
			int nowX = q.front().second;
			q.pop();
			if (board[nowY][nowX] == 1 && visited[nowY][nowX] - 1 <= D)
			{
				can_delete.push_back(make_pair(make_pair(nowY, nowX), visited[nowY][nowX] - 1));
				continue;
			}
			if (visited[nowY][nowX] - 1 > D)
				continue;
			for (int j = 0; j < 4; j++)
			{
				int nextY = nowY + goY[j], nextX = nowX + goX[j];
				if (!visited[nextY][nextX] && is_in_board(nextY, nextX))
				{
					visited[nextY][nextX] = visited[nowY][nowX] + 1;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
		if (can_delete.size() > 0)
		{
			sort(can_delete.begin(), can_delete.end(), Vcompare);
			deleted.push_back(can_delete[0].first);
		}
	}
	deleted.erase(unique(deleted.begin(), deleted.end()), deleted.end());
	board_remove(deleted);
	return deleted.size();
}

void archer_place(int x, int n)
{
	if (n == 3)
	{
		int sum = 0, time = N + 1;
		while (time--)
		{
			sum += bfs();
			board_move();
		}
		maxSum = max(sum, maxSum);
		board_recover();
		return;
	}

		for (int j = x; j <= M; j++)
		{
			bool overlap = false;
			for (int k = 0; k < n; k++)
				if (archer[k] == make_pair(N+1, j))
					overlap = true;
			if (!overlap)
			{
				archer[n] = make_pair(N+1, j);
				archer_place( j, n + 1);
				archer[n] = make_pair(0, 0);
			}
		}
	
}

int main()
{
	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
			board_cpy[i][j] = board[i][j];
		}
	archer.resize(3);
	archer_place(1, 0);
	cout << maxSum;
}