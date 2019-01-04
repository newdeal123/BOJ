// 네 자리 소수 두 개를 입력받아서 바꾸는데 몇 단계나 필요한지 계산하시오.
// 입력은 항상 네 자리 소수만(1000 이상) 주어진다고 가정하자.
//  주어진 두 소수 A에서 B로 바꾸는 과정에서도 항상 네 자리 소수임을 유지해야 하고,
//  ‘네 자리 수’라 하였기 때문에 0039 와 같은 1000 미만의 비밀번호는 허용되지 않는다.

//  입력
// 첫 줄에 test case의 수 T가 주어진다. 다음 T줄에 걸쳐 각 줄에 1쌍씩 네 자리 소수가 주어진다.

// 출력
// 각 test case에 대해 두 소수 사이의 변환에 필요한 최소 회수를 출력한다. 불가능한 경우 Impossible을 출력한다.

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	int prime[10005];
	int size = 0;
	//소수를 prime배열에 size크기만큼 배열
	for (int i = 1000; i <= 9999; i++)
	{
		int point = 0;
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0)
				point++;
		}
		if (point == 0)
		{
			prime[size] = i;
			size++;
		}
	}
	//테스트케이스 t
	int t;
	scanf("%d", &t);
	for (int qwe = 0; qwe < t; qwe++)
	{
		int sum[10005];
		int visit[10005];
		//초기화
		for (int asd = 0; asd < 10005; asd++)
		{
			sum[asd] = 0;
			visit[asd] = 0;
		}

		queue <int> q;
		int st, now_copy;
		int fin;
		int now = st;
		scanf("%d %d", &st, &fin);
		
		visit[st] = 1;
		q.push(st);

		//bfs돌리기
		while (!q.empty())
		{
		
			now = q.front();
			q.pop();
			
			int aim[5] = { 0,0,0,0,0 };
			now_copy = now;
		
			//now의 자리수마다 aim배열에 저장
			for (int i = 1; i <= 4; i++)
			{
				aim[i] = now % 10;
				now = now / 10;
			}
			now = now_copy;

			for (int i = 0; i < size; i++)
			{
				
				int aim2[5] = { 0,0,0,0,0 };
				int i_copy = prime[i];
				
				//i번째 자리수마다 aim2배열에 저장
				for (int j = 1; j <= 4; j++)
				{
					aim2[j] = prime[i] % 10;
					prime[i] = prime[i] / 10;
				}
				prime[i] = i_copy;

				int p = 0;

				for (int k = 1; k <= 4; k++)
				{
					if (aim[k] == aim2[k])
						p++;
				}

				//3자리가 일치하고 방문하지않았다면 q에넣음
				if (p == 3 && visit[prime[i]] == 0)
				{
					
					visit[prime[i]] = 1;
					q.push(prime[i]);
					sum[prime[i]] = sum[now] + 1;
				}

			}
		}
		if (sum != 0)
			printf("%d\n", sum[fin]);
		else
			printf("Impossible");

	}
}