//N - Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
//
//N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 N이 주어진다. (1 ≤ N < 15)
//
//	출력
//	첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
#include <iostream>
using namespace std;
int N;
int cnt = 0;
int arr[15];

bool check(int idx)
{
	for (int i = 1; i < idx; i++)
	{
		if (arr[i] == arr[idx] || abs(arr[idx] - arr[i]) == (idx - i))
			return false;
	}
	return true;
}

void f(int n)
{
	if (n > N)
	{
		cnt++;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		arr[n] = i;
		if (check(n))
			f(n + 1);
	}
	
}

int main()
{
	cin >> N;
	f(1);
	cout << cnt;
}