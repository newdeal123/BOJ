#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_N = 1000 + 2;
int N, cache[MAX_N][MAX_N], arr1[MAX_N], arr2[MAX_N];

int f(int idx1, int idx2)
{
	if (idx1 == N && idx2 == N)
		return 0;
	if (idx1 == N || idx2 == N)
		return INF;

	int&ret = cache[idx1][idx2];
	if (ret != -1)
		return ret;
	int DTW = (arr1[idx1] - arr2[idx2])*(arr1[idx1] - arr2[idx2]);
	ret = min(f(idx1 + 1, idx2), f(idx1, idx2 + 1)) + DTW;
	ret = min(ret, f(idx1 + 1, idx2 + 1) + DTW);
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr1[i];
	for (int i = 0; i < N; i++)
		cin >> arr2[i];
	cout << f(0, 0);
}