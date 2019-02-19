//미키의 뒷마당에는 특정 수의 양이 있다.그가 푹 잠든 사이에 배고픈 늑대는 마당에 들어와 양을 공격했다.
//
//마당은 행과 열로 이루어진 직사각형 모양이다.글자 '.' (점)은 빈 필드를 의미하며, 글자 '#'는 울타리를, 'o'는 양, 'v'는 늑대를 의미한다.
//
//한 칸에서 수평, 수직만으로 이동하며 울타리를 지나지 않고 다른 칸으로 이동할 수 있다면, 두 칸은 같은 영역 안에 속해 있다고 한다.
//마당에서 "탈출"할 수 있는 칸은 어떤 영역에도 속하지 않는다고 간주한다.
//
//다행히 우리의 양은 카라테 검은 띠 보유자여서 늑대에게 싸움을 걸 수 있고 영역 안의 양의 수가 늑대의 수보다 많다면 이기게 된다.
//그렇지 않다면 늑대가 그 지역 안의 모든 양을 먹는다.
//
//맨 처음 모든 양과 늑대는 마당 안 영역에 존재한다.
//
//아침이 도달했을 때 살아남은 양과 늑대의 수를 출력하는 프로그램을 작성하라.
//
//입력
//첫 줄에는 두 정수 R과 C가 주어지며(3 ≤ R, C ≤ 250), 각 수는 마당의 행과 열의 수를 의미한다.
//
//다음 R개의 줄은 C개의 글자를 가진다.이들은 마당의 구조(울타리, 양, 늑대의 위치)를 의미한다.
//
//출력
//하나의 줄에 아침까지 살아있는 양과 늑대의 수를 의미하는 두 정수를 출력한다.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 252

char map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N] = { 0, };
int M, N, wolfsum = 0, sheepsum = 0;
char sheep = 'o', wolf = 'v', wall = '#', field = '.';
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

void bfs_go(int y, int x);

bool isinMap(int y, int x)
{
	if (y<1 || y>M || x<1 || x>N)
		return false;
	else
		return true;
}

void bfs()
{
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)
			if (map[i][j] != wall && !visit[i][j])
			{
				visit[i][j] = 1;
				bfs_go(i, j);
			}
}

void bfs_go(int y, int x)
{
	int wolfN = 0, sheepN = 0;
	queue <pair <int, int> > q;
	q.push(make_pair(y, x));

	if (map[y][x] == wolf)
		wolfN++;
	else if (map[y][x] == sheep)
		sheepN++;
	
	while (!q.empty())
	{
		int now_y = q.front().first; int now_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_y = now_y + goY[i]; int next_x = now_x + goX[i];
			if (!visit[next_y][next_x] && map[next_y][next_x] != wall && isinMap(next_y,next_x))
			{
				char this_c = map[next_y][next_x];
				if (this_c == sheep)
					sheepN++;
				else if (this_c == wolf)
					wolfN++;

				visit[next_y][next_x] = 1;
				q.push(make_pair(next_y, next_x));
			}
		}
	}

	if (wolfN >= sheepN)
		wolfsum += wolfN;
	else
		sheepsum += sheepN;

}
int main()
{
	cin >> M >> N;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	bfs();

	cout << sheepsum << " " << wolfsum;
}