#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
vector <pair<int, int>> to_fill;
int board[10][10];
int sqaure[10][10];
int get_sqaureN(int y, int x)
{
	if (y >= 1 && y <= 3)
	{
		if (x >= 1 && x <= 3)
			return 1;
		if (x >= 4 && x <= 6)
			return 2;
		if (x >= 7 && x <= 9)
			return 3;
	}
	if (y >= 4 && y <= 6)
	{
		if (x >= 1 && x <= 3)
			return 4;
		if (x >= 4 && x <= 6)
			return 5;
		if (x >= 7 && x <= 9)
			return 6;
	}
	if (y >= 7 && y <= 9)
	{
		if (x >= 1 && x <= 3)
			return 7;
		if (x >= 4 && x <= 6)
			return 8;
		if (x >= 7 && x <= 9)
			return 9;
	}
}

bool is_possible(int y, int x)
{
	bool visited[10] = { 0, };
	for (int i = 1; i < 10; i++)
	{
		if (board[y][i] == 0)
			continue;

		if (visited[board[y][i]])
			return false;
		visited[board[y][i]] = true;
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i < 10; i++)
	{
		if (board[i][x] == 0)
			continue;

		if (visited[board[i][x]])
			return false;
		visited[board[i][x]] = true;
	}
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			if (board[i][j] == 0)
				continue;
			if (i == y && j == x)
				continue;
			if (sqaure[y][x]==sqaure[i][j] && board[i][j] == board[y][x])
				return false;
		}
	
	return true;
	
}

void dfs(int n)
{
	if (n == to_fill.size())
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
		exit(0);
	}
	
	for (int i = 1; i <= 9; i++)
	{
		int y = to_fill[n].first, x = to_fill[n].second;
		board[y][x]= i;
		if (is_possible(y, x))
			dfs(n + 1);
		board[y][x] = 0;
	}

}

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> board[i][j];
			sqaure[i][j] = get_sqaureN(i, j);
			if (board[i][j] == 0)
				to_fill.push_back(make_pair(i, j));
		}
	}
	dfs(0);
	
}