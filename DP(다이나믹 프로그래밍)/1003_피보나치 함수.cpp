//N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 테스트 케이스의 개수 T가 주어진다.
//
//각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다.N은 40보다 작거나 같은 자연수 또는 0이다.
//
//출력
//각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.
#include <iostream>
#include <string.h> 
using namespace std;
int N; 
int save = 2; 
int cache[2][41]; 


void fibonacci(int n)
{
	if (N >= save)
	{
		for (int i = save; i <= N; i++)
		{
			cache[0][i] = cache[0][i - 1] + cache[0][i - 2];
			cache[1][i] = cache[1][i - 1] + cache[1][i - 2];
		}
		save = N;
	}

}



void initialize(void)
{
	memset(cache, 0, sizeof(cache));
	//피보나치수열을 위해서는 앞에 두개의 숫자가 필요하므로
	cache[0][0] = 1;
	cache[1][1] = 1;
}



int main(void)
{
	int T; //test_case
	cin >> T;
	initialize();
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		if (N > 40 || N < 0)
			exit(-1);
		fibonacci(N);
		cout << cache[0][N] << " " << cache[1][N] << endl;
	}
	return 0;

}