#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N = 20 + 2;
int sharkY, sharkX, shark_size = 2, shark_exp = 0;
int board[MAX_N][MAX_N];
int N;
int goY[4] = { 1,-1,0,0 };
int goX[4] = { 0,0,1,-1 };
vector <pair<int,int>> fish[7];

struct Hunt
{
	int dist, y, x;
};

bool compare(Hunt&a, Hunt&b)
{
	if (a.dist != b.dist)
		return a.dist < b.dist;
	if (a.y != b.y)
		return a.y < b.y;
	return a.x < b.x;
}

int bfs(int startY, int startX, int finY, int finX)
{
	queue <pair<int, int>> q;
	int visited[MAX_N][MAX_N] = { 0, };
	visited[startY][startX] = 1;
	q.push(make_pair(startY, startX));
	while (!q.empty())
	{
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();
		if (nowY == finY && nowX == finX)
			return visited[nowY][nowX] - 1;
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + goY[i], nextX = nowX + goX[i];
			if (nextY <1 || nextY > N || nextX <1 || nextX > N)
				continue;
			if (!visited[nextY][nextX] && board[nextY][nextX] <= shark_size)
			{
				visited[nextY][nextX] = visited[nowY][nowX] + 1;
				q.push(make_pair(nextY, nextX));
			}
		}
		
	}
	return -1;
}

void search(vector <Hunt>& can_eat)
{
	for (int i = 1; i < shark_size; i++)
	{
		//런타임에러 발생원인. shark_size가 7을 넘겨버리면 오류가떠버린다.
		if (i > 6)
			continue;
		for (int j = 0; j < fish[i].size(); j++)
		{
			int nextY = fish[i][j].first, nextX = fish[i][j].second;
			if (board[nextY][nextX] == 0)
				continue;
			int d = bfs(sharkY, sharkX, nextY, nextX);
			if (d == -1)
				continue;
			can_eat.push_back({ d ,nextY, nextX });
		}
	}
}

int main()
{
	int sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 6)
				fish[board[i][j]].push_back(make_pair(i, j));
			else if (board[i][j] == 9)
				sharkY = i, sharkX = j, board[i][j] = 0;
		}

	while (true)
	{
		vector <Hunt> can_eat;
		search(can_eat);
		if (can_eat.empty())
			break;
		sort(can_eat.begin(), can_eat.end(), compare);
		//물고기 제거
		board[can_eat[0].y][can_eat[0].x] = 0;
		//합계
		sum += can_eat[0].dist;
		//아기상어 이동
		sharkY = can_eat[0].y, sharkX = can_eat[0].x;
		//경험치+1
		shark_exp++;
		//경험치==상어몸집 이면 상어몸집+1
		if (shark_exp == shark_size)
			shark_size++, shark_exp = 0;
	}

	cout << sum;
}