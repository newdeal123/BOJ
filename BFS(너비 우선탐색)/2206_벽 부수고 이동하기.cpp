//N×M의 행렬로 표현되는 맵이 있다.맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
//당신은(1, 1)에서(N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다.
//최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.
//
//만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.
//
//맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 N(1 ≤ N ≤ 1, 000), M(1 ≤ M ≤ 1, 000)이 주어진다.다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과(N, M)은 항상 0이라고 가정하자.
//
//출력
//첫째 줄에 최단 거리를 출력한다.불가능할 때는 - 1을 출력한다.
#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int MAX = 1000;

int goY[4] = { 0,0,1,-1 };
int goX[4] = { -1,1,0,0 };
int N, M;
int graph[MAX][MAX];
int cache[MAX][MAX][2]; //마지막 2는 벽 뚫기 여부

int BFS(void)

{

	queue < pair<pair<int, int>, int>> q; //y, x, 벽 뚫기

	q.push(make_pair(make_pair(0, 0), 1)); //시작점, 벽 뚫기 가능

	cache[0][0][1] = 1;



	while (!q.empty())

	{

		int y = q.front().first.first;

		int x = q.front().first.second;

		int block = q.front().second;

		q.pop();



		//도착하면

		if (y == N - 1 && x == M - 1)

			return cache[y][x][block]; //시작하는 칸도 포함

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + goY[i];
			int nextX = x + goX[i];

			if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M)
			{
				//벽이 있고, 벽을 아직 안 뚫었다면
				if (graph[nextY][nextX] == 1 && block)

				{

					cache[nextY][nextX][block - 1] = cache[y][x][block] + 1;

					q.push(make_pair(make_pair(nextY, nextX), block - 1));

				}

				//벽이 없고 방문하지 않았던 곳이라면
				else if (graph[nextY][nextX] == 0 && cache[nextY][nextX][block] == 0)
				{
					cache[nextY][nextX][block] = cache[y][x][block] + 1;
					q.push(make_pair(make_pair(nextY, nextX), block));
				}
			}
		}
	}
	return -1;

}

int main(void)

{

	cin >> N >> M;



	for (int i = 0; i < N; i++)

	{

		string temp;

		cin >> temp;



		for (int j = 0; j < M; j++)

			graph[i][j] = temp[j] - '0';

	}



	cout << BFS() << endl;

	return 0;

}