#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 1000000 + 2;
int N;
double cache[MAX_N];

double f(int n)
{
	if (n <= 0) return 0.0;
	double &ret = cache[n];
	if (ret > -0.5) return ret;
	ret = 0.0;

	for (int i = 1; i <= 6; i++)
		ret += f(n - i) + 1;
	return ret /= 6.0;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cout << fixed;
	cout.precision(11);
	cout << f(N);
}