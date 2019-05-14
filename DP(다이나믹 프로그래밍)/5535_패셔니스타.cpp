#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#pragma warning(disable:4996)
typedef long long ll;
using namespace std;
const int INF = 987654321;
const int MAX_N = 200 + 2;
int D, N;
struct Clothes
{
	int minTemp, maxTemp, fashion;
};
int weather[MAX_N], cache[MAX_N][101];
Clothes clothes[MAX_N];

int f(int days, int lastFashion)
{
	if (days == D)
		return 0;

	int&ret = cache[days][lastFashion];
	if (ret != -1)
		return ret;

	for (int i = 0; i < N; i++)
	{
		if (clothes[i].minTemp > weather[days] || weather[days] > clothes[i].maxTemp)
			continue;
		int add = 0;
		if (days != 0)
			add = abs(lastFashion - clothes[i].fashion);
		ret = max(ret, f(days + 1, clothes[i].fashion) + add);
	}
	return ret;
}


int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> D >> N;
	for (int i = 0; i < D; i++)
		cin >> weather[i];
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		clothes[i] = { a,b,c };
	}
	cout << f(0, 0);
}