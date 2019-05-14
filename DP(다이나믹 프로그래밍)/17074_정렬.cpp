#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int INF = ((int)1E9 + 1);
const int MAX_N = (int)1E5 + 2;
int cache[MAX_N][3];
int arr[MAX_N], N;

//state 0:스킵불가 1:스킵가능 2:이전idx에서 스킵을했음
int f(int idx , int state)
{
	if (idx == N + 1)
	{
		if (state == 1)
			return 0;
		else
			return 1;
	}
	
	int&ret = cache[idx][state];
	if (ret != -1)
		return ret;
	ret = 0;
	if (state == 0)
	{
		if (arr[idx - 1] > arr[idx])
			return ret = 0;
		else
			return ret = f(idx + 1, 0);
	}
	if (state == 1)
	{
		ret += f(idx + 1, 2);
		if (arr[idx - 1] <= arr[idx])
			ret += f(idx + 1, 1);
		return ret;
	}
	if (state == 2)
	{
		if (arr[idx - 2] > arr[idx])
			return ret = 0;
		else
			return ret = f(idx + 1, 0);
	}
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	arr[0] = -INF;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cout << f(1, 1);
}