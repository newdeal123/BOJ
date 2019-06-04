#include  <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_N = 15 + 2;
int N, L, R, X, cache[MAX_N][1 << 15], arr[MAX_N];

int dp(int idx, int bit)
{
	if (idx == N)
	{
		int sum = 0, minN = INF, maxN = 0;
		for (int i = 0; i < N; i++)
			if (bit & (1 << i))
			{
				sum += arr[i];
				minN =min(minN, arr[i]);
				maxN = max(maxN, arr[i]);
			}
		if (sum<L || sum>R) return 0;
		if (maxN - minN < X) return 0;
		return 1;
	}

	int&ret = cache[idx][bit];
	if (ret != -1) return ret;
	ret = 0;
	return ret += dp(idx + 1, bit | (1 << idx)) + dp(idx + 1, bit);
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << dp(0, 0);
}