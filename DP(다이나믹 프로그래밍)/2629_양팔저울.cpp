#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int MAX_N = 30 + 2;
const int MAX_G = 500 + 2;
int cache[MAX_N][MAX_N*MAX_G][2];
int N, weight[MAX_N], targetG;

int f(int idx, int sum)
{
	if (idx == N)
	{
		if (abs(sum) == targetG)
			return 1;
		else
			return 0;
	}
	int&ret = cache[idx][abs(sum)][sum < 0 ? 1 : 0];
	if (ret != -1)
		return ret;

	ret = max(f(idx + 1, sum + weight[idx]), f(idx + 1, sum - weight[idx]));
	ret = max(ret, f(idx + 1, sum));
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> weight[i];
	int t;
	cin >> t;
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> targetG;
		int ans = f(0, 0);
		if (ans == 1)
			cout << "Y ";
		else
			cout << "N ";
	}
}