#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_N = 1000 + 2;
int N, M, mid_max = 0;
char board[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];
int goY[3] = { -1,0,1 };
int goX[3] = { 1,1,1 };

bool can_go(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	if (board[y][x] == '#')
		return false;
	return true;
}

int f(int y, int x)
{
	if (x == M)
	{
		if (board[y][x] == 'O')
			return 0;
		else
			return -INF;
	}
	
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	if (board[y][x] == 'O')
		ret = 0;
	else
		ret = -INF;
	for (int i = 0; i < 3; i++)
	{
		int nextY = y + goY[i], nextX = x + goX[i];
		if (!can_go(nextY, nextX))
			continue;
		if (board[y][x] == 'C')
			ret = max(ret, f(nextY, nextX) + 1);
		else	if (board[y][x] == 'O')
			ret = max(ret, f(nextY, nextX));
		else
			ret = max(ret, f(nextY, nextX));
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int startY, startX;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++)
		{
			board[i][j] = s[j - 1];
			if (board[i][j] == 'R')
				startY = i, startX = j;
		}
	}
	int dist = f(startY, startX);
	if (dist < 0)
		cout << "-1";
	else
		cout << dist;
}