//욱제는 학교 숙제로 크기가 8×8인 체스판에서 탈출하는 게임을 만들었다.체스판의 모든 칸은 빈 칸 또는 벽 중 하나이다.
//욱제의 캐릭터는 가장 왼쪽 아랫 칸에 있고, 이 캐릭터는 가장 오른쪽 윗 칸으로 이동해야 한다.
//
//이 게임의 특징은 벽이 움직인다는 점이다. 1초마다 모든 벽이 아래에 있는 행으로 한 칸씩 내려가고, 
//가장 아래에 있어서 아래에 행이 없다면 벽이 사라지게 된다.욱제의 캐릭터는
//1초에 인접한 한 칸 또는 대각선 방향으로 인접한 한 칸으로 이동하거나, 현재 위치에 서 있을 수 있다.이동할 때는 빈 칸으로만 이동할 수 있다.
//
//1초 동안 욱제의 캐릭터가 먼저 이동하고, 그 다음 벽이 이동한다.벽이 캐릭터가 있는 칸으로 이동하면 더 이상 캐릭터는 이동할 수 없다.
//
//욱제의 캐릭터가 가장 오른쪽 윗 칸으로 이동할 수 있는지 없는지 구해보자.
//
//입력
//8개 줄에 걸쳐서 체스판의 상태가 주어진다. '.'은 빈 칸, '#'는 벽이다.
//
//출력
//욱제의 캐릭터가 가장 오른쪽 윗 칸에 도착할 수 있으면 1, 없으면 0을 출력한다.
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int map[10][10][10] = { 0, };
int goY[9] = { 0,0,1,-1,1,-1,1,-1,0 };
int goX[9] = { 1,-1,0,0,1,-1,-1,1,0 };

bool isinmap(int y, int x)
{
	if (y < 1 || y>8 || x < 1 || x>8)
		return false;
	return true;
}

//윗줄부터 벽이 하나도없으면 탈출가능
bool CanExit(int time, int y, int x)
{
	for (int i = y - 1; i >= 1; i--)
		for (int j = 1; j <= 8; j++)
			if (map[time][i][j] == 1)
				return false;
	return true;
}

bool bfs()
{
	queue <pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(8, 1)));
	while (!q.empty())
	{
		int nowT = q.front().first;
		int nowY = q.front().second.first;
		int nowX = q.front().second.second;
		q.pop();
		if (CanExit(nowT, nowY, nowX))
			return true;
		for (int i = 0; i < 9; i++)
		{
			int nextT = nowT + 1;
			int nextY = nowY + goY[i], nextX = nowX + goX[i];
			if (isinmap(nextY, nextX) && map[nowT][nextY][nextX] == 0 && map[nextT][nextY][nextX] == 0)
				q.push(make_pair(nextT, make_pair(nextY, nextX)));
		}
	}

	return false;
}

void mapPrint(int time)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
			cout << map[time][i][j];
		cout << endl;
	}
}

int main()
{
	for (int i = 1; i <= 8; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= 8; j++)
			if (s[j - 1] == '#')
				map[0][i][j] = 1;
	}
	if (map[0][8][1] == 1)
	{
		cout << "0";
		return 0;
	}

	//시간별로 map 저장
	for (int time = 1; time <= 8; time++)
	{
		for (int i = 8; i >= 1; i--)
		{
			for (int j = 1; j <= 8; j++)
			{
				if (i == 8 && map[time - 1][i][j] == 1)
					map[time][i][j] = 0;
				else if (map[time - 1][i][j] == 1)
					map[time][i + 1][j] = 1;		
			}
		}
	}

	cout << bfs();
}