#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N, cache[501][501], pMax[501][501], arr[501];

int f(int left, int right)
{
	if (left == right)return 0;
	int&ret = cache[left][right];
	if (ret != -1)return ret;
	ret = INF;
	for (int i = left; i < right; i++)
		ret = min(ret, f(left, i) + f(i + 1, right) + abs(pMax[left][i] - pMax[i + 1][right]));
	
	return ret;
}


int main()
{
	cin >> N;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++)cin >> arr[i];

	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			int maxN = 0;
			for (int k = i; k <= j; k++)
				maxN = max(maxN, arr[k]);
			pMax[i][j] = maxN;
		}

	cout << f(0, N - 1);
}
