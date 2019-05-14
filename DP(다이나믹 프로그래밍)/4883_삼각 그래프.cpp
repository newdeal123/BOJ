#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
const int INF = (int)1E9 + 2;
const int MAX_N = (int)1E6 + 2;
int N;
int board[MAX_N][3], cache[MAX_N][3];

bool is_in_board(int y, int x)
{
	if (y<0 || y>=N || x < 0 || x>=3)
		return false;
	return true;
}

int f(int y, int x)
{
	if (y == N-1 && x == 1)
		return board[y][x];
	if (!is_in_board(y, x))
		return INF;
	int&ret = cache[y][x];
	if (ret != -1)
		return ret;
	ret = INF;
	if (x == 0)
	{
		int goY[3] = { 1,1,0 };
		int goX[3] = { 1,0,1 };
		for (int i = 0; i < 3; i++)
			ret = min(ret, f(y + goY[i], x + goX[i]) + board[y][x]);
	}
	else if(x == 1)
	{
		int goY[4] = { 1,1,0,1 };
		int goX[4] = { 1,0,1 ,-1 };
		for (int i = 0; i < 4; i++)
			ret = min(ret, f(y + goY[i], x + goX[i]) + board[y][x]);
	}
	else
	{
		int goY[2] = { 1,1 };
		int goX[2] = { -1,0 };
		for (int i = 0; i < 2; i++)
			ret = min(ret, f(y + goY[i], x + goX[i]) + board[y][x]);
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; ; i++)
	{
		memset(cache, -1, sizeof(cache));
		cin >> N;
		if (!N) break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 3; j++)
				cin >> board[i][j];
		cout << i << ". " << f(0, 1) << "\n";
	}
}