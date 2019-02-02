//재환이가 1×N 크기의 미로에 갇혀있다.미로는 1×1 크기의 칸으로 이루어져 있고, 각 칸에는 숫자가 하나 쓰여 있다.
//i번째 칸에 쓰여 있는 숫자를 Ai라고 했을 때, 재환이는 Ai이하만큼 오른쪽으로 떨어진 칸으로 한 번에 점프할 수 있다.
//예를 들어, 3번째 칸에 쓰여 있는 숫자가 3이면, 재환이는 4, 5, 6번 칸 중 하나로 점프할 수 있다.
//
//재환이는 지금 미로의 가장 왼쪽 끝에 있고, 가장 오른쪽 끝으로 가려고 한다.
//이때, 최소 몇 번 점프를 해야 갈 수 있는지 구하는 프로그램을 작성하시오.만약, 가장 오른쪽 끝으로 갈 수 없는 경우에는 - 1을 출력한다.
//
//입력
//첫째 줄에 N(1 ≤ N ≤ 1, 000)이 주어진다.둘째 줄에는 Ai(0 ≤ Ai ≤ 100)가 주어진다.
//
//출력
//재환이가 최소 몇 번 점프를 해야 가장 오른쪽 끝 칸으로 갈 수 있는지 출력한다.만약, 가장 오른쪽 끝으로 갈 수 없는 경우에는 - 1을 출력한다.
#include <iostream>
#include <string.h>
using namespace std;

#define MAX_N 1005
#define INF 7654321
int N;
int map[MAX_N];
int cache[MAX_N][MAX_N];

int min(int a, int b)
{
	int ret;
	return ret = a > b ? b : a;
}

//지금좌표는x이고, 현재까지 사용한jump개수가jumpN인함수
int maze(int x, int jumpN)
{
	//기저사례1 : 끝을 넘어갔을경우
	if (x > N)
		return INF;

	//기저사례2: 미로끝에 도착했을경우
	if (x == N)
		return jumpN;

	int& ret = cache[x][jumpN];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = 1; i <= map[x]; i++)
	{
		maze(x + i, jumpN + 1);  //?
		ret = min(ret, maze(x + i, jumpN + 1));
	}

	if (ret != INF)
		return ret;
	else
		return -1;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> map[i];
	cout << maze(1, 0);
}