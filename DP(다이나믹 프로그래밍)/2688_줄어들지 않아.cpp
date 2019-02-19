//어떤 숫자가 줄어들지 않는다는 것은 그 숫자의 각 자리 수보다 그 왼쪽 자리 수가 작거나 같을 때 이다.
//
//예를 들어, 1234는 줄어들지 않는다.
//
//줄어들지 않는 4자리 수를 예를 들어 보면 0011, 1111, 1112, 1122, 2223이 있다.줄어들지 않는 4자리수는 총 715개가 있다.
//
//이 문제에서는 숫자의 앞에 0(leading zero)이 있어도 된다. 0000, 0001, 0002는 올바른 줄어들지 않는 4자리수이다.
//
//n이 주어졌을 때, 줄어들지 않는 n자리 수의 개수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 테스트 케이스의 개수 T(1 <= T <= 1, 000)이 주어진다.각 테스트 케이스는 숫자 하나 n으로 이루어져 있다. (1 <= n <= 64)
//
//출력
//각 테스트 케이스에 대해 한 줄에 하나씩 줄어들지 않는 n자리 수의 개수를 출력한다.

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_N 64
long long cache[10][MAX_N+2];

long long f(int n, int k)
{
	if (k == 1)
		return 1;

	long long& ret = cache[n][k];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = n; i < 10; i++)
		ret += f(i, k - 1);

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int t; cin >> t;
	while (t--)
	{
		int n;  long long sum = 0;
		cin >> n;
		for (int i = 0; i < 10; i++)
			sum += f(i, n);

		cout << sum << endl;
	}
}