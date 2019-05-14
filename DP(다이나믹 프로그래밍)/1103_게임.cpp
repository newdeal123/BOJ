#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#pragma warning(disable:4996)
typedef long long ll;
using namespace std;
const int INF = 987654321;
const int MAX_N = 50 + 2;
int N, M;
char board[MAX_N][MAX_N];
int cache[MAX_N][MAX_N][MAX_N*MAX_N];
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

bool is_in_board(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

int dp(int y, int x, int dist)
{
	if (board[y][x] == 'H' || !is_in_board(y, x))
		return dist;
	if (dist > N*M)
		return INF;

	int&ret = cache[y][x][dist];
	if (ret != -1)
		return ret;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + goY[i] * (board[y][x] - '0');
		int nextX = x + goX[i] * (board[y][x] - '0');
		ret = max(ret, dp(nextY, nextX, dist + 1));
	}

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++)
			board[i][j] = s[j - 1];
	}
	int ans = dp(1, 1, 0);
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;
}
