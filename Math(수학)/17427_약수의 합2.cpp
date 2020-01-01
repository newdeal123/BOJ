#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N = (int)1e6+ 1;
ll ans[MAX_N] = { 0, };

void getAns()
{
	for (int i = 1; i <= MAX_N; i++)
		for (int j = 1; j <= MAX_N / i; j++)
			ans[i * j] += j;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getAns();
	int N;
	cin >> N;
	ll sum = 0;
	for (int i = 1; i <= N; i++)sum += ans[i];
	cout << sum;
}