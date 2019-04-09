#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 100000;
const int INF = 987654321;
int N, K;
int go[2] = { -1,1 };

bool isinrange(int n)
{
	if (n<0 || n>MAX_N)
		return false;
	return true;
}

int bfs()
{
	int visited[MAX_N + 2] = { 0, };
	queue <int> q;
	q.push(N);
	visited[N] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == K)
			break;
		for (int i = 0; i < 2; i++)
		{
			int next = now + go[i];
			if (isinrange(next))
			  if (!visited[next])
				{
					visited[next] = visited[now] + 1;
					q.push(next);
				}		
		}
		for (int i = 2; i*now <= K * 2; i *= 2)
		{
			if (now == 0)
				break;
			int next = now*i;
			if (isinrange(next))
				if (!visited[next])
				{
					visited[next] = visited[now];
					q.push(next);
				}
		}
	}

	return visited[K] - 1;
}

int main()
{
	cin >> N >> K;
	cout << bfs();
}