// 체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 이동하려고 하는 칸이 주어진다. 
// 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?

// 입력
// 입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.
// 각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 
// 체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다.
//  둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

// 출력
// 각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 있는지 출력한다.
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int j = 0; j < n; j++)
	{
		int str[305][305] = { 0, };
		int visit[305][305] = { 0, };
		int i,x1,x2,y1,y2;
		scanf("%d", &i);
		scanf("%d %d", &x1, &y1);
		scanf("%d %d", &x2, &y2);
		queue <int> g;
		queue <int> s;
		visit[x1][y1] = 1;
		g.push(y1);
		s.push(x1);
		int now_g ;
		int now_s ;
		int turn = 0;
		while (1)
		{
			now_g = g.front();
			now_s = s.front();
			g.pop();
			s.pop();
			if (now_g == y2 && now_s == x2)
				break;
			if (visit[now_s+1][now_g-2] == 0 && now_s + 1 >= 0 && now_s + 1 <= i && now_g - 2 >= 0 && now_g - 2 <= i) {
				g.push(now_g - 2);
				s.push(now_s + 1);
				visit[now_s + 1][now_g - 2]=1;
				str[now_s + 1][now_g - 2] = str[now_s][now_g] + 1;
			}
			if (visit[now_s + 1][now_g+2] == 0 && now_s + 1 >= 0 && now_s + 1 < i && now_g + 2 >= 0 && now_g + 2 < i) {
				g.push(now_g + 2);
				s.push(now_s + 1);
				visit[now_s + 1][now_g + 2] = 1;
				str[now_s + 1][now_g + 2]= str[now_s][now_g] + 1;
			}
			if (visit[now_s-1][now_g-2] == 0 && now_s - 1 >= 0 && now_s - 1 < i && now_g - 2 >= 0 && now_g - 2 < i) {
				g.push(now_g - 2);
				s.push(now_s - 1);
				visit[now_s - 1][now_g - 2] = 1;
				str[now_s - 1][now_g - 2]= str[now_s][now_g] + 1;
			}
			if (visit[now_s - 1][now_g +2] == 0 && now_s - 1 >= 0 && now_s - 1 < i && now_g + 2 >= 0 && now_g + 2 < i) {
				g.push(now_g + 2);
				s.push(now_s - 1);
				visit[now_s - 1][now_g + 2] = 1;
				str[now_s - 1][now_g + 2]= str[now_s][now_g] + 1;
			}
			if (visit[now_s+2][now_g-1] == 0 && now_s + 2 >= 0 && now_s + 2 < i && now_g - 1 >= 0 && now_g - 1 < i) {
				g.push(now_g - 1);
				s.push(now_s + 2);
				visit[now_s + 2][now_g - 1] = 1;
				str[now_s + 2][now_g - 1]= str[now_s][now_g] + 1;
			}
			if (visit[now_s + 2][now_g+1] == 0 && now_s + 2 >= 0 && now_s + 2 < i && now_g + 1 >= 0 && now_g + 1 < i) {
				g.push(now_g + 1);
				s.push(now_s + 2);
				visit[now_s + 2][now_g + 1] = 1;
				str[now_s + 2][now_g + 1] = str[now_s][now_g] + 1;
			}
			if (visit[now_s-2][now_g+1] == 0 && now_s - 2 >= 0 && now_s - 2 < i && now_g + 1 >= 0 && now_g + 1 < i) {
				g.push(now_g + 1);
				s.push(now_s - 2);
				visit[now_s - 2][now_g + 1] = 1;
				str[now_s - 2][now_g + 1] = str[now_s][now_g] + 1;
			}
			if (visit[now_s - 2][now_g-1] == 0 && now_s - 2 >= 0 && now_s - 2 < i && now_g - 1 >= 0 && now_g - 1 < i) {
				g.push(now_g - 1);
				s.push(now_s - 2);
				visit[now_s - 2][now_g - 1] = 1;
				str[now_s - 2][now_g - 1] = str[now_s][now_g] + 1;
			}

		}

		printf("%d\n", str[now_s][now_g]);
	}

	return 0;
}