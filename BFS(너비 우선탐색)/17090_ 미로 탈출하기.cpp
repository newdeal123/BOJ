#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;
int N, M, cnt = 0;
char board[501][501];
int visited[501][501]= {0, };
set <int> ans,not_ans;

void search(int y, int x)
{
	queue <pair<int, int>> q;
	visited[y][x] = ++cnt;
	q.push(make_pair(y, x));
	while (true)
	{
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();
		int nextY, nextX;
		switch (board[nowY][nowX])
		{
		case 'U':
		{nextY = nowY - 1;
		nextX = nowX;
		break;
		}
		case 'D':
		{nextY = nowY + 1;
		nextX = nowX;
		break;
		}
		case 'R':
		{nextY = nowY;
		nextX = nowX + 1;
		break;
		}
		case 'L':
		{nextY = nowY;
		nextX = nowX - 1;
		break;
		}
		}
		if (ans.find(visited[nextY][nextX]) != ans.end())
		{
			ans.insert(cnt);
			break;
		}
		
		if (nextY<1 || nextY>N || nextX<1 || nextX>M)
		{
			ans.insert(cnt);
			break;
		}
		if (visited[nextY][nextX] == cnt)
		{
			not_ans.insert(cnt);
			break;
		}
		visited[nextY][nextX] = cnt;
		q.push(make_pair(nextY, nextX));
		
		
	}

}

int main()
{
	int sum = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++)
			board[i][j] = s[j - 1];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			if (!visited[i][j])
				search(i, j);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if(ans.find(visited[i][j])!= ans.end())
				sum++;
		}
		
	}

	cout << sum;
}