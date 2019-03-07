//여러 섬으로 이루어진 나라가 있다.이 나라의 대통령은, 섬들을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 있었다.
//하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 생각을 하게 되었다.
//그래서 그는, 생색내는 식으로 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고, 
//그 또한 다리를 가장 짧게 하여 돈을 아끼려 하였다.
//
//이 나라는 N×N크기의 이차원 평면상에 존재한다.이 나라는 여러 섬으로 이루어져 있으며, 
//섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다.다음은 세 개의 섬으로 이루어진 나라의 지도이다.
//
//위의 그림에서 색이 있는 부분이 육지이고, 색이 없는 부분이 바다이다.이 바다에 가장 짧은 다리를 놓아 
//두 대륙을 연결하고자 한다.가장 짧은 다리란, 다리가 격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다.
//
//지도가 주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 연결하는 방법을 찾으시오.
//
//입력
//첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다.
//그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며,
//0은 바다, 1은 육지를 나타낸다.항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.
//
//출력
//첫째 줄에 가장 짧은 다리의 길이를 출력한다.
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int MAX_N = 102;
const int INF = 87654321;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = { 0, };
int islandN, N;
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

int min(int a, int b)
{
	return a > b ? b : a;
}

bool isinMap(int y, int x)
{
	if (y<1 || y>N || x<1 || x>N)
		return false;
	else
		return true;
}

bool isBeach(int y, int x)
{
	for (int i = 0; i < 4; i++)
		if (map[y + goY[i]][x + goX[i]] == 0 && isinMap(y+goY[i],x+goX[i]))
			return true;
	return false;
}

//섬마다 번호매기기(1,2...)
void makeIsland()
{
	queue <pair<int, int>> q;

	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (map[i][j] != 0 && !visited[i][j])
			{
				visited[i][j] = 1;
				q.push(make_pair(i, j));
				map[i][j] = ++islandN;
				while (!q.empty())
				{
					int nowY = q.front().first; int nowX = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						int nextY = nowY + goY[i]; int nextX = nowX + goX[i];
						if (!visited[nextY][nextX] && map[nextY][nextX] != 0 && isinMap(nextY,nextX))
						{
							map[nextY][nextX] = islandN;
							visited[nextY][nextX] = 1;
							q.push(make_pair(nextY, nextX));
						}
					}
				}
			}
}

//해변의 좌표를 queue에 넣고 다리건설
int makeBridge()
{
	int ret = INF;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (isBeach(i, j) && map[i][j] !=0)
			{
				queue <pair<int, int>> q;
				memset(visited, 0, sizeof(visited));
				q.push(make_pair(i, j));
				while (!q.empty())
				{
					int nowY = q.front().first, nowX = q.front().second;
					q.pop();
					for (int d = 0; d < 4; d++)
					{
						int nextY = nowY + goY[d]; int nextX = nowX + goX[d];
						if (map[nextY][nextX] != 0 && isinMap(nextY, nextX) && map[nextY][nextX] != map[i][j])
						{
							ret = min(ret, visited[nowY][nowX]);
						}
						else if (map[nextY][nextX] == 0 && isinMap(nextY, nextX) && !visited[nextY][nextX])
						{
							visited[nextY][nextX] = visited[nowY][nowX] + 1;
							q.push(make_pair(nextY, nextX));
						}
					}
				}
			
			}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	makeIsland();
	cout << makeBridge();

}