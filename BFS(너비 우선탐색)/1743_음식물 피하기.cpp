//코레스코 콘도미니엄 8층은 학생들이 3끼의 식사를 해결하는 공간이다.
//그러나 몇몇 비양심적인 학생들의 만행으로 음식물이 통로 중간 중간에 떨어져 있다.
//이러한 음식물들은 근처에 있는 것끼리 뭉치게 돼서 큰 음식물 쓰레기가 된다.
//
//이 문제를 출제한 선생님은 개인적으로 이러한 음식물을 실내화에 묻히는 것을 정말 진정으로 싫어한다.
//참고로 우리가 구해야 할 답은 이 문제를 낸 조교를 맞추는 것이 아니다.
//
//통로에 떨어진 음식물을 피해가기란 쉬운 일이 아니다.따라서 선생님은 떨어진 음식물 중에 제일 큰 음식물만은 피해 가려고 한다.
//
//선생님을 도와 제일 큰 음식물의 크기를 구해서 “10ra"를 외치지 않게 도와주자.
//
//입력
//첫째 줄에 통로의 세로 길이 N(1 ≤ N ≤ 100)과 가로 길이 M(1 ≤ M ≤ 100) 
//그리고 음식물 쓰레기의 개수 K(1 ≤ K ≤ 10, 000)이 주어진다.그리고 다음 K개의 줄에 음식물이 떨어진 좌표(r, c)가 주어진다.
//
//좌표(r, c)의 r은 위에서부터, c는 왼쪽에서부터가 기준이다.
//
//출력
//첫째 줄에 음식물중 가장 큰 음식물의 크기를 출력하라.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 101;
int N, M, K;
int board[MAX_N][MAX_N] = { 0, };
int visited[MAX_N][MAX_N] = { 0, };
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

bool isinboard(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

int bfs(int y, int x)
{
	int cnt = 1;
	queue <pair<int, int>> q;
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
			if (!visited[nextY][nextX] && board[nextY][nextX] == 1 && isinboard(nextY, nextX))
			{
				visited[nextY][nextX] = 1;
				q.push(make_pair(nextY, nextX));
				cnt++;
			}
		}
	}
	return cnt;
}

int search()
{
	int maxN = 0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			if (board[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = 1;
				maxN = max(maxN, bfs(i, j));
			}
	return maxN;
}

int main()
{
	cin >> N >> M >> K;
	while (K--)
	{
		int y, x;
		cin >> y >> x;
		board[y][x] = 1;
	}
	cout << search();
}