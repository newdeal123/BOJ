//꿍은 군대에서 진짜 할짓이 없다.그래서 꿍만의 피보나치를 만들어보려고 한다.
//기존의 피보나치는 너무 단순해서 꿍은 좀더 복잡한 피보나치를 만들어보고자 한다.
//그래서 다음과 같은 피보나치를 만들었다.꿍만의 피보나치 함수가 koong(n)이라고 할 때,
//    n < 2 : 1
//	n = 2 : 2
//	n = 3 : 4
//	n > 3 : koong(n − 1) + koong(n − 2) + koong(n − 3) + koong(n − 4)
//	이다.
//
//	여러분도 꿍 피보나치를 구해보아라.
//
//	입력
//	입력의 첫 번째 줄을 테스트 케이스의 개수 t(0 < t < 69)가 주어진다.다음 t줄에는 몇 번째 피보나치를 구해야하는지를 나타내는 n(0 ≤ n ≤ 67)이 주어진다.
//
//	출력
//	각 테스트 케이스에 대해, 각 줄에 꿍 피보나치값을 출력하라.

#include <iostream>
using namespace std;

#define MAX_N 68
long long cache[MAX_N];

long long  koong(long long n)
{
	if (n < 2)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	long long& ret = cache[n];
	if (ret != -1)
		return ret;
	
	return ret = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
	
}

int main()
{
	for (int i = 0; i < MAX_N; i++)
		cache[i] = -1;
	int t;
	
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long n;
		cin >> n;
		cout << koong(n) << "\n";
	}
}