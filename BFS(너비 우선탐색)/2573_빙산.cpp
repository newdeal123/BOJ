// 지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산을 그림 1과 같이 2차원 배열에 표시한다고 하자. 
// 빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 빙산 이외의 바다에 해당되는 칸에는 0이 저장된다.
//  그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.
//  빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 
//  배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 
//  단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 
//  한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오.
//  만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

//  입력
// 첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다. 
// N과 M은 3 이상 300 이하이다. 그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 
// 각 칸에 들어가는 값은 0 이상 10 이하이다. 배열에서 빙산이 차지하는 칸의 개수, 
// 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다. 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

// 출력
// 첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.

#include <stdio.h>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int n = 0, m = 0;
int map[301][301];


bool check() {

	queue <int> g;
	queue <int> s;
	int now_s = 0, now_g = 0;

	int vis[301][301];
	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			vis[i][j] = 0;
		}
	}
		
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] > 0 && vis[i][j] == 0)
			{
				vis[i][j] = 1;
				now_s = i;
				now_g = j;
				goto gate1;
			}
		}
	}

	gate1:
		g.push(now_g);
		s.push(now_s);

		while (!g.empty())
		{
			now_g = g.front();
			now_s = s.front();
			g.pop();
			s.pop();

			if (map[now_s + 1][now_g] > 0 && vis[now_s + 1][now_g] == 0)
			{
				vis[now_s + 1][now_g] = 1;
				s.push(now_s + 1);
				g.push(now_g);
			}
			if (map[now_s][now_g + 1] > 0 && vis[now_s][now_g + 1] == 0)
			{
				vis[now_s][now_g + 1] = 1;
				s.push(now_s);
				g.push(now_g + 1);
			}
			if (map[now_s - 1][now_g] > 0 && vis[now_s - 1][now_g] == 0)
			{
				vis[now_s - 1][now_g] = 1;
				s.push(now_s - 1);
				g.push(now_g);
			}
			if (map[now_s][now_g - 1] > 0 && vis[now_s][now_g - 1] == 0)
			{
				vis[now_s][now_g - 1] = 1;
				s.push(now_s);
				g.push(now_g - 1);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (map[i][j] > 0 && vis[i][j] == 0)
				{
					return false;
				}
			}
		}
			return true;
	
}


int main()
{
	
	int year = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	while (check())
	{
		int melt[301][301];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				melt[i][j] = 0;
				if (map[i + 1][j] == 0 && i + 1 > 0 && i + 1 <= n && j > 0 && j <= m)
				{
					melt[i][j]++;
				}
				if (map[i][j + 1] == 0 && i > 0 && i <= n &&  j + 1 > 0 && j + 1 <= m)
				{
					melt[i][j]++;
				}
				if (map[i - 1][j] == 0 && i - 1 > 0 && i - 1 <= n && j > 0 && j <= m)
				{
					melt[i][j]++;
				}
				if (map[i][j - 1] == 0 && i > 0 && i <= n && j - 1 > 0 && j - 1 <= m)
				{
					melt[i][j]++;
				}
			}
		}

		//1years ago
		year++;
		int check_0 = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				map[i][j] -= melt[i][j];

				if (map[i][j] < 0)
					map[i][j] = 0;

				if (map[i][j] == 0)
					check_0++;
			}
		}

		if (check_0 == n*m)
		{
			printf("0");
			return 0;
		}
	
	}


	printf("%d", year);
}