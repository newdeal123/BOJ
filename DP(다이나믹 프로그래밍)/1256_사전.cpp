#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int MAX = (int)1E9 + 100;
int bino[201][201] = { 0, };
int skip;

void get_bino()
{
	for (int i = 0; i < 201; i++)
	{
		bino[i][i] = bino[i][0] = 1;
		for (int j = 1; j < i; j++)
			bino[i][j] = min(bino[i - 1][j - 1] + bino[i - 1][j], MAX);
	}
}

void f(int n, int m, string s)
{
	if (skip < 0)
		return;

	if (n == 0 && m == 0)
	{
		if (skip == 0)
			cout << s << "\n";
		--skip;
		return;
	}

	if (bino[n + m][n] <= skip)
	{
		skip -= bino[n + m][n];
		return;
	}

	if (n > 0)
		f(n - 1, m, s + "a");
	if (m > 0)
		f(n, m - 1, s + "z");
}

int main()
{
	get_bino();
	int n, m;
	cin >> n >> m >> skip;
	skip -= 1;
	if (skip >= bino[n + m][n])
	{
		cout << "-1";
		return 0;
	}
	f(n, m, "");
}