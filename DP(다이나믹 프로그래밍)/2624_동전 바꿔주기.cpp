#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_T = 10000 + 2;
const int MAX_K = 100 + 2;
int cache[MAX_T][MAX_K];
int T, K;
pair <int,int> arr[MAX_K];

int f(int sum, int idx)
{
	if (idx == K)
	{
		if (sum == 0)
			return 1;
		else
			return 0;
	}
	int& ret = cache[sum][idx];
	if (ret != -1)
		return ret;
	ret = 0;
	//arr.first=value, arr.second=n
	for (int i = 0; i*arr[idx].first <= sum; i++)
	{
		if (i > arr[idx].second)
			break;
		ret += f(sum - i*arr[idx].first, idx + 1);
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> T >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i].first = a, arr[i].second = b;
	}
	cout << f(T, 0);
}