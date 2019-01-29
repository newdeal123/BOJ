//준규는 N×M 크기의 미로에 갇혀있다.미로는 1×1크기의 방으로 나누어져 있고, 각 방에는 사탕이 놓여져 있다.
//미로의 가장 왼쪽 윗 방은(1, 1)이고, 가장 오른쪽 아랫 방은(N, M)이다.
//
//준규는 현재(1, 1)에 있고, (N, M)으로 이동하려고 한다.준규가(r, c)에 있으면, (r + 1, c), (r, c + 1), (r + 1, c + 1)로 이동할 수 있고, 
//각 방을 방문할 때마다 방에 놓여져있는 사탕을 모두 가져갈 수 있다.또, 미로 밖으로 나갈 수는 없다.
//
//준규가(N, M)으로 이동할 때, 가져올 수 있는 사탕 개수의 최댓값을 구하시오.
//
//입력
//첫째 줄에 미로의 크기 N, M이 주어진다. (1 ≤ N, M ≤ 1, 000)
//
//둘째 줄부터 N개 줄에는 총 M개의 숫자가 주어지며, r번째 줄의 c번째 수는(r, c)에 놓여져 있는 사탕의 개수이다.사탕의 개수는 0보다 크거나 같고, 100보다 작거나 같다.
//
//출력
//첫째 줄에 준규가(N, M)으로 이동할 때, 가져올 수 있는 사탕 개수를 출력한다.

#include <iostream>

using namespace std;

#define MAX_N 1005

int N, M;
int map[MAX_N][MAX_N] , cache[MAX_N][MAX_N];

int goY[4] = { 0,1,0,1 };
int goX[4] = { 0,0,1,1 };

int max(int a, int b, int c)
{
	int ret;
	ret = a > b ? a : b;
	ret = ret > c ? ret : c;
	return ret;
}

int maze(int y, int x)
{
	//기저사례1 : 미로밖일경우
	if (y <1 || y > N || x<1 || x> M)
		return 0;
	//기저사례2 : 목적지에 도착했을 경우
	if (y == N && x == M)
		return 0;

	int& ret = cache[y][x];

	if (ret != -1)
		return ret;

	return ret = max
	(   maze(y + goY[1], x + goX[1]) + map[y + goY[1]][x + goX[1]],
		maze(y + goY[2], x + goX[2]) + map[y + goY[2]][x + goX[2]],
		maze(y + goY[3], x + goX[3]) + map[y + goY[3]][x + goX[3]]);
}

int main()
{
	//캐시 초기화
	for (int i = 0; i <= MAX_N; i++)
		for (int j = 0; j <= MAX_N; j++)
			cache[i][j] = -1;


	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	cout << maze(1, 1) + map[1][1];
}