#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
const int MOD = 1000007;
const int MAX_N = 50 + 2;
pair <int, int> arcade[MAX_N];
int cache[MAX_N][MAX_N][MAX_N][MAX_N];
int N, M, C;
int goY[2] = { 0,1 };
int goX[2] = { 1,0 };

int get_arcadeN(int y, int x)
{
	for (int i = 1; i <= C; i++)
	{
		if (arcade[i] == make_pair(y, x))
			return i;
	}
	return -1;
}

//좌표,마지막 방문한 오락실 번호, 방문해야할 오락실 수
int f(int y, int x, int last, int sum)
{
	if (sum < 0)
		return 0;

	if (y == N && x == M)
	{
		if (sum == 0)
			return 1;
		else
			return 0;
	}

	int&ret = cache[y][x][last][sum];
	if (ret != -1)
		return ret%MOD;
	ret = 0;
	for (int i = 0; i < 2; i++)
	{
		int nextY = y + goY[i], nextX = x + goX[i];
		if (nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= M)
		{
			int nextN = get_arcadeN(nextY, nextX);
			if (nextN == -1)
				ret += f(nextY, nextX, last, sum) % MOD;
			else if (nextN > last)
				ret += f(nextY, nextX, nextN, sum - 1) % MOD;
		}
		ret %= MOD;
	}
	return ret%MOD;
}

int main()
{
	bool flag = false;
	int firstN;
	memset(cache, -1, sizeof(cache));
	cin >> N >> M >> C;
	arcade[0] = make_pair(-1, -1);
	for (int i = 1; i <= C; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1 && b == 1)
		{
			flag = true;
			firstN = i;
		}

		arcade[i] = make_pair(a, b);
	}
	for (int i = 0; i <= C; i++)
	{
		if (flag)
			cout << f(1, 1, firstN, i - 1) % MOD << " ";
		else
			cout << f(1, 1, 0, i) % MOD << " ";
	}
}