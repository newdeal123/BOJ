//수빈이가 세상에서 가장 좋아하는 것은 소수이고, 취미는 소수를 가지고 노는 것이다.요즘 수빈이가 가장 관심있어 하는 소수 7331이다.
//
//7331은 소수인데, 신기하게도 733도 소수이고, 73도 소수이고, 7도 소수이다.
//즉, 왼쪽부터 1자리, 2자리, 3자리, 4자리 수 모두 소수이다!수빈이는 이런 숫자를 신기한 소수라고 이름 붙였다.
//
//수빈이는 N자리의 숫자 중에서 어떤 수들이 신기한 소수인지 궁금해졌다.N이 주어졌을 때, 수빈이를 위해 N자리 신기한 소수를 모두 찾아보자.
//
//입력
//첫재 줄에 N(1 ≤ N ≤ 8)이 주어진다.
//
//출력
//N자리 수 중에서 신기한 소수를 오름차순으로 정렬해서 한 줄에 하나씩 출력한다.
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int N;
int arr[9];

bool isPrime(int n)
{
	if (n == 0 || n == 1)
		return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

bool check(int idx)
{
	string s;
	s.resize(idx + 1);
	for (int i = 0; i <= idx; i++)
		s[i] = arr[i] + '0';
	if (isPrime(stoi(s)))
		return true;
	return false;
}


void dfs(int idx)
{
	if (idx == N)
	{
		for (int i = 0; i < N; i++)
			cout << arr[i];
		cout << "\n";
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		arr[idx] = i;
		if (check(idx))
			dfs(idx + 1);
	}
}

int main()
{
	cin >> N;
	dfs(0);
}