#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
#pragma warning(disable:4996)
using namespace std;
const int INF = 987654321;
const int MAX_N = 5000 + 2;
int P, N, T;
vector <int> node[MAX_N];
int visited[MAX_N] = { 0, };

int bfs()
{
	queue <int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (auto next : node[now])
		{
			if (!visited[next])
			{
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}
	return visited[T];
}

void print_path()
{
	vector <int> ans;
	queue <int> q;
	ans.push_back(T);
	q.push(T);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= P; i++)
		{
			for (auto j : node[i])
			{
				if (j == now && visited[i] + 1 == visited[now])
				{
					ans.push_back(i);
					q.push(i);
				}
			}
		}

	}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << "\n";
}
int main()
{
	cin >> P >> N >> T;
	while (N--)
	{
		int start, fin1, fin2;
		cin >> start >> fin1 >> fin2;
		node[start].push_back(fin1);
		node[start].push_back(fin2);
	}
	cout << bfs() << "\n";
	print_path();
}
