#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 200 + 2;
string s1, s2, s3;
int cache[MAX_N][MAX_N];

int f(int idx1, int idx2)
{
	int idx3 = idx1 + idx2;
	if (idx3 == s3.size())
		return 1;
	int&ret = cache[idx1][idx2];
	if (ret != -1)
		return ret;
	ret = 0;
	if (s1[idx1] == s3[idx3])
		ret = max(ret, f(idx1 + 1, idx2));
	if (s2[idx2] == s3[idx3])
		ret = max(ret, f(idx1, idx2 + 1));
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		memset(cache, -1, sizeof(cache));
		cin >> s1 >> s2 >> s3;
		int tmp = f(0, 0);
		string ans;
		if (tmp == 1)
			ans = "yes";
		else
			ans = "no";
		cout << "Data set " << i << ": " << ans << "\n";
	}
}