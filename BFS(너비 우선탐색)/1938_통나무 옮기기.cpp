//가로와 세로의 길이가 같은 평지에서 벌목을 한다.그 지형은 0과 1로 나타나 있다. 1은 아직 잘려지지 않은 나무를 나타내고 0은 아무 것도 없음을 나타낸다.다음 지형을 보자.
//
//B 0 0 1 1
//B 0 0 0 0
//B 0 0 0 0
//1 1 0 0 0
//E E E 0 0
//위의 지형에서 길이 3인 통나무 BBB를 밀거나 회전시켜 EEE의 위치로 옮기는 작업을 하는 문제를 생각해 보자.
//BBB와 EEE의 위치는 임의로 주어진다.단 문제에서 통나무의 길이는 항상 3이며 B의 개수와 E의 개수는 같다.
//통나무를 움직이는 방법은 아래와 같이 상하좌우(Up, Down, Left, Right)와 회전(Turn)이 있다.
//
//코드	의미
//U	통나무를 위로 한 칸 옮긴다.
//D	통나무를 아래로 한 칸 옮긴다.
//L	통나무를 왼쪽으로 한 칸 옮긴다.
//R	통나무를 오른쪽으로 한 칸 옮긴다.
//T	중심점을 중심으로 90도 회전시킨다.
//예를 들면, 다음과 같다. (초기상태로부터의 이동)
//
//초기상태	상(U)	하(D)	좌(L)	우(R)	회전(T)
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 B B B 0 0
//0 0 0 0 0 0
//0 0 0 1 0 0
//
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 B B B 0 0
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 0 0 1 0 0
//
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 B B B 0 0
//0 0 0 1 0 0
//
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 0 0 0 0 0
//B B B 0 0 0
//0 0 0 0 0 0
//0 0 0 1 0 0
//
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 0 B B B 0
//0 0 0 0 0 0
//0 0 0 1 0 0
//0 0 0 0 0 0
//
//0 0 0 0 0 0
//0 0 B 0 0 0
//0 0 B 0 0 0
//0 0 B 0 0 0
//0 0 0 1 0 0
//이와 같은 방식으로 이동시킬 때에 그 움직일 위치에 다른 나무, 즉 1이 없어야만 움직일 수 있다.
//그리고 움직임은 위의 그림과 같이 한 번에 한 칸씩만 움직인다.단 움직이는 통나무는 어떤 경우이든지 중간단계에서 한 행이나 한 열에만 놓일 수 있다.
//예를 들면 아래 그림에서 a와 같은 단계는 불가능하다.그리고 회전의 경우에서는 반드시 중심점을 중심으로 90도 회전을 해야 한다. (항상 통나무의 길이가 3이므로 중심점이 있음)
//
//그리고 이런 회전(Turn)이 가능하기 위해서는 그 통나무를 둘러싸고 있는 3 * 3 정사각형의 구역에 단 한 그루의 나무도 없어야만 한다.
//
//문제는 통나무를 5개의 기본동작(U, D, L, R, T)만을 사용하여 처음위치(BBB)에서 최종위치(EEE)로 옮기는 프로그램을 작성하는 것이다.단, 최소 횟수의 단위 동작을 사용해야 한다.
//
//입력
//첫째 줄에 주어진 평지의 한 변의 길이 N이 주어진다. (4 <= N <= 50) 주어진다.이어서 
//그 지형의 정보가 0, 1, B, E로 이루어진 문자열로 주어진다.한 줄에 입력되는 문자열의 길이는 N이며 입력 문자 사이에는 빈칸이 없다.통나무와 최종 위치의 개수는 1개이다.
//
//출력
//첫째 줄에 최소 동작 횟수를 출력한다.이동이 불가능하면 0만을 출력한다.
#include <iostream>
#include <queue>
#define MX 55
using namespace std;

struct WOOD {
	int x, y;
};

struct TOTAL {
	WOOD a, b, c;
	int dir;
}wood1, wood2, wood3;

queue <TOTAL> q;
char map[MX][MX];
int visit[2][MX][MX];
int N, cnt, sw;

void bfs()
{
	visit[q.front().dir][q.front().b.y][q.front().b.x] = 1;
	while (!q.empty())
	{
		wood2 = q.front();
		if (map[wood2.a.y][wood2.a.x] == 'E' && map[wood2.b.y][wood2.b.x] == 'E' && map[wood2.c.y][wood2.c.x] == 'E')
		{
			sw = 1; return;
		}
		q.pop();
		for (int i = 1; i <= 5; i++)
		{
			if (i == 1)
			{
				if (wood2.a.y == 0) continue;
				if (map[wood2.a.y - 1][wood2.a.x] == '1' || map[wood2.b.y - 1][wood2.b.x] == '1' || map[wood2.c.y - 1][wood2.c.x] == '1') continue;
				wood3.a.x = wood2.a.x; wood3.a.y = wood2.a.y - 1;
				wood3.b.x = wood2.b.x; wood3.b.y = wood2.b.y - 1;
				wood3.c.x = wood2.c.x; wood3.c.y = wood2.c.y - 1;
				wood3.dir = wood2.dir;
			}
			else if (i == 2)
			{
				if (wood2.c.y == N - 1) continue;
				if (map[wood2.a.y + 1][wood2.a.x] == '1' || map[wood2.b.y + 1][wood2.b.x] == '1' || map[wood2.c.y + 1][wood2.c.x] == '1') continue;
				wood3.a.x = wood2.a.x; wood3.a.y = wood2.a.y + 1;
				wood3.b.x = wood2.b.x; wood3.b.y = wood2.b.y + 1;
				wood3.c.x = wood2.c.x; wood3.c.y = wood2.c.y + 1;
				wood3.dir = wood2.dir;
			}
			else if (i == 3)
			{
				if (wood2.a.x == 0) continue;
				if (map[wood2.a.y][wood2.a.x - 1] == '1' || map[wood2.b.y][wood2.b.x - 1] == '1' || map[wood2.c.y][wood2.c.x - 1] == '1') continue;
				wood3.a.x = wood2.a.x - 1; wood3.a.y = wood2.a.y;
				wood3.b.x = wood2.b.x - 1; wood3.b.y = wood2.b.y;
				wood3.c.x = wood2.c.x - 1; wood3.c.y = wood2.c.y;
				wood3.dir = wood2.dir;
			}
			else if (i == 4)
			{
				if (wood2.c.x == N - 1) continue;
				if (map[wood2.a.y][wood2.a.x + 1] == '1' || map[wood2.b.y][wood2.b.x + 1] == '1' || map[wood2.c.y][wood2.c.x + 1] == '1') continue;
				wood3.a.x = wood2.a.x + 1; wood3.a.y = wood2.a.y;
				wood3.b.x = wood2.b.x + 1; wood3.b.y = wood2.b.y;
				wood3.c.x = wood2.c.x + 1; wood3.c.y = wood2.c.y;
				wood3.dir = wood2.dir;
			}
			else if (i == 5)
			{
				if (wood2.dir)
				{
					if (map[wood2.a.y - 1][wood2.a.x] == '1' || map[wood2.a.y + 1][wood2.a.x] == '1') continue;
					if (map[wood2.b.y - 1][wood2.b.x] == '1' || map[wood2.b.y + 1][wood2.b.x] == '1') continue;
					if (map[wood2.c.y - 1][wood2.c.x] == '1' || map[wood2.c.y + 1][wood2.c.x] == '1') continue;
					if (wood2.b.y == 0 || wood2.b.y == N - 1) continue;
					wood3.a.x = wood2.a.x + 1; wood3.a.y = wood2.a.y - 1;
					wood3.b.x = wood2.b.x; wood3.b.y = wood2.b.y;
					wood3.c.x = wood2.c.x - 1; wood3.c.y = wood2.c.y + 1;
					wood3.dir = 0;
				}
				else
				{
					if (map[wood2.a.y][wood2.a.x - 1] == '1' || map[wood2.a.y][wood2.a.x + 1] == '1') continue;
					if (map[wood2.b.y][wood2.b.x - 1] == '1' || map[wood2.b.y][wood2.b.x + 1] == '1') continue;
					if (map[wood2.c.y][wood2.c.x - 1] == '1' || map[wood2.c.y][wood2.c.x + 1] == '1') continue;
					if (wood2.b.x == 0 || wood2.b.x == N - 1) continue;
					wood3.a.x = wood2.a.x - 1; wood3.a.y = wood2.a.y + 1;
					wood3.b.x = wood2.b.x; wood3.b.y = wood2.b.y;
					wood3.c.x = wood2.c.x + 1; wood3.c.y = wood2.c.y - 1;
					wood3.dir = 1;
				}
			}
			if (visit[wood3.dir][wood3.b.y][wood3.b.x]) continue;
			q.push(wood3);
			visit[wood3.dir][wood3.b.y][wood3.b.x] = visit[wood2.dir][wood2.b.y][wood2.b.x] + 1;
		}
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c;
			cin >> c;
			map[i][j] = c;
			if (!cnt&&c == 'B') { wood1.a.x = j; wood1.a.y = i; cnt++; }
			else if (cnt == 1 && c == 'B') { wood1.b.x = j; wood1.b.y = i; cnt++; }
			else if (cnt == 2 && c == 'B')
			{
				wood1.c.x = j; wood1.c.y = i;
				if (wood1.a.x == wood1.b.x && wood1.b.x == wood1.c.x) wood1.dir = 0;
				else wood1.dir = 1;
				q.push(wood1);
			}
		}
	}

	bfs();

	if (sw) cout << visit[wood2.dir][wood2.b.y][wood2.b.x] - 1 << endl;
	else cout << 0 << endl;
	return 0;
}