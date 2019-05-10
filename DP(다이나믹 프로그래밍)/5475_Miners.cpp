#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 100000 + 2;
int cache[MAX_N][4][4][4][4];
int N, arr[MAX_N];

int f(int idx, int n1_lastF1, int n1_lastF2, int n2_lastF1, int n2_lastF2)
{
	if (idx == N)
		return 0;

	int&ret = cache[idx][n1_lastF1][n1_lastF2][n2_lastF1][n2_lastF2];
	if (ret != -1)
		return ret;

	if (n1_lastF1 == n1_lastF2)
	{
		if (n1_lastF1 == 0 || n1_lastF1 == arr[idx])
			ret = max(ret, f(idx + 1, n1_lastF2, arr[idx], n2_lastF1, n2_lastF2) + 1);
		else
			ret = max(ret, f(idx + 1, n1_lastF2, arr[idx], n2_lastF1, n2_lastF2) + 2);
	}
	else if (n1_lastF1 == 0)
	{
		if (n1_lastF2 == arr[idx])
			ret = max(ret, f(idx + 1, n1_lastF2, arr[idx], n2_lastF1, n2_lastF2) + 1);
		else
			ret = max(ret, f(idx + 1, n1_lastF2, arr[idx], n2_lastF1, n2_lastF2) + 2);
	}
	else
	{
		if (n1_lastF1 != n1_lastF2 && n1_lastF2 != arr[idx] && arr[idx] != n1_lastF1)
			ret = max(ret, f(idx + 1, n1_lastF2, arr[idx], n2_lastF1, n2_lastF2) + 3);
		else
			ret = max(ret, f(idx + 1, n1_lastF2, arr[idx], n2_lastF1, n2_lastF2) + 2);
	}

	if (n2_lastF1 == n2_lastF2)
	{
		if (n2_lastF1 == 0 || n2_lastF1 == arr[idx])
			ret = max(ret, f(idx + 1, n1_lastF1, n1_lastF2, n2_lastF2, arr[idx]) + 1);
		else
			ret = max(ret, f(idx + 1, n1_lastF1, n1_lastF2, n2_lastF2, arr[idx]) + 2);
	}
	else if (n2_lastF1 == 0)
	{
		if (n2_lastF2 == arr[idx])
			ret = max(ret, f(idx + 1, n1_lastF1, n1_lastF2, n2_lastF2, arr[idx]) + 1);
		else
			ret = max(ret, f(idx + 1, n1_lastF1, n1_lastF2, n2_lastF2, arr[idx]) + 2);
	}
	else
	{
		if (n2_lastF1 != n2_lastF2 && n2_lastF2 != arr[idx] && arr[idx] != n2_lastF1)
			ret = max(ret, f(idx + 1, n1_lastF1, n1_lastF2, n2_lastF2, arr[idx]) + 3);
		else
			ret = max(ret, f(idx + 1, n1_lastF1, n1_lastF2, n2_lastF2, arr[idx]) + 2);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char c;
		cin >> c;
		if (c == 'M')
			arr[i] = 1;
		else if (c == 'F')
			arr[i] = 2;
		else
			arr[i] = 3;
	}
	cout << f(0, 0, 0, 0, 0);
}