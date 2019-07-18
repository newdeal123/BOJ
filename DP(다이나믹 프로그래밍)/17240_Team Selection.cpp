#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_N = 20000 + 2;
int N, ability[MAX_N][5], cache[MAX_N][(1 << 5)]; //ability: i번선수의 j역할 능력치

int f(int idx, int bit)
{
	if (bit == (1 << 5) - 1) return 0;
	if (idx == N) return -INF;

	int&ret = cache[idx][bit];
	if (ret != -1)return ret;

	ret = max(ret, f(idx + 1, bit));
	for (int i = 0; i < 5; i++)
	{
		if (bit &(1 << i)) continue;
		ret = max(ret, f(idx + 1, bit | (1 << i)) + ability[idx][i]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 5; j++)
			cin >> ability[i][j];
	cout << f(0, 0);
}