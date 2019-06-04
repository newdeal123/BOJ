#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_N = 1000 + 2;
int N, arr[MAX_N], cache[MAX_N];

int f(int idx)
{
	int&ret = cache[idx];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = idx + 1; i < N; i++)
		if (arr[idx] > arr[i])
			ret = max(ret, f(i) + arr[i]);
	return ret;

}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int maxN = 0;
	for (int i = 0; i < N; i++)
	{
		maxN = max(maxN, f(i) + arr[i]);
	}
	cout << maxN;
}