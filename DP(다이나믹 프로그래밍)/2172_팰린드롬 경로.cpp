#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAX_N = 20 + 2;
int N, L;
int board[MAX_N][MAX_N];
int cache[MAX_N][MAX_N][MAX_N][MAX_N][MAX_N];
int goY[8] = { -1,-1,-1,0,1,1,1,0 };
int goX[8] = { -1,0,1,1,1,0,-1,-1 };

bool is_in_board(int y, int x)
{
	if (y<1 || y>N || x<1 || x>N)
		return false;
	return true;
}

int f(int y1, int x1, int y2, int x2, int len)
{
	if (board[y1][x1] != board[y2][x2])
		return 0;

	if (len == 1)
	{
		if (y1 == y2 && x1 == x2)
			return 1;
		else
			return 0;
	}

	if (len == 2)
	{
		for (int i = 0; i < 8; i++)
		{
			int nextY = y1 + goY[i], nextX = x1 + goX[i];
			if (nextY == y2 && nextX == x2)
				return 1;
		}
		return 0;
	}

	int&ret = cache[y1][x1][y2][x2][len];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i < 8; i++)
	{
		int nextY1 = y1 + goY[i], nextX1 = x1 + goX[i];
		for (int j = 0; j < 8; j++)
		{
			int nextY2 = y2 + goY[j], nextX2 = x2 + goX[j];
			if (!is_in_board(nextY1, nextX1) || !is_in_board(nextY2, nextX2))
				continue;
			ret += f(nextY1, nextX1, nextY2, nextX2, len - 2);
		}
	}
	return ret;

}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	int sum = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			for (int i2 = 1; i2 <= N; i2++)
				for (int j2 = 1; j2 <= N; j2++)
					sum += f(i, j, i2, j2, L);
		}
	cout << sum;
}