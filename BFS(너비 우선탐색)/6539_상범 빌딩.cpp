//당신은 상범 빌딩에 갇히고 말았다.여기서 탈출하는 가장 빠른 길은 무엇일까 ? 
//상범 빌딩은 각 변의 길이가 1인 정육면체(단위 정육면체)로 이루어져있다.각 정육면체는 금으로 이루어져 있어 지나갈 수 없거나, 
//비어있어서 지나갈 수 있게 되어있다.당신은 각 칸에서 인접한 6개의 칸(동, 서, 남, 북, 상, 하)으로 1분의 시간을 들여 이동할 수 있다.
//즉, 대각선으로 이동하는 것은 불가능하다.그리고 상범 빌딩의 바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출할 수 있다.
//
//당신은 상범 빌딩을 탈출할 수 있을까 ? 만약 그렇다면 얼마나 걸릴까 ?
//
//입력
//입력은 여러 개의 테스트 케이스로 이루어지며, 각 테스트 케이스는 세 개의 정수 L, R, C로 시작한다.
//L(1 ≤ L ≤ 30)은 상범 빌딩의 층 수이다.R(1 ≤ R ≤ 30)과 C(1 ≤ C ≤ 30)는 상범 빌딩의 한 층의 행과 열의 개수를 나타낸다.
//
//그 다음 각 줄이 C개의 문자로 이루어진 R개의 행이 L번 주어진다.각 문자는 상범 빌딩의 한 칸을 나타낸다.
//금으로 막혀있어 지나갈 수 없는 칸은 '#'으로 표현되고, 비어있는 칸은 '.'으로 표현된다.당신의 시작 지점은 'S'로 표현되고, 
//탈출할 수 있는 출구는 'E'로 표현된다.각 층 사이에는 빈 줄이 있으며, 입력의 끝은 L, R, C가 모두 0으로 표현된다.
//
//출력
//각 빌딩에 대해 한 줄씩 답을 출력한다.만약 당신이 탈출할 수 있다면 다음과 같이 출력한다.
//
//Escaped in x minute(s).
//여기서 x는 상범 빌딩을 탈출하는 데에 필요한 최단 시간이다.
//
//만일 탈출이 불가능하다면, 다음과 같이 출력한다.
//
//Trapped!


#include <iostream>
#include <queue>
#include <string>
#include <string.h>
using namespace std;
const int MAX_N = 30 + 2;
int map[MAX_N][MAX_N][MAX_N] = { 0, };
int visited[MAX_N][MAX_N][MAX_N] = { 0, };
int L, R, C;
int goZ[6] = { 0,0,0,0,1,-1 };
int goY[6] = { 0,0,1,-1,0,0 };
int goX[6] = { 1,-1,0,0,0,0 };

struct Maze
{
	int z, y, x;
	Maze(int i, int j, int k) { z = i;  y = j; x = k; };
	Maze() {};
}M_start, M_fin;

bool is_in_map(int z, int y, int x)
{
	if (z<1 || z>L || y<1 || y>R || x<1 || x>C)
		return false;
	return true;
}

int bfs()
{
	queue <Maze> q;
	q.push(M_start);
	visited[M_start.z][M_start.y][M_start.x] = 1;
	while (!q.empty())
	{
		int nowZ = q.front().z;
		int nowY = q.front().y;
		int nowX = q.front().x;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nextZ = nowZ + goZ[i];
			int nextY = nowY + goY[i];
			int nextX = nowX + goX[i];
			if (!visited[nextZ][nextY][nextX] && is_in_map(nextZ, nextY, nextX) && map[nextZ][nextY][nextX] !=1)
			{
				visited[nextZ][nextY][nextX] = visited[nowZ][nowY][nowX] + 1;
				q.push(Maze(nextZ, nextY, nextX));
			}
		}

	}


	return visited[M_fin.z][M_fin.y][M_fin.x] ;
}

int main()
{
	while (true)
	{
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;

		for (int i = 1; i <= L; i++)
			for (int j = 1; j <= R; j++)
			{
				string s;
				cin >> s;
				for (int k = 1; k <= C; k++)
				{
					if (s[k-1] == 'S')
						M_start = Maze(i, j, k);
					else if (s[k-1] == 'E')
						M_fin = Maze(i, j, k);
					else if (s[k-1] == '#')
						map[i][j][k] = 1;
				}
			}

		
		if (bfs() != 0)
			printf_s("Escaped in %d minute(s).\n", bfs() - 1);
		else
			printf_s("Trapped!\n");
	}

	return 0;
}
