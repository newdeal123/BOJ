//N×N 게임판에 수가 적혀져 있다.이 게임의 목표는 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 점프를 해서 가는 것이다.
//
//각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리를 의미한다.반드시 오른쪽이나 아래쪽으로만 이동해야 한다. 
//0은 더 이상 진행을 막는 종착점이며, 항상 현재 칸에 적혀있는 수만큼 오른쪽이나 아래로 가야 한다.한 번 점프를 할 때, 
//방향을 바꾸면 안된다.즉, 한 칸에서 오른쪽으로 점프를 하거나, 아래로 점프를 하는 두 경우만 존재한다.
//
//가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는 경로의 개수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 게임 판의 크기 N(4 ≤ N ≤ 100)이 주어진다.그 다음 N개 줄에는 각 칸에 적혀져 있는 수가 N개씩 주어진다.
//칸에 적혀있는 수는 0보다 크거나 같고, 9보다 작거나 같은 정수이며, 가장 오른쪽 아래 칸에는 항상 0이 주어진다.
//
//출력
//가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 문제의 규칙에 맞게 갈 수 있는 경로의 개수를 출력한다.

#include <iostream>
using namespace std;

#define MAX_N 111

long map[MAX_N][MAX_N];
long cache[MAX_N][MAX_N];
long N;
long goY[2] = { 0,1 };
long goX[2] = { 1,0 };

long maze(long y, long x)
{
	long sum = 0;

	//기저사례1 : 맵 밖에 벗어났을 경우
	if (y<1 || y>N || x<1 || x>N)
		return 0;

	//기저사례2 : 도착지점에 도착했을 경우
	if (y == N && x == N)
		return 1;

	//기저사례3 : 점프를 못하는 지점에 도착했을경우
	if (map[y][x] == 0)
		return 0;

	long& ret = cache[y][x];
	if (ret != -1)
		return ret;

	return ret = maze(y + (goY[0] * map[y][x]), x + (goX[0] * map[y][x])) + 
					  maze(y + (goY[1] * map[y][x]), x + (goX[1] * map[y][x]));
	
}

int main()
{
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			cache[i][j] = -1;

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	cout << maze(1,1);
}