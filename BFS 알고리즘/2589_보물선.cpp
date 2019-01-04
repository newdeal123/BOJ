/*보물섬 지도를 발견한 후크 선장은 보물을 찾아나섰다. 보물섬 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 
각 칸은 육지(L)나 바다(W)로 표시되어 있다. 이 지도에서 이동은 상하좌우로 이웃한 육지로만 가능하며, 한 칸 이동하는데 한 시간이 걸린다. 
보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다. 
육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안된다.
보물 지도가 주어질 때, 보물이 묻혀 있는 두 곳 간의 최단 거리로 이동하는 시간을 구하는 프로그램을 작성하시오.
입력
첫째 줄에는 보물 지도의 세로의 크기와 가로의 크기가 빈칸을 사이에 두고 주어진다. 이어 L과 W로 표시된 보물 지도가 아래의 예와 같이 주어지며, 각 문자 사이에는 빈 칸이 없다. 보물 지도의 가로, 세로의 크기는 각각 50이하이다.

출력
첫째 줄에 보물이 묻혀 있는 두 곳 사이를 최단 거리로 이동하는 시간을 출력한다.*/


#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	char island[101][101];
	int visit[101][101] = { 0, };
	int  sum[101][101] = { 0, };
	int n, m;
	int max = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf(" %c", &island[i][j]);
		}
	}
	

	queue <int> g;
	queue <int> s;
	while (1) {
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (island[i][j]== 'L' && visit[i][j] == 0)
				{
					visit[i][j] = 1;
					g.push(j);
					s.push(i);
					goto gate1;
				}
				if (i == n && j == m)
					goto fin;
			}
		}

	gate1:
		int visit2[101][101] = { 0, };

		for (int i = 0; i <= 100; i++)
		{
			for (int j = 0; j <= 100; j++)
			{
				sum[i][j] = 0;
				visit2[i][j] = 0;
			}
		 }

		while (!g.empty())
		{
			int now_g = g.front();
			int now_s = s.front();
			g.pop();
			s.pop();
			if (island[now_s + 1][now_g] == 'L' && visit2[now_s + 1][now_g] == 0)
			{
				visit2[now_s + 1][now_g] = 1;
				s.push(now_s + 1);
				g.push(now_g);
				sum[now_s + 1][now_g] = sum[now_s][now_g] + 1;
			}
			if (island[now_s][now_g + 1] == 'L' && visit2[now_s][now_g + 1] == 0)
			{
				visit2[now_s][now_g + 1] = 1;
				s.push(now_s);
				g.push(now_g + 1);
				sum[now_s][now_g + 1] = sum[now_s][now_g] + 1;
			}
			if (island[now_s - 1][now_g] == 'L' && visit2[now_s - 1][now_g] == 0)
			{
				visit2[now_s - 1][now_g] = 1;
				s.push(now_s - 1);
				g.push(now_g);
				sum[now_s - 1][now_g] = sum[now_s][now_g] + 1;
			}
			if (island[now_s][now_g - 1] == 'L' && visit2[now_s][now_g - 1] == 0)
			{
				visit2[now_s][now_g - 1] = 1;
				s.push(now_s);
				g.push(now_g - 1);
				sum[now_s][now_g - 1] = sum[now_s][now_g] + 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (sum[i][j] > max)
					max = sum[i][j];
			}
		}
	}
fin:

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (sum[i][j] > max)
				max = sum[i][j];
		}
	}
	printf("%d", max);

    return 0;
}