// 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

// 덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.

// 입력
// 첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.

// 출력
// 첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.


#include <stdio.h>
#pragma warning (disable: 4996)
#define size  1000000000
int main()
{
	int n, k;
	int str[205][205]; //바꾸기
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 202; i++)
	{
		str[i][1] = 1;
		str[0][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			for (int x = 0; x <= i; x++)
			{
				str[i][j]+= (str[x][j - 1])%size;
				str[i][j] = str[i][j] % size;
			}
		}
	}
	printf("%d", str[n][k]%size);



	return 0;
}