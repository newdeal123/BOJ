#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 100000 + 1;
const int INF = 987654321;
int cache[MAX_N][5][5];
int arr[MAX_N];
int N;

int DDR(int idx, int left, int right)
{
	if (idx > N)
		return 0;

	int& ret = cache[idx][left][right];
	if (ret != -1)
		return ret;
	ret = INF;
	// left lift
	if (arr[idx] == left)
		ret = min(ret, DDR(idx + 1, arr[idx], right) + 1);
	else if (arr[idx] == 0 || left == 0)
		ret = min(ret, DDR(idx + 1, arr[idx], right) + 2);
	else if (abs(arr[idx] - left) == 1 || (arr[idx] == 1 && left == 4) || (arr[idx] == 4 && left == 1))
		ret = min(ret, DDR(idx + 1, arr[idx], right) + 3);
	else
		ret = min(ret, DDR(idx + 1, arr[idx], right) + 4);
	// right lift
	if (arr[idx] == right)
		ret = min(ret, DDR(idx + 1, left, arr[idx]) + 1);
	else if (arr[idx] == 0 || right == 0)
		ret = min(ret, DDR(idx + 1, left, arr[idx]) + 2);
	else if (abs(arr[idx] - right) == 1 || (arr[idx] == 1 && right == 4) || (arr[idx] == 4 && right == 1))
		ret = min(ret, DDR(idx + 1, left, arr[idx]) + 3);
	else
		ret = min(ret, DDR(idx + 1, left, arr[idx]) + 4);

	return ret;

}


int main()
{
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= MAX_N; i++)
	{
		int tmp;
		cin >> tmp;
		if (!tmp)
			break;
		arr[i] = tmp;
		N = i;
	}
	cout << DDR(1, 0, 0);
}