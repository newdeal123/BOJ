//정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 3가지가 있다.합을 나타낼 때는 수를 1개 이상 사용해야 한다.단, 같은 수를 두 번 이상 연속해서 사용하면 안된다.
//
//1 + 2 + 1
//1 + 3
//3 + 1
//정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 테스트 케이스의 개수 T가 주어진다.각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다.n은 양수이며 100, 000보다 작거나 같다.
//
//출력
//각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1, 000, 000, 009로 나눈 나머지를 출력한다.
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 100000 + 2;
const int MOD = (int)1E9 + 9;

long long cache[MAX_N][4];

long long f(int n, int lastN)
{
	if (n == 0)
		return 1;

	long long &ret = cache[n][lastN];
	if (ret != -1)
		return ret % MOD;

	ret = 0;
	if (n - 3 >= 0)
	{
		for (int i = 1; i <= 3; i++)
			if (lastN != i)
				ret += f(n - i, i) % MOD;
	}
	else if (n - 2 >= 0)
	{
		for (int i = 1; i <= 2; i++)
			if (lastN != i)
				ret += f(n - i, i) % MOD;
	}
	else
		if (lastN != 1)
			ret += f(n - 1, 1) % MOD;

	return ret%MOD;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << f(n, 0) % MOD << "\n";
	}
}