#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_N = 500 + 2;
int n, a, b, cache[MAX_N][MAX_N][10];

int f(int score, int turn, int Dturn)
{
	if ((double)Dturn > (double)turn*(0.1)) return INF;
	if (score >= n)
	{
		if (score >= n + a) return INF;
		else return turn;
	}

	int&ret = cache[score][turn][Dturn];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, f(score * 2, turn + 1, Dturn + 1));
	ret = min(ret, f(score + a, turn + 1, Dturn));
	ret = min(ret, f(score + b, turn + 1, Dturn));
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> n >> a >> b;
	cout << f(0, 0, 0);
}