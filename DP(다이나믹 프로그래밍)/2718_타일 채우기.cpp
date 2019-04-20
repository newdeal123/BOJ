#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 1000 + 2;
int N;
int cache[MAX_N][1 << 4];

int f(int idx, int bit)
{
	if (idx == N)
	{
		if (bit == 0)
			return 1;
		else
			return 0;
	}
	if (idx > N)
		return 0;

	int&ret = cache[idx][bit];
	if (ret != -1)
		return ret;

	ret = 0;
	if (bit == 0)
		ret += f(idx + 1, 0) + f(idx + 1, 12) + f(idx + 1, 3) + f(idx + 1, 9) + f(idx + 2, 0);
	else if (bit == 12) //1100
		ret += f(idx + 1, 0) + f(idx + 1, 3);
	else if (bit == 3) //0011
		ret += f(idx + 1, 0) + f(idx + 1, 12);
	else if (bit == 9) //1001
		ret += f(idx + 1, 0) + f(idx + 1, 6);
	else if (bit == 6)//0110
		ret += f(idx + 1, 9);
	return ret;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> N;
		cout << f(0, 0) << "\n";
	}
}