//여행을 떠난 세준이는 지도를 하나 구하였다.이 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다.
//한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.
//
//현재 제일 왼쪽 위 칸이 나타내는 지점에 있는 세준이는 제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 한다.
//그런데 가능한 힘을 적게 들이고 싶어 항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다.
//
//지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에는 지도의 세로의 크기 M과 가로의 크기 N이 빈칸을 사이에 두고 주어진다.
//이어 다음 M개 줄에 걸쳐 한 줄에 N개씩 위에서부터 차례로 각 지점의 높이가 빈 칸을 사이에 두고 주어진다.
//M과 N은 각각 500이하의 자연수이고, 각 지점의 높이는 10000이하의 자연수이다.
//
//출력
//첫째 줄에 이동 가능한 경로의 수 H를 출력한다.모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다.

#include <iostream>

using namespace std;
#define MAX_N 505

int map[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];
int M, N;

int goY[4] = { -1,1,0,0 };  // 상하좌우
int goX[4] = { 0,0,-1,1 };  // 상하좌우

int maze(int y, int x)
{
	
	int sum = 0;
	//기저사례1 : 미로밖일경우
	if (y<1 || y >M || x < 1 || x >N)
		return 0;

	//기저사례2 : 도착점에 도착했을경우
	if (y == M && x == N)
		return 1;

	int& ret = cache[y][x];

	if (ret != -1)
		return ret;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + goY[i];
		int nextX = x + goX[i];

		if (map[nextY][nextX] < map[y][x])
			sum += maze(nextY,nextX);
	}

	return ret = sum;
}

int main()
{
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			cache[i][j] = -1;

	cin >> M >> N;

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <=N; j++)
			cin >> map[i][j];

	cout << maze(1, 1);
}