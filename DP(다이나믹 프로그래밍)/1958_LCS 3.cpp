#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
const int INF = 987654321;
const int MAX_N = 100 + 2;
string s1, s2, s3;
int cache[MAX_N][MAX_N][MAX_N];
int go1[6] = { 1,0,0,1,1,0 };
int go2[6] = { 0,1,0,1,0,1 };
int go3[6] = { 0,0,1,0,1,1 };

int f(int idx1, int idx2, int idx3)
{
	if (idx1 == s1.size() || idx2 == s2.size() || idx3 == s3.size())
		return 0;

	int&ret = cache[idx1][idx2][idx3];
	if (ret != -1)
		return ret;

	if (s1[idx1] == s2[idx2] && s2[idx2] == s3[idx3])
		ret = max(ret, f(idx1 + 1, idx2 + 1, idx3 + 1) + 1);

	
	for (int i = 0; i < 6; i++)
	{
		int next_idx1 = idx1 + go1[i];
		int next_idx2 = idx2 + go2[i];
		int next_idx3 = idx3 + go3[i];
		ret = max(ret, f(next_idx1, next_idx2, next_idx3));
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> s1 >> s2 >> s3;
	cout << f(0, 0, 0);
}