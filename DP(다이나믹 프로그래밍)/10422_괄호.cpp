//‘(‘, ‘)’ 문자로만 이루어진 문자열을 괄호 문자열이라 한다.올바른 괄호 문자열이란 다음과 같이 정의된다.
//()는 올바른 괄호 문자열이다.S가 올바른 괄호 문자열이라면, (S)도 올바른 괄호 문자열이다.
//S와 T가 올바른 괄호 문자열이라면, 두 문자열을 이어 붙인 ST도 올바른 괄호 문자열이다. 
//(()())()은 올바른 괄호 문자열이지만(()은 올바른 괄호 문자열이 아니다.괄호 문자열이 주어졌을 때 올바른 괄호 문자열인지 확인하는 방법은 여러 가지가 있다.
//
//	하지만 우리가 궁금한 것은 길이가 L인 올바른 괄호 문자열의 개수이다.길이 L이 주어졌을 때
//	길이가 L인 서로 다른 올바른 괄호 문자열의 개수를 출력하는 프로그램을 만들어 보자.
//
//	입력
//	첫 번째 줄에 테스트케이스의 개수를 나타내는 T(1 ≤ T ≤ 100)가 주어진다.두 번째 줄부터
//	각 테스트케이스마다 괄호 문자열의 길이를 나타내는 L이 주어진다. (1 ≤ L ≤ 5000)
//
//	출력
//	각 테스트 케이스에 대해 길이가 L인 올바른 괄호 문자열의 개수를 1, 000, 000, 007로 나눈 나머지를 출력하시오.
#include <iostream>
#include <string.h>
using namespace std;
const int MAX_N = 5000;
const int MOD = 1000000007;
int cache[MAX_N/2 + 1][MAX_N / 2 + 1];
int N;
//idx, '(' 의 수
int f(int idx, int sum)
{
	if (idx == 0)
	{
		if (sum == 0)
			return 1;
		else
			return 0;
	}
	//가지치기: '('수가 절반을 넘으면 ')'로 다 못덮는다.
	if (sum > N / 2)
		return 0;

	int&ret = cache[idx/2][sum];
	if (ret != -1)
		return ret%MOD;
	if (sum == 0)
		return ret = f(idx - 1, sum + 1) % MOD;
	else
		return ret = (f(idx - 1, sum - 1) + f(idx - 1, sum + 1)) % MOD;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;
	while (t--)
	{
		cin >> N;
		if (N % 2 == 1)
		{
			cout << "0\n";
			continue;
		}
		cout << f(N, 0) << "\n";
	}
}