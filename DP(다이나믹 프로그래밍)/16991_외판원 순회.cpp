#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
const int MAX_N = 16 + 2;
const double INF = 987654321.0;
int N;
pair <int, int> city[MAX_N];
double cache[MAX_N][1 << 16];

double get_dist(int y1, int x1, int y2, int x2)
{
	double ret = (double)(y1 - y2) * (double)(y1 - y2) + (double)(x1 - x2) *(double)(x1 - x2);
	return sqrt(ret);
}

double f(int now, int bit)
{
	if (bit == (1 << N) - 1)
		return get_dist(city[now].first,city[now].second, city[0].first , city[0].second);

	double& ret = cache[now][bit];
	if (ret > 0)
		return ret;

	ret = INF;
	for (int i = 0; i < N; i++)
	{
		if (bit & (1 << i))
			continue;
		double dist = get_dist(city[now].first, city[now].second, city[i].first, city[i].second);
			ret = min(ret, f(i, bit | (1 << i)) + dist);
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		city[i] = make_pair(a, b);
	}
	cout << fixed;
	cout.precision(8);
	cout << f(0, 1);
}