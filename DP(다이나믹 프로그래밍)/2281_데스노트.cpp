#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;
const int INF = 987654321;
const int MAX_N = 1000 + 2;
int N, M;
int cache[MAX_N][MAX_N];
int arr[MAX_N];

int f(int idx, int len)
{
	if (idx == N)
		return 0;

	int&ret = cache[idx][len];
	if (ret != -1)
		return ret;

	ret = INF;
	if (len != 0)
		ret = min(ret, f(idx + 1, arr[idx] + 1) + (M - len + 1)*(M - len + 1));
	if (len + arr[idx] <= M)
		ret = min(ret, f(idx + 1, len + arr[idx] + 1));
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << f(0, 0);
}