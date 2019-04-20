#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 16 + 2;
const int INF = 987654321;
int N, arr[MAX_N][MAX_N], start_city = 0;
int cache[MAX_N][1 << 16];
int bit_cache[1 << 16];

int bit_count(int n)
{
	if (n == 0)
		return 0;
	int&ret = bit_cache[n];
	if (ret != -1)
		return ret;

	return ret = bit_count(n / 2) + n % 2;
}

int f(int city, int bit)
{
	if (bit_count(bit) == N)
	{
		if (arr[city][start_city] == 0)
			return INF;
		else
			return arr[city][start_city];
	}
	

	int& ret = cache[city][bit];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int next_city = 0; next_city < N; next_city++)
	{
		if (arr[city][next_city] == 0 || bit & (1 << next_city))
			continue;
		ret = min(ret, f(next_city, bit | (1 << next_city)) + arr[city][next_city]);
	}
	return ret;
}

int main()
{
	memset(bit_cache, -1, sizeof(bit_cache));
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	cout << f(0, 1);
}