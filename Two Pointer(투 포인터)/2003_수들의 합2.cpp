#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#pragma warning(disable:4996)
typedef long long ll;
using namespace std;
ll N, M;
ll arr[10000 + 2];

ll f(int idx1, int idx2, ll sum)
{
	if (idx1 == idx2 && idx1 == N - 1)
	{
		if (sum == M)
			return 1;
		else
			return 0;
	}
	ll ret = 0;

	if (sum == M)
		ret++;
	if (idx1 == idx2)
		ret += f(idx1, idx2 + 1, sum + arr[idx2 + 1]);
	else if (idx2 + 1 < N && sum + arr[idx2 + 1] <= M)
		ret += f(idx1, idx2 + 1, sum + arr[idx2 + 1]);
	else
		ret += f(idx1 + 1, idx2, sum - arr[idx1]);
	return ret;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << f(0, 0, arr[0]);
}