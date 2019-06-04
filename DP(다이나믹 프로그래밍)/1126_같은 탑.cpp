#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
const int INF = 987654321;
const int MAX_N = 50 + 1;
const int MAX_H = 250000 + 1;
int cache[MAX_N][MAX_H][2], N, arr[MAX_N];

//idx번 블록을 옮길 차례에 1번탑이 2번탑보다 diff보다 많다.
int f(int idx, int diff)
{
	if (abs(diff) >= MAX_H)
		return -INF;

	if (idx == N)
	{	
		if (diff == 0)	return 0;
		else return -INF;
	}

	int&ret = cache[idx][abs(diff)][diff > 0 ? 1 : 0];
	if (ret != -1)
		return ret;
	ret = max(f(idx + 1, diff - arr[idx]) + arr[idx], f(idx + 1, diff + arr[idx]) + arr[idx]);
	ret = max(ret, f(idx + 1, diff));
	return ret;
}


int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int ans= f(0, 0) / 2;
	if (ans <= 0)
		cout << "-1";
	else
		cout << ans;
}