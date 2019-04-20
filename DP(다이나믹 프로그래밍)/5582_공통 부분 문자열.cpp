#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
const int MAX_N = 4000 + 2;
using namespace std;
string s1, s2;
int cache[MAX_N][MAX_N];

int f(int idx1, int idx2)
{
	if (idx1 == s1.size() || idx2 == s2.size())
		return 0;

	int& ret = cache[idx1][idx2];
	if (ret != -1)
		return ret;
	
	if (s1[idx1] == s2[idx2])
		return ret = f(idx1 + 1, idx2 + 1) + 1;
	else
		return ret = 0;
}

int main()
{
	int maxN = 0;
	memset(cache, -1, sizeof(cache));
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
		for (int j = 0; j < s2.size(); j++)
			maxN = max(maxN, f(i, j));
	cout << maxN;

}