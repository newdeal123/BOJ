#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
const int INF = (int)1E9 + 1;
const int MAX_N = 100 + 1;
ll N, M, memory[MAX_N], cost[MAX_N], cache[MAX_N][MAX_N*MAX_N];

ll f(ll idx, ll now_cost)
{
	if (idx == N)
		return 0;

	ll&ret = cache[idx][now_cost];
	if (ret != -1)
		return ret;
	ret = 0;
	if (now_cost >= cost[idx])
		return ret = max(f(idx + 1, now_cost - cost[idx]) + memory[idx], f(idx + 1, now_cost));
	else
		return ret = f(idx + 1, now_cost);
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> memory[i];
	for (int i = 0; i < N; i++)
		cin >> cost[i];

	for (ll i = 0; i < MAX_N*MAX_N; i++)
	{
		if (f(0, i) >= M)
		{
			cout << i;
			return 0;
		}
	}
}