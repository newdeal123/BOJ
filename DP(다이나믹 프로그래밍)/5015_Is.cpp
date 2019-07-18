#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
const int MAX_N = 101;
string W, S;
int cache[MAX_N][MAX_N];

bool dp(int w, int s)
{
	int&ret = cache[w][s];
	if (ret != -1)
		return ret;

	while (s < S.size() && w < W.size() && W[w]==S[s])
	{
		++w, ++s;
	}
	if (w == W.size())
		return ret = (s == S.size());
	if (W[w] == '*')
		for (int skip = 0; skip + s <= S.size(); skip++)
			if (dp(w + 1, s + skip))
				return ret = 1;
	return ret = 0;
}

int main()
{
	cin >> W;
	int t;
	cin >> t;
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> S;
		if (dp(0, 0))
			cout << S << "\n";
	}
}