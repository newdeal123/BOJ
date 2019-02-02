//NASA에서는 화성 탐사를 위해 화성에 무선 조종 로봇을 보냈다.실제 화성의 모습은 굉장히 복잡하지만, 
//로봇의 메모리가 얼마 안 되기 때문에 지형을 N×M 배열로 단순화 하여 생각하기로 한다.
//
//지형의 고저차의 특성상, 로봇은 움직일 때 배열에서 왼쪽, 오른쪽, 아래쪽으로 이동할 수 있지만, 위쪽으로는 이동할 수 없다.
//또한 한 번 탐사한 지역(배열에서 하나의 칸)은 탐사하지 않기로 한다.
//
//각각의 지역은 탐사 가치가 있는데, 로봇을 배열의 왼쪽 위(1, 1)에서 출발시켜 오른쪽 아래(N, M)으로 보내려고 한다.
//이때, 위의 조건을 만족하면서, 탐사한 지역들의 가치의 합이 최대가 되도록 하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 N, M(1≤N, M≤1, 000)이 주어진다.다음 N개의 줄에는 M개의 수로 배열이 주어진다.배열의 각 수는 절댓값이 100을 넘지 않는 정수이다.이 값은 그 지역의 가치를 나타낸다.
//
//출력
//첫째 줄에 최대 가치의 합을 출력한다.
#include <iostream>
#include <string.h>
using namespace std;

#define MAX_N 1005
#define MININF -7654321 //캐시의 기본값(-1이 들어갈수있으므로) 및 최하점
int map[MAX_N][MAX_N];
int cache[MAX_N][MAX_N][3];
int N, M;
int goY[3] = { 0,0,1 };
int goX[3] = { 1,-1,0 };

int maze(int y, int x, int pastgo)
{
	//기저사례1 : 도착점에 도착했을때
	if (y == N && x == M)
		return map[y][x];
	//기저사례2 : 맵밖으로 나갔을때
	if (y < 1 || y>N || x<1 || x>M)
		return MININF;

	int& ret = cache[y][x][pastgo];
	if (ret != MININF)
		return ret;

	for (int i = 0; i < 3; i++)
	{
		if (pastgo == 0 && i == 1)//왼쪽으로 이동해왔다면 이번엔 오른쪽으로 가지못한다.
			continue;
		if (pastgo == 1 && i == 0)//오른쪽으로 이동해왔다면 이번엔 왼쪽으로 가지못한다.
			continue;
		ret = ret > maze(y + goY[i], x + goX[i],i) + map[y][x] ? ret : maze(y + goY[i], x + goX[i],i) + map[y][x];
	}

	return ret;
}

int main()
{
	for (int i = 1; i < MAX_N; i++)
		for (int j = 1; j < MAX_N; j++)
			for (int k = 0; k < 3; k++)
				cache[i][j][k] = MININF;

		cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	cout << maze(1, 1, 2);
	//cout << "\n";
	//for (int i = 1; i < N; i++)
	//{
	//	for (int j = 1; j < M; j++)
	//		cout << cache[i][j];
	//	cout << endl;
	//}
}
