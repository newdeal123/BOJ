//눈금의 간격이 1인 M×N(M, N≤100)크기의 모눈종이가 있다.이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때,
//이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
//
//
//M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 
//그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다.M, N, K는 모두 100 이하의 자연수이다.
//둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 
//x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다.모눈종이의 왼쪽 아래 꼭짓점의 좌표는(0, 0)이고, 
//오른쪽 위 꼭짓점의 좌표는(N, M)이다.입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.
//
//출력
//첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다.둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_N 100
using namespace std;

queue <pair<int, int>> q;
vector <int> finded;
int map[MAX_N + 2][MAX_N] = { 0, };
int visited[MAX_N + 2][MAX_N] = { 0, };
int goY[4] = { 0,0,-1,1 };
int goX[4] = { 1,-1,0,0 };
int M, N;

bool isinmap(int y, int x)
{
	if (y < 1 || y > M || x<1 || x>N)
		return false;
	else
		return true;
}

void bfs()
{
	int cnt = 0; 


	while (!q.empty())
	{
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();
		visited[now_y][now_x] = 1;

		for (int i = 0; i < 4; i++)
		{
			int nextY = now_y + goY[i];
			int nextX = now_x + goX[i];

			if (isinmap(nextY, nextX) && !visited[nextY][nextX] && map[nextY][nextX]==0)
			{
				visited[nextY][nextX] = 1;
				q.push(make_pair(nextY, nextX));
			}
		}

		cnt++;
	}

	finded.push_back(cnt);
}

int main()
{
	int t;
	cin >> M >> N >> t;
	while (t--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1++;
		y1++;
		for (int i = y1; i <= y2; i++)
			for (int j = x1; j <= x2; j++)
				map[i][j] = 1;
	
	}
/*
	for (int i = 1; i <= M; i++)
	{
	for (int j = 1; j <= N; j++)
	cout << map[i][j];
	cout << endl;
	}
*/

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
			if (!visited[i][j] && map[i][j]==0)
			{
				q.push(make_pair(i, j));
				bfs();
			}
	}
	int size = finded.size();
	cout << size << endl;
	sort(finded.begin(), finded.end());

	for (int i = 0; i < size; i++)
		cout << finded[i] << " ";
	
}