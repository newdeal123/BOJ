#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int N, M;
const int INF = 987654321;
const int MAX_N = 10000 + 2;
const int MAX_M = 500 + 2;
int cache[MAX_N][MAX_M];
int arr[MAX_N];

//cnt=지침지수
int f(int time, int cnt)
{
	if (time == N+1)
	{
		if (cnt != 0)
			return -INF;
		else
			return 0;
	}
	if (time > N+1 )
		return -INF;
	
	int&ret = cache[time][cnt];
	if (ret != -1)
		return ret;

	if (cnt == 0)
		return ret = max(f(time + 1, 0), f(time + 1, 1) + arr[time]);
	else
	{
		if (cnt + 1 > M)
			return ret = f(time + cnt, 0);
		else
			return ret = max(f(time + cnt, 0), f(time + 1, cnt + 1) + arr[time]);
	}
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cout << f(1, 0);
}