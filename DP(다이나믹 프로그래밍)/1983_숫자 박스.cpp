#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = (int)1e6, IMP = (int)1e9 + 5000;
int N, cache[400][400][400], arr[2][400], cnt[2];

int f(int idx, int c1, int c2) {
	if (N - idx < max(c1, c2))return -INF;
	if (!c1 || !c2)return 0;

	int&ret = cache[idx][c1][c2];
	if (ret != IMP)return ret;

	ret = f(idx + 1, c1 - 1, c2 - 1) + arr[0][c1 - 1] * arr[1][c2 - 1];
	ret = max(ret, max(f(idx + 1, c1, c2 - 1), f(idx + 1, c1 - 1, c2)));

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 400; i++)
		for (int j = 0; j < 400; j++)
			for (int k = 0; k < 400; k++)cache[i][j][k] = IMP;
	cin >> N;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < N ; j++) {
			int n;
			cin >> n;
			if (n)arr[i][cnt[i]++] = n;
		}
	cout << f(0, cnt[0],cnt[1]);
}