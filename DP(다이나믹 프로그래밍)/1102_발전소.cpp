#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
const int MAX_N = 16 + 2;
const int INF = 987654321;
int N, P;
int arr[MAX_N][MAX_N];
int cache[1 << 16];

int bit_count(int n)
{
	if (n == 0)
		return 0;
	return n % 2 + bit_count(n / 2);
}

int f(int bit)
{
	if (bit_count(bit) >= P)
		return 0;

	int& ret = cache[bit];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = 1; i <= N; i++)
	{
		if (bit & (1 << i))
			for (int j = 1; j <= N; j++)
				if (!(bit & (1 << j)))
					ret = min(ret, f(bit | (1 << j)) + arr[i][j]);
			
	}
	return ret;
}

int main()
{
	int bit = 0;
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= N; i++)
	{
		char c;
		cin >> c;
		if (c == 'Y')
			bit |= (1 << i);
	}
	cin >> P;
	int ans = f(bit);
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;
}