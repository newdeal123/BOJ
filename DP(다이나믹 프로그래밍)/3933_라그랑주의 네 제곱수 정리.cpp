#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;
const int MAX_N = 1024*32;
int cache[MAX_N][183][5];

int f(int n, int lastuse, int canplus)
{
	if (n == 0)
		return 1;
	if (n < 0 || canplus <= 0 || lastuse==182)
		return 0;

	int&ret = cache[n][lastuse][canplus];
	if (ret != -1)
		return ret;
	ret = f(n,lastuse+1,canplus)+ f(n - lastuse*lastuse, lastuse, canplus - 1);

	return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	memset(cache, -1, sizeof(cache));
	while (true)
	{
		int n;
		cin >> n;
		if (!n)break;
		cout << f(n, 1, 4) << "\n";
	}
}
