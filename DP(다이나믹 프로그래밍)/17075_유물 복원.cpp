#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int MAX_N = 50 + 2;
int N, M, K, cnt = 0;
int board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = { 0, };
int cache[MAX_N*MAX_N][MAX_N][MAX_N];

int dp(int sum, int y, int x)
{
	if (y == N + 1 && x == 1)
	{
		if (sum%K == 0)
			return 1;
		return 0;
	}

	if (board[y][x] != -1)
	{
		if (x == M)
			return dp(sum, y + 1, 1);
		else
			return dp(sum, y, x + 1);
	}

	int&ret = cache[sum][y][x];
	if (ret != -1)
		return ret;
	if (x == M)
		return ret = max(dp((sum + visited[y][x]) % K, y + 1, 1), dp(sum, y + 1, 1));
	else
		return ret = max(dp((sum + visited[y][x]) % K, y, x + 1), dp(sum, y, x + 1));
}

void output(int sum, int y, int x)
{
	if (y == N + 1 && x == 1)
		return;
	if (board[y][x] != -1)
	{
		cout << board[y][x] << " ";
		if (x == M)
		{
			cout << "\n";
			return output(sum, y + 1, 1);
		}
		else
			return output(sum, y, x + 1);
	}

	if (x == M)
	{
		if (dp((sum + visited[y][x]) % K, y + 1, 1) >= dp(sum, y + 1, 1))
		{
			cout << "1\n";
			return output((sum + visited[y][x]) % K, y + 1, 1);
		}
		else
		{
			cout << "0\n";
			return output(sum, y + 1, 1);
		}
	}
	else
	{
		if (dp((sum + visited[y][x]) % K, y, x + 1) >= dp(sum, y, x + 1))
		{
			cout << "1 ";
			return output((sum + visited[y][x]) % K, y, x + 1);
		}
		else
		{
			cout << "0 ";
			return output(sum, y, x + 1);
		}
	}
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	int allSum = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			visited[i][j] = i*j*(N - i + 1)*(M - j + 1);
			if (board[i][j] == 1)
				allSum += visited[i][j];
		}

	int ans = dp(allSum % K, 1, 1);
	if (ans == 0)
		cout << "-1";
	else
	{
		cout << "1\n";
		output(allSum% K, 1, 1);
	}
}