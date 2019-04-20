#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 100 + 4;
const int INF = -987654321;
const int FAIL = -87654321;
int N, M;
int cache[MAX_N][MAX_N / 2][2][MAX_N];
int arr[MAX_N];

int f(int idx, int m, bool active, int last_idx)
{
	if (idx == N+2)
	{
		if (m == 0)
			return 0;
		else
			return FAIL;
	}

	int& ret = cache[idx][m][active][last_idx];
	if (ret != INF)
		return ret;
	

	if (active)
		ret = max(f(idx + 1, m, 1, idx) + arr[idx], f(idx + 1, m, 0, last_idx));
	else
	{
		//묶을수 있으면
		if (last_idx + 1 < idx && m > 0)
			ret = max(f(idx + 1, m, 0, last_idx), f(idx + 1, m - 1, 1, idx) + arr[idx]);
		else
			ret = max(ret, f(idx + 1, m, 0, last_idx));
	}
	return ret;
}

int main()
{
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N / 2; j++)
			for (int k = 0; k < 2; k++)
				for (int p = 0; p < MAX_N; p++)
					cache[i][j][k][p] = INF;

	cin >> N >> M;
	//편의를 위해 2~N+1까지가 arr배열
	for (int i = 2; i < N + 2; i++)
		cin >> arr[i];
	cout << f(2, M, 0, 0);
}