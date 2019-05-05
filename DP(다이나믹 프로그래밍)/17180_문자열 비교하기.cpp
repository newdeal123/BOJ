#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 300 + 2;
const int INF = 987654321;
int N, M;
int cache[MAX_N][MAX_N];
string s1, s2;

int f(int idx1, int idx2)
{
	if (idx1 == N && idx2 == M)
		return 0;

	int& ret = cache[idx1][idx2];
	if (ret != -1)
		return ret;
	ret = INF;
	if (idx1 == 0 && idx2 == 0)
		return ret = f(idx1 + 1, idx2 + 1) + abs(s1[idx1] - s2[idx2]);

	if (idx1 + 1 <= N && idx2 + 1 <= M)
		ret = min(ret, f(idx1 + 1, idx2 + 1) + abs(s1[idx1] - s2[idx2]));
	if (idx1 + 1 <= N)
		ret = min(ret, f(idx1 + 1, idx2) + abs(s1[idx1] - s2[idx2 - 1]));
	if (idx2 + 1 <= M)
		ret = min(ret, f(idx1, idx2 + 1) + abs(s1[idx1 - 1] - s2[idx2]));
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	cin >> s1 >> s2;
	cout << f(0, 0);

}