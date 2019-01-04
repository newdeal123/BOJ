// 오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.

// 예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

// 수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.

// 입력
// 첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

// 출력
// 첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

#include <stdio.h>
#define size 10007

int main()
{
	int N;
	int str[1010][11];
	int sum = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10; j++) {
			str[i][j] = 0;
		}
	}

	for (int i = 0; i < 11; i++) str[1][i] = 1;
		
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = j; k <= 9; k++)
			{
				str[i][j] += str[i - 1][k];
				str[i][j]=str[i][j] % size;
			}
		}
	}


	for (int p = 0; p < 10; p++)
	{
		sum += str[N][p];
		sum=sum%size;
	}
	printf("%d", sum);


	return 0;
}