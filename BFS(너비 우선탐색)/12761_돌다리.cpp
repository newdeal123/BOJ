#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX = (int)1E5;
int A, B, N, M;
int goN[2] = { 1,-1 };

bool is_in_range(int n)
{
	if (n<0 || n>MAX)
		return false;
	return true;
}

int bfs()
{
	int visited[MAX + 2] = { 0, };
	queue <int> q;
	q.push(N);
	visited[N] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		int next;
		for (int i = 0; i < 2; i++)
		{
			next = now + goN[i];
			if (!is_in_range(next))
				continue;
			if (!visited[next])
			{
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
				next = now + A;
			else if (i == 1)
				next = now + B;
			else if (i == 2)
				next = now - A;
			else
				next = now - B;
			if (!is_in_range(next))
				continue;
			if (!visited[next])
			{
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
				next = now * A;
			else
				next = now * B;
			if (!is_in_range(next))
				continue;
			if (!visited[next])
			{
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}

	return visited[M] - 1;
}

int main()
{
	cin >> A >> B >> N >> M;
	cout << bfs();
}
