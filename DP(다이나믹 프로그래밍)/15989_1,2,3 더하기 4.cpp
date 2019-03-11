//정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 4가지가 있다.합을 나타낼 때는 수를 1개 이상 사용해야 한다.합을 이루고 있는 수의 순서만 다른 것은 같은 것으로 친다.
//
//1 + 1 + 1 + 1
//2 + 1 + 1 (1 + 1 + 2, 1 + 2 + 1)
//2 + 2
//1 + 3 (3 + 1)
//정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 테스트 케이스의 개수 T가 주어진다.각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다.n은 양수이며 10, 000보다 작거나 같다.
//
//출력
//각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 10000 + 2;
int cache[MAX_N][4];

int f(int n, int lastN)
{
	if (n == 0)
		return 1;

	int&ret = cache[n][lastN];
	if (ret != -1)
		return ret;

	ret = 0;
	if (n - 3 >= 0)
	{
		for (int i = lastN; i <= 3; i++)
			ret += f(n - i, i);
	}
	else if (n - 2 >= 0)
	{
		for (int i = lastN; i <= 2; i++)
			ret += f(n - i, i);
	}
	else
	{
		for (int i = lastN; i <= 1; i++)
			ret += f(n - i, i);
	}
	return ret;
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
		cout << f(n, 1) << "\n";
	}
}