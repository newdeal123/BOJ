// 적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

// 크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 
// 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다.
//  또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. 
// (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)
// 그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)

// 둘째 줄부터 N개 줄에는 그림이 주어진다.

// 출력
// 적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	int n;
	int turn = 0;
	int map[105][105];
	char str[105][105];
	int visit[105][105];
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf(" %c", &str[i][j]);
			if (str[i][j] == 'R')
				map[i][j] = 1;
			else if (str[i][j] == 'G')
				map[i][j] = 2;
			else if (str[i][j] == 'B')
				map[i][j] = 3;

			visit[i][j] = 0;
		}
	}
	
	queue <int> g;
	queue <int> s;
	while (1) {

		int now_color = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (visit[i][j] == 0)
				{
					now_color = map[i][j];
					visit[i][j] = 1;
					g.push(j);
					s.push(i);
					goto gate1;
				}
				if (i == n && j == n)
					goto fin;
			}
		}
	gate1:
		while (!g.empty())
		{
			int now_g = g.front();
			int now_s = s.front();
			g.pop();
			s.pop();
			if (map[now_s + 1][now_g] == now_color && visit[now_s + 1][now_g] == 0)
			{
				s.push(now_s + 1);
				g.push(now_g);
				visit[now_s + 1][now_g] = 1;
			}
			if (map[now_s][now_g + 1] == now_color && visit[now_s][now_g + 1] == 0)
			{
				s.push(now_s);
				g.push(now_g + 1);
				visit[now_s][now_g + 1] = 1;
			}
			if (map[now_s - 1][now_g] == now_color && visit[now_s - 1][now_g] == 0)
			{
				s.push(now_s - 1);
				g.push(now_g);
				visit[now_s - 1][now_g] = 1;
			}
			if (map[now_s][now_g - 1] == now_color && visit[now_s][now_g - 1] == 0)
			{
				s.push(now_s);
				g.push(now_g - 1);
				visit[now_s][now_g - 1] = 1;
			}


		}

		turn++;


	}
fin:
	printf("%d ", turn);

	//방문 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			visit[i][j] = 0;
		}
	}
	 queue <int> g2;
	 queue <int> s2;

	 turn = 0;
	//적색맹자
	while (1) {
		

		int now_color = 0;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (visit[i][j] == 0)
				{
					now_color = map[i][j];
					visit[i][j] = 1;
					g2.push(j);
					s2.push(i);
					if (now_color == 1 || now_color == 2)
						goto only_rg;
					else
						goto gate2;
				}
				if (i == n && j == n)
					goto fin2;
			}
		}
	only_rg:
		while (!g2.empty())
		{
			int now_g = g2.front();
			int now_s = s2.front();
			g2.pop();
			s2.pop();
			if ( (map[now_s + 1][now_g] == 1 || map[now_s + 1][now_g] == 2) && visit[now_s + 1][now_g] == 0)
			{
				s2.push(now_s + 1);
				g2.push(now_g);
				visit[now_s + 1][now_g] = 1;
			}
			if ( (map[now_s][now_g + 1] == 1 || map[now_s][now_g + 1] == 2) && visit[now_s][now_g + 1] == 0)
			{
				s2.push(now_s);
				g2.push(now_g + 1);
				visit[now_s][now_g + 1] = 1;
			}
			if ((map[now_s - 1][now_g] == 1 || map[now_s - 1][now_g] == 2 ) && visit[now_s - 1][now_g] == 0)
			{
				s2.push(now_s - 1);
				g2.push(now_g);
				visit[now_s - 1][now_g] = 1;
			}
			if ((map[now_s][now_g - 1] == 1 || map[now_s][now_g - 1] == 2 ) && visit[now_s][now_g - 1] == 0)
			{
				s2.push(now_s);
				g2.push(now_g - 1);
				visit[now_s][now_g - 1] = 1;
			}


		}

		turn++;

	gate2:
		while (!g2.empty())
		{
			int now_g = g2.front();
			int now_s = s2.front();
			g2.pop();
			s2.pop();
			if (map[now_s + 1][now_g] == now_color && visit[now_s + 1][now_g] == 0)
			{
				s2.push(now_s + 1);
				g2.push(now_g);
				visit[now_s + 1][now_g] = 1;
			}
			if (map[now_s][now_g + 1] == now_color && visit[now_s][now_g + 1] == 0)
			{
				s2.push(now_s);
				g2.push(now_g + 1);
				visit[now_s][now_g + 1] = 1;
			}
			if (map[now_s - 1][now_g] == now_color && visit[now_s - 1][now_g] == 0)
			{
				s2.push(now_s - 1);
				g2.push(now_g);
				visit[now_s - 1][now_g] = 1;
			}
			if (map[now_s][now_g - 1] == now_color && visit[now_s][now_g - 1] == 0)
			{
				s2.push(now_s);
				g2.push(now_g - 1);
				visit[now_s][now_g - 1] = 1;
			}


		}

		if (now_color == 3)
			turn++;



	}
fin2:
	printf("%d", turn);
}
