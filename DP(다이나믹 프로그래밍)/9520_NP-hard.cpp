#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 1500 + 2;
int cache[MAX_N][MAX_N];
int arr[MAX_N][MAX_N];
int N;

int f(int x, int y, int num)
{
	if (num > N)
		return 0;

	int& ret = cache[x][y];
	if (ret != -1)
		return ret;

	int left = f(num, y, num + 1) + arr[x][num];
	int right = f(x, num, num + 1) + arr[y][num];

	return ret = min(left, right);
}

int main() 
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> arr[i][j];

	memset(cache, -1, sizeof(cache));

	cout << f(1, 1, 1);
}
