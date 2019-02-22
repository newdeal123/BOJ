//RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다.
//또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다.집 i의 이웃은 집 i - 1과 집 i + 1이다.
//
//각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 파랑으로 드는 비용이 주어질 때, 
//모든 집을 칠할 때 드는 비용의 최솟값을 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 집의 수 N이 주어진다.N은 1, 000보다 작거나 같다.둘째 줄부터 N개의 줄에 
//각 집을 빨강으로 칠할 때, 초록으로 칠할 때, 파랑으로 칠할 때 드는 비용이 주어진다.비용은 1, 000보다 작거나 같은 자연수이다.
//
//출력
//첫째 줄에 모든 집을 칠할 때 드는 비용의 최솟값을 출력한다.
#include <iostream>
#include <algorithm> //to use min()
#include <string.h> //to use memset()
using namespace std;
#define MAX_N 1000 + 5
#define INF 87654321
enum {
	NONE,
	RED,
	GREEN,
	BLUE
};

int N; // 문제에서 주어진 집의개수
int cost[MAX_N][5];
int cache[MAX_N][5];

int makeColor(int n, int lastcolor)
{
	//기저사례
	if (n > N)
		return 0;

	int &ret = cache[n][lastcolor];
	if (ret != -1)
		return ret;

	ret = INF;
	if (lastcolor != RED)
		ret = min(ret, makeColor(n + 1, RED) + cost[n][RED]);
	if (lastcolor != GREEN)
		ret = min(ret, makeColor(n + 1, GREEN) + cost[n][GREEN]);
	if (lastcolor != BLUE)
		ret = min(ret, makeColor(n + 1, BLUE) + cost[n][BLUE]);

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i][RED] >> cost[i][GREEN] >> cost[i][BLUE];
	}
	cout << makeColor(1, NONE);
}
