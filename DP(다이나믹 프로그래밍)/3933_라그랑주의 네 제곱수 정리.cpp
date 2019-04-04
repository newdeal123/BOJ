//양의 정수는 많아야 4개의 제곱수로 표현할 수 있다고 한다.이 이론을 라그랑주의 네 제곱수 정리라고 한다.이 정리는 조제프루이 라그랑주가 1770년에 증명했다.
//
//우리는 이 이론을 증명하거나 새로운 이론을 발견할 필요는 없고, n이 주어졌을 때 
//4개 이하의 양의 제곱수의 합으로 n을 만들 수 있는 경우의 수를 구하려고 한다.
//경우의 수를 구할 때 제곱수의 순서가 바뀌는 경우는 같은 경우로 본다.따라서 32 + 42 과 42 + 32는 같은 경우이다.
//
//N이 25일 때 4개 이하의 제곱수의 합으로 표현 할 수 있는 경우는 12 + 22 + 22 + 42, 32 + 42, 52 이렇게 3가지이다.
//
//입력
//입력은 최대 255줄이다.각 줄에는 215보다 작은 양의 정수가 하나씩 주어진다.마지막 줄에는 0이 하나 있고, 입력 데이터가 아니다.
//
//출력
//각 테스트 케이스에 대해서 입력으로 주어진 n을 많아야 4개의 제곱수로 나타내는 경우의 수를 출력한다.

#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;
const int MAX_N = 33000;
int cache[MAX_N][180 + 2][5]; //why 180? 180*180 =32400 almost 33000

int f(int n, int lastuse, int canplus)
{
	if (n == 0)
		return 1;
	if (n < 0 || canplus <= 0)
		return 0;

	int&ret = cache[n][lastuse][canplus];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = lastuse; i < 180; i++)
	{
			ret += f(n - i*i, i, canplus - 1);
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	while (true)
	{
		int n;
		cin >> n;
		if (!n)
			break;
		cout << f(n, 1, 4) << "\n";
	}
}