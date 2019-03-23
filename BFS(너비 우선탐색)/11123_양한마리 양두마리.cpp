// 입력
// 첫 번째 줄은 테스트 케이스의 수를 나타나는 T를 입력받는다.

// 이후 각 테스트 케이스의 첫 번째 줄에서는 H,W 를 입력받는다. H는 그리드의 높이이고, W는 그리드의 너비이다. 이후 그리드의 높이 H 에 걸쳐서 W개의 문자로 이루어진 문자열 하나를 입력받는다. 

// 0 < T ≤ 100
// 0 < H, W ≤ 100
// 출력
// 각 테스트 케이스마다, 양의 몇 개의 무리로 이루어져 있었는지를 한 줄에 출력하면 된다. 
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int H, W;
char board[101][101];
int visited[101][101];
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

bool isinboard(int y, int x)
{
	if (y<1 || y>H || x<1 || x>W)
		return false;
	return true;
}

void bfs(int y, int x)
{
	queue <pair<int,int>> q;
	visited[y][x] = 1;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i];
			int nextX = nowX + goX[i];
			if (isinboard(nextY, nextX) && !visited[nextY][nextX] && board[nextY][nextX] == '#')
			{
				visited[nextY][nextX] = 1;
				q.push(make_pair(nextY, nextX));
			}
		}
	}
	
}

int search()
{
	int cnt = 0;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			if (!visited[i][j] && board[i][j] == '#')
			{
				visited[i][j] = 1;
				bfs(i, j);
				cnt++;
			}
	
	return cnt;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(visited, 0, sizeof(visited));
		cin >> H >> W;
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				cin >> board[i][j];
		cout << search() << "\n";
	}
}