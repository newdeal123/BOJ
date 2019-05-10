#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
const int INF = 987654321;
const int MAX_N = 1000 + 5;
int cache[MAX_N][MAX_N];
int arr[MAX_N], N;

int f(int start, int fin, bool my_turn)
{
	if (start == fin)
	{
		if (my_turn)
			return arr[start];
		else
			return 0;
	}

	int& ret = cache[start][fin];
	if (ret != -1)
		return ret;

	if (my_turn)
		ret = max(f(start + 1, fin, 0) + arr[start], f(start, fin - 1, 0) + arr[fin]);
	else
		ret = min(f(start + 1, fin, 1), f(start, fin - 1, 1));

	return ret;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		cout << f(0, N - 1, 1) << "\n";
	}
}