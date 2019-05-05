#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
#include <string>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
const int INF = 987654321;
const int MAX_N = 1000000 + 2;
const int MOD = 1000000000;
ll cache[MAX_N];

ll f(int n)
{
	if (n <= 1)
		return 0;
	if (n == 2)
		return 1;

	ll&ret = cache[n];
	if (ret != -1)
		return ret%MOD;

	return ret = (n - 1) * (f(n - 1) % MOD + f(n - 2) % MOD) % MOD;
}


int main()
{
	memset(cache, -1, sizeof(cache));
	int n;
	cin >> n;
	cout << f(n);
    return 0;
}