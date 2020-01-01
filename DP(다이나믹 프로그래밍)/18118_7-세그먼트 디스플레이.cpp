#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long ll;
int N, M;
ll cache[10][100000 + 2][10];
int cache2[10][100000 + 2];

ll myPow(int n, int k)
{
	if (k == 0)return 1;
	return myPow(n, k - 1)*n;
}

int cnt(int n, int r)
{
	if (n == N)
	{
		if (r == 0) return 0;
		else return -100;
	}
	int&ret = cache2[n][r];
	if (ret != -1)return ret;

	ret = cnt(n + 1, (100 * r + 11) % M) + 1;
	for (int i = 0; i<10; i++)
		ret = max(ret, cnt(n + 1, (10 * r + i) % M));

	return ret;
}

ll f(int n, int r, int add)
{
	if (n == N)
	{
		if (r == 0 && add==0) return 0;
		else return LLONG_MIN + 100;
	}
	ll&ret = cache[n][r][add];
	if (ret != -1)return ret;
	ret = LLONG_MIN + 100;

	if(N-n<=add) return ret= f(n + 1, (100 * r + 11) % M, add - 1) + 11 * myPow(10, N - n - 2 + add);

	if (add) ret = f(n + 1, (100 * r + 11) % M, add - 1) + 11 * myPow(10, N - n - 2 + add);
	for (int i = 9; i >=0; i--)
	{
		ret = max(ret, f(n + 1, (10 * r + i) % M, add) + i*myPow(10, N - n - 1 + add));
	}

	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));
		cin >> N >> M;
		cout << f(0, 0, cnt(0, 0));
		cout << "\n";
	}
}