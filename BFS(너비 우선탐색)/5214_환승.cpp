#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX = (int)1E5 + 1;
int N, K, M;
vector<int> line[MAX + 2000];
int visited[MAX + 2000]; 

int BFS(void)
{
	queue<int> q;
	q.push(1);
	visited[1] = 1; 

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		if (here == N) 
			return visited[here];

		for (int i = 0; i < line[here].size(); i++)
		{
			int next = line[here][i];
			if (visited[next] == 0)
			{
				q.push(next);

				if (next > MAX)
					visited[next] = visited[here];
				else
					visited[next] = visited[here] + 1;
			}
		}
	}
	return -1; 

}

int main(void)
{
	cin >> N >> K >> M;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int node;
			cin >> node;
			line[MAX + i].push_back(node);
			line[node].push_back(MAX + i);
		}
	}

	cout << BFS() << endl;
	return 0;

}