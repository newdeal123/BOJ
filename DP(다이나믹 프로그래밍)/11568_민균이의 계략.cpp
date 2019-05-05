#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 1000 + 2;
int cache[MAX_N];
int N;
int arr[MAX_N];

int f(int start)
{
	int& ret = cache[start];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int next = start + 1; next < N; next++)
	{
		if (arr[start] < arr[next])
			ret = max(ret, f(next) + 1);
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, f(i));
	cout << ans;
}