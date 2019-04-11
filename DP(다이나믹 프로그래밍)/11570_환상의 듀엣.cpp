#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 2000 + 2;
int cache[MAX_N][MAX_N];
int arr[MAX_N];
int N;

int f(int last_a, int last_b)
{
	if (last_a == N || last_b == N)
		return 0;
	int&ret = cache[last_a][last_b];
	if (ret != -1)
		return ret;

	int idx = max(last_a, last_b) + 1;

	if (last_a == 0 && last_b == 0)
		return ret = min(f(idx, last_b), f(last_a, idx));
	else if (last_a == 0)
		return ret = min(f(idx, last_b), f(last_a, idx) + abs(arr[last_b] - arr[idx]));
	else if (last_b == 0)
		return ret = min(f(idx, last_b) + abs(arr[last_a] - arr[idx]), f(last_a, idx));
	else
		return ret = min(f(idx, last_b) + abs(arr[last_a] - arr[idx]), f(last_a, idx) + abs(arr[last_b] - arr[idx]));
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cout << f(0, 0);
}