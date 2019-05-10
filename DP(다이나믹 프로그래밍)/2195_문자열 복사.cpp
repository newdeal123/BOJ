#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_N = 1000 + 2;
string s, p;
int cache[MAX_N];
int cache2[MAX_N][MAX_N];

int sameLen(int s_idx, int p_idx)
{
	int&ret = cache2[s_idx][p_idx];
	if (ret != -1)
		return ret;

	for (int i = 1; ; i++)
	{
		if (s_idx + i >= s.size() || p_idx + i >= p.size())
			return ret = i;
		if (s[s_idx + i] != p[p_idx + i])
			return ret = i;	
	}

}

int f(int idx)
{
	if (idx >= p.size())
		return 0;

	int&ret = cache[idx];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int start = 0; start < s.size(); start++)
	{
		if (s[start] != p[idx])
			continue;
		ret = min(ret, f(idx + sameLen(start, idx)) + 1);
	}

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> s;
	cin >> p;
	cout << f(0);
}