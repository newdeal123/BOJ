//자연수 과 정수 가 주어졌을 때 이항 계수 를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 과 가 주어진다. (1 ≤  ≤ 10, 0 ≤  ≤)
//
//출력
//를 출력한다.

#include <iostream>
using namespace std;


int f(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return f(n - 1) * n;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << f(n) / (f(k) * f(n - k));
	
}