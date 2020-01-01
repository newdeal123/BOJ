#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N = (int)1e4+ 1;
int ans[MAX_N] = { 0, };

void getAns()
{
	for (int i = 1; i <= MAX_N; i++)
		for (int j = 1; j <= MAX_N / i; j++)
			ans[i * j] += 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getAns();

	int t;
	cin >> t;

	while (t--)
	{
		int N;
		cin >> N;
		cout << N<< " " << ans[N] << "\n";
	}
}