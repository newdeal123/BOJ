//정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다.합을 나타낼 때는 수를 1개 이상 사용해야 한다.
//
//1 + 1 + 1 + 1
//1 + 1 + 2
//1 + 2 + 1
//2 + 1 + 1
//2 + 2
//1 + 3
//3 + 1
//정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 테스트 케이스의 개수 T가 주어진다.각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다.n은 양수이며 1, 000, 000보다 작거나 같다.
//
//출력
//각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1, 000, 000, 009로 나눈 나머지를 출력한다.
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = (int)1e6 + 2;
const int MOD = (int)1e9 + 9;

long long cache[MAX_N];

long long f(int n)
{
	if (n == 0)
		return 1;

	long long& ret = cache[n];
	if (ret != -1)
		return ret % MOD;

	if (n - 3 >= 0)
		return ret = (f(n - 1) + f(n - 2) + f(n - 3)) % MOD;
	else if (n - 2 >= 0)
		return ret = (f(n - 1) + f(n - 2)) % MOD;
	else
		return ret = f(n - 1) % MOD;
}

int main()
{
	int t;
	memset(cache, -1, sizeof(cache));
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << f(n) % MOD << "\n";
	}
}