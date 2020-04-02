#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, board[21][21], goY[4] = { 0,1,0,-1 }, goX[4] = { 1,0,-1,0 };
int visited[21][21][4][21][21][4] = { 0, };
int goS[2] = { 1,-1 };

struct NODE
{
	int y, x, state;
};

void visit(NODE a, NODE b, int value)
{
	visited[a.y][a.x][a.state][b.y][b.x][b.state] = value;
}

int getVisited(NODE a, NODE b)
{
	return visited[a.y][a.x][a.state][b.y][b.x][b.state];
}

void is_in_board(NODE& a, NODE& b, NODE prevA, NODE prevB)
{
	if (a.y < 0 || a.y >= N || a.x < 0 || a.x >= N || board[a.y][a.x] == 1)
	{
		a = prevA;
	}
	if (b.y < 0 || b.y >= N || b.x < 0 || b.x >= N || board[b.y][b.x] == 1)
	{
		b = prevB;
	}
}

int bfs()
{
	queue<pair<NODE, NODE>>q;
	visit({ N - 1,0,0 }, { N - 1,0,3 }, 1);
	q.push({ { N - 1,0,0 },{ N - 1,0,3 } });
	while (!q.empty())
	{
		NODE nowA = q.front().first, nowB = q.front().second;
		q.pop();
        
		if (nowA.y == 0 && nowA.x == N - 1 && nowB.y == 0 && nowB.x == N - 1)
			return getVisited(nowA, nowB) - 1;

		for (int i = 0; i < 2; i++)
		{
			NODE nextA = nowA, nextB = nowB;
			nextA.state = (nextA.state + goS[i] < 0 ? 3 : nextA.state + goS[i]) % 4;
			nextB.state = (nextB.state + goS[i] < 0 ? 3 : nextB.state + goS[i]) % 4;
			if (nowA.y == 0 && nowA.x == N - 1)nextA = nowA;
			if (nowB.y == 0 && nowB.x == N - 1)nextB = nowB;
			if (!getVisited(nextA, nextB))
			{
				visit(nextA, nextB, getVisited(nowA, nowB) + 1);
				q.push({ nextA,nextB });
			}
		}
		{
			NODE nextA = nowA, nextB = nowB;
			nextA.y += goY[nextA.state], nextA.x += goX[nextA.state];
			nextB.y += goY[nextB.state], nextB.x += goX[nextB.state];
			if (nowA.y == 0 && nowA.x == N - 1)nextA = nowA;
			if (nowB.y == 0 && nowB.x == N - 1)nextB = nowB;
			is_in_board(nextA, nextB, nowA, nowB);
			if (!getVisited(nextA, nextB))
			{
				visit(nextA, nextB, getVisited(nowA, nowB) + 1);
				q.push({ nextA,nextB });
			}

		}

	}

	return -1;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)board[i][j] = (s[j] == 'E' ? 0 : 1);
	}
	cout << bfs();
}