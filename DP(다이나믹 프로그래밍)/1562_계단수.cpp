#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef  long long ll;
const int MOD = (int)1E9;
const int MAX_N = 100 + 2;
int cache[MAX_N][10][1 << 10];
int N;

int f(int idx, int lastN, int bit)
{
	if (idx == N)
	{
		if (bit == (1 << 10) - 1)
			return 1;
		else
			return 0;
	}

	int &ret = cache[idx][lastN][bit];
	if (ret != -1)
		return ret%MOD;

	if (lastN == 0)
		return ret = f(idx + 1, lastN + 1, bit | (1 << (lastN + 1))) % MOD;
	else if (lastN == 9)
		return ret = f(idx + 1, lastN - 1, bit | (1 << (lastN - 1))) % MOD;
	else
		return ret = (f(idx + 1, lastN + 1, bit | (1 << (lastN + 1))) % MOD + f(idx + 1, lastN - 1, bit | (1 << (lastN - 1))) % MOD) % MOD;
}

int main()
{
	cin >> N;
	ll  sum = 0;
	memset(cache, -1, sizeof(cache));

	for (int i = 1; i < 10; i++)
	{
		sum += f(1, i, (1 << i)) % MOD;
		sum %= MOD;
	}
	
	cout << sum;
}