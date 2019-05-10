#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
const int INF = 987654321;
const int MAX_N = 1000 + 5;
int cache[MAX_N][2];
int bring[3] = { 1,3,4 };

int f(int n, bool my_turn)
{
	if (n == 0)
	{
		if (my_turn)
			return 1;
		else
			return 0;
	}
	int&ret = cache[n][my_turn];
	if (ret != -1)
		return ret;
	ret = 0;
	if (my_turn)
	{
		for (int i = 0; i < 3; i++)
		{
			int next = bring[i];
			if (n - next >= 0)
				ret = max(ret, f(n - next, 0));
		}
	}
	else
	{
		ret = 1;
		for (int i = 0; i < 3; i++)
		{
			int next = bring[i];
			if (n - next >= 0)
				ret = min(ret, f(n - next, 1));
		}
	}
	return ret;
}


int main()
{
	memset(cache, -1, sizeof(cache));
	int n;
	cin >> n;
	int ans = f(n, 1);
	if (ans == 1)
		cout << "SK";
	else
		cout << "CY";
}