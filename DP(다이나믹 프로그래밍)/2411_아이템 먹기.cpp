#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 100 + 2;
int N, M, A, B;
int cache[MAX_N][MAX_N][201];
int board[MAX_N][MAX_N] = { 0, };
int goY[2] = { 1,0 };
int goX[2] = { 0,1 };

int go(int y, int x, int sum)
{
	if (y == N && x == M)
	{
		if (sum == A)
			return 1;
		else
			return 0;
	}
	int&ret = cache[y][x][sum];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 2; i++)
	{
		int nextY = y + goY[i], nextX = x + goX[i];
		if (nextY > N || nextX > M)
			continue;
		if (board[nextY][nextX] == 1)
			ret += go(nextY, nextX, sum + 1);
		if (board[nextY][nextX] == 0)
			ret += go(nextY, nextX, sum);
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> M >> A >> B;
	for (int i = 0; i < A; i++)
	{
		int y, x;
		cin >> y >> x;
		board[y][x] = 1;
	}
	for (int i = 0; i < B; i++)
	{
		int y, x;
		cin >> y >> x;
		board[y][x] = 2;
	}
	cout << go(1, 1, 0);
}