//헤일스톤 수열은 다음과 같이 정의 한다.
//
//n이 짝수라면, 2로 나눈다.
//n이 홀수라면, 3을 곱한 뒤 1을 더한다.
//헤일스톤 추측은 임의의 양의 정수 n으로 수열을 시작한다면, 항상 4, 2, 1, 4, 2, 1, ...로 끝난다는 추측이다.이 문제에서는 1이 나오면 수열이 끝난 것으로 처리한다.
//
//n이 주어졌을 때, 이 수열에서 가장 큰 값을 찾아 출력하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 100, 000)가 주어진다.다음 줄부터 T개의 줄에는 헤일스톤 수열의 시작값 n이 주어진다. (1 ≤ n ≤ 100, 000)
//
//출력
//각각의 테스트 케이스에 대해서, n으로 시작하는 헤일스톤 수열에서 가장 큰 값을 출력한다.
#include <iostream>
#include <string.h>
using namespace std;

int maxN ;

int f(int n)
{
	//cout << "f(" << n << ")" << "\n";
	maxN = n > maxN ? n : maxN;

	if (n == 1)
		return 0;

	if (n % 2 == 0)
	 f(n / 2);
	else
	f((3 * n) + 1);

	return 0;
	
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		maxN = 0;
		f(n);
		printf("%d\n", maxN);

	 }
}