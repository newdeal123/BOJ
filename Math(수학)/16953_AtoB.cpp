//정수 A를 B로 바꾸려고 한다.가능한 연산은 다음과 같은 두 가지이다.
//
//2를 곱한다.
//1을 수의 가장 오른쪽에 추가한다.
//A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.
//
//입력
//첫째 줄에 A, B(1 ≤ A < B ≤ 10^9)가 주어진다.
//
//	출력
//	A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값을 출력한다.만들 수 없는 경우에는 - 1을 출력한다.
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = (int)1E9;
const long long INF = 98765431;
long long  A, B;

long long f(long long n)
{
	if (n == B)
		return 0;
	if (n > B)
		return INF;

	int ret;
	return ret = min(f(n * 2) + 1, f(n * 10 + 1) + 1);
}

int main()
{
	cin >> A >> B;
	if (f(A) >= INF)
		cout << "-1";
	else
		cout << f(A) + 1;
}

