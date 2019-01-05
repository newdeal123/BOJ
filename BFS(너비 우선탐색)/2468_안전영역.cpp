// 재난방재청에서는 많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다. 먼저 어떤 지역의 높이 정보를 파악한다. 
// 그 다음에 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 지는 지를 조사하려고 한다. 
// 이때, 문제를 간단하게 하기 위하여, 장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정한다.

// 어떤 지역의 높이 정보는 행과 열의 크기가 각각 N인 2차원 배열 형태로 주어지며 배열의 각 원소는 해당 지점의 높이를 표시하는 자연수이다. 
// 물에 잠기지 않는 안전한 영역이라 함은 물에 잠기지 않는 지점들이 
// 위, 아래, 오른쪽 혹은 왼쪽으로 인접해 있으며 그 크기가 최대인 영역을 말한다.
// (꼭짓점으로만 붙어 있는 두 지점은 인접하지 않는다고 취급한다). 
// 어떤 지역의 높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하는 프로그램을 작성하시오. 

// 입력
// 첫째 줄에는 어떤 지역을 나타내는 2차원 배열의 행과 열의 개수를 나타내는 수 N이 입력된다. 
// N은 2 이상 100 이하의 정수이다. 둘째 줄부터 N개의 각 줄에는 2차원 배열의 첫 번째 행부터 N번째 행까지 
// 순서대로 한 행씩 높이 정보가 입력된다. 각 줄에는 각 행의 첫 번째 열부터 N번째 열까지 N개의 높이 정보를 나타내는 자연수가
//  빈 칸을 사이에 두고 입력된다. 높이는 1이상 100 이하의 정수이다.

// 출력
// 첫째 줄에 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다.
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	int n;
	int map[105][105];
	int map_copy[105][105];
	int str[101] = { 1, };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &map[i][j]);
			map_copy[i][j] = map[i][j];
		}
	}
	
	for (int i = 1; i <= 100; i++) {

		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= n; y++)
			{
				map[x][y] = map_copy[x][y];
			}
		}
		int visit[101][101] = { 0, };
		int turn = 0;
		for (int a = 1; a <= n; a++){
			for (int b = 1; b <= n; b++) {
				if (map[a][b] > i)
					map[a][b] = 1;
				else
					map[a][b] = 0;
			}
		}
		
		queue <int> g;
		queue <int> s;
		int now_g = 0;
		int now_s = 0;
		while (1) {
			for (int a = 1; a <= n; a++) {
				for (int b = 1; b <= n; b++) {
					if (map[a][b] == 1 && visit[a][b] == 0) {
						turn++;
						now_g = b;
						now_s = a;
						goto gate1;
					}
					if (a == n && b == n)
						goto fin;

				}
			}
		gate1:
			visit[now_s][now_g] = 1;
			g.push(now_g);
			s.push(now_s);
			while (!g.empty())
			{
				now_g = g.front();
				now_s = s.front();
				g.pop();
				s.pop();
				if (map[now_s - 1][now_g] == 1 && visit[now_s - 1][now_g] == 0) {
					g.push(now_g);
					s.push(now_s - 1);
					visit[now_s - 1][now_g] = 1;
				}
				if (map[now_s + 1][now_g] == 1 && visit[now_s + 1][now_g] == 0) {
					g.push(now_g);
					s.push(now_s + 1);
					visit[now_s + 1][now_g] = 1;
				}
				if (map[now_s][now_g - 1] == 1 && visit[now_s][now_g - 1] == 0) {
					g.push(now_g - 1);
					s.push(now_s);
					visit[now_s][now_g - 1] = 1;
				}
				if (map[now_s][now_g + 1] == 1 && visit[now_s][now_g + 1] == 0) {
					g.push(now_g + 1);
					s.push(now_s);
					visit[now_s][now_g + 1] = 1;
				}

			}

		}


	fin:str[i] = turn;

	}
		sort(str, str + 101);
		printf("%d", str[100]);
}