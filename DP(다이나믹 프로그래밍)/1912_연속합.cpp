// n개의 정수로 이루어진 임의의 수열이 주어진다.
//  우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 
//  단, 수는 한 개 이상 선택해야 한다.

// 예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

// 입력
// 첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 
// 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

// 출력
// 첫째 줄에 답을 출력한다.

#include <stdio.h>
int max(int a, int b)
{
	if (a >= b)  return a;
	else         return b;
}


int main()
{
	int num;
	int happen = 0;
	int point = 0;
	int max_num = 0;
	int str[100010];
	int sum[100010];
	sum[0] = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &str[i]);
	}
	if (num == 1)
	{
		printf("%d", str[0]);
		return 0;
	}
	for (int i = 1; i <= num; i++)
	{
		if (happen == 1)
		{
			sum[i] = str[i - 1];
			happen = 0;
		}
		else
		{
			sum[i] = sum[i - 1] + str[i - 1];
		}
		if (sum[i] <= -1 || i == num)
		{

			for (int j = point; j < i; j++)
			{
				if (i==1)
				{
					max_num = sum[1];
				}
				else
					max_num = max(max_num, max(sum[j], sum[j + 1]));
			}
			happen++;
			point = i;
		}


	}
	printf("%d", max_num);


	return 0;
}