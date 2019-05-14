#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;
const int MAX_N = 2000 + 2;
int N;
int Left[MAX_N], Right[MAX_N], cache[MAX_N][MAX_N];

int f(int leftIdx, int rightIdx)
{
	if (leftIdx == N || rightIdx == N)
		return 0;

	int&ret = cache[leftIdx][rightIdx];
	if (ret != -1)
		return ret;

	if (Right[rightIdx] < Left[leftIdx])
		ret = max(ret, f(leftIdx, rightIdx + 1) + Right[rightIdx]);
	ret = max(ret, f(leftIdx + 1, rightIdx));
	ret = max(ret, f(leftIdx + 1, rightIdx + 1));

	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Left[i];
	for (int i = 0; i < N; i++)
		cin >> Right[i];
	cout << f(0, 0);
}