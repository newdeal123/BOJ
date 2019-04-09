#include <iostream>
#include <queue>
using namespace std;
const int MAX_N = 100000;
const int INF = 987654321;
int N, K;
int go[2] = { -1,1 };

bool isinrange(int n)
{
	if (n <0 || n>MAX_N)
		return false;
	return true;
}

pair<int, int> bfs()
{
	int min_dist = INF, cnt = 0;
	int visited[MAX_N+2] = { 0, };
	queue <int> q;
	q.push(N);
	visited[N] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (visited[now] > min_dist)
			continue;
		for (int i = 0; i < 3; i++)
		{
			int there;
			if (i == 2)
				there = now * 2;
			else
				there = now + go[i];
			if (there == K)
			{
				if (cnt == 0)
				{
					cnt++;
					min_dist = visited[now];
				}
				else if (min_dist == visited[now])
					cnt++;
				else if (min_dist > visited[now])
				{
					cnt = 1;
					min_dist = visited[now];
				}
				continue;
			}
			if (isinrange(there))
				if (!visited[there] || visited[there] >= visited[now]+1)
				{
					visited[there] = visited[now] + 1;
					q.push(there);
				}
			
		}
	}
	return make_pair(min_dist, cnt);
}

int main()
{
	cin >> N >> K;
	if (N == K)
		cout << "0\n1";
	else
	{
		pair<int, int> ans = bfs();
		cout << ans.first << "\n" << ans.second;
	}
}