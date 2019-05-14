#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;
const int MAX_N = 300 + 2, MAX_M = 20 + 2;
int N, M;
int company[MAX_M][MAX_N]; //i번기업에 j금액을 투자했을때 얻는 이익
int cache[MAX_N][MAX_M];

//가지고있는 금액, idx번째 기업
int f(int sum, int idx)
{
	if (idx > M)
		return 0;

	int&ret = cache[sum][idx];
	if (ret != -1)
		return ret;

	for (int i = 0; i <= sum; i++)
		ret = max(ret, f(sum - i, idx + 1) + company[idx][i]);
	return ret;
}


void output(int sum, int idx)
{
	if (idx > M)
		return;
	
	int maxInvest = 0, maxN = 0;
	for (int i = 0; i <= sum; i++)
		if (maxN < f(sum - i, idx + 1) + company[idx][i])
		{
			maxN = f(sum - i, idx + 1) + company[idx][i];
			maxInvest = i;
		}
	cout << maxInvest << " ";
	return output(sum - maxInvest, idx + 1);

}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int cost;
		cin >> cost;
		for (int i = 1; i <= M; i++)
			cin >> company[i][cost];
	}

	cout << f(N, 1) << "\n";
	output(N, 1);
}