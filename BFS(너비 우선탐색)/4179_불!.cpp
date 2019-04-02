//지훈이는 미로에서 일을 한다.지훈이를 미로에서 탈출하도록 도와주자!
//
//미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.
//
//지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동한다.
//
//불은 각 지점에서 네 방향으로 확산된다.
//
//지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
//
//지훈이와 불은 벽이 있는 공간은 통과하지 못한다.
//
//입력
//입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다.단, 1 ≤ R, C ≤ 1000 이다.R은 미로 행의 개수, C는 열의 개수이다.
//
//다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
//
//각각의 문자들은 다음을 뜻한다.
//
//#: 벽
//. : 지나갈 수 있는 공간
//J : 지훈이의 미로에서의 초기위치(지나갈 수 있는 공간)
//	F : 불이난 공간
//	J는 입력에서 하나만 주어진다.
//
//	출력
//	지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는경우 IMPOSSIBLE 을 출력한다.
//
//	지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.
//
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int INF = 987654321;
int N, M;
int board[MAX_N + 1][MAX_N + 1]; //time, y , x
enum { WALL = -1, BLANK };
int startX, startY;
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };
vector <pair<int, int>> fire; //불 시발점의 좌표

bool isinboard(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

// 시간에 따른 board변화를 저장
void getboard()
{
	bool tvisited[MAX_N + 1][MAX_N + 1] = { 0, };
	queue <pair<int, int>> q;
	for (auto i : fire)
	{
		q.push(i);
		tvisited[i.first][i.second] = 1;
		board[i.first][i.second] = 1;
	}
	
	while (!q.empty())
	{
		int nowY = q.front().first, nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];
			if (isinboard(nextY, nextX)  && board[nextY][nextX] != WALL && !tvisited[nextY][nextX])
			{
				tvisited[nextY][nextX] = 1;
				board[nextY][nextX] = board[nowY][nowX] + 1;
				q.push(make_pair(nextY, nextX));
				
			}
		}
	}

}

void  bfs()
{
	int visited[MAX_N + 1][MAX_N + 1] = { 0, };
	int minDist = INF;
	queue <pair<int, int>> q;
	q.push(make_pair(startY, startX));
	visited[startY][startX] = 1;
	while (!q.empty())
	{
		int nowY = q.front().first, nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];

			if (!isinboard(nextY, nextX))
				minDist = min(minDist, visited[nowY][nowX]);

			if (board[nextY][nextX] != WALL && !visited[nextY][nextX] && board[nextY][nextX] > visited[nowY][nowX] + 1)
			{
				q.push(make_pair(nextY, nextX));
				visited[nextY][nextX] = visited[nowY][nowX] + 1;
			}
		}

	}

	if (minDist == INF)
		cout << "IMPOSSIBLE";
	else
		cout << minDist;
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++)
		{
			char c = s[j - 1];
			if (c == '#')
				board[i][j] = WALL;
			else if (c == 'J')
				startY = i, startX = j;
			else if (c == 'F')
				fire.push_back(make_pair(i, j));
			else
				board[i][j] = INF;
		}
	}
	getboard();
	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cout << board[i][j];
		cout << "\n";
	}*/
	bfs();
}