#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector <vector <int>> v;
int N, M;
int visited[32001];
stack <int> stk;

void dfs(int n)
{
	visited[n] = 1;
	for (int i = 0; i < v[n].size(); i++)
	{
		int next = v[n][i];
		if (!visited[next])
			dfs(next);
	}
	stk.push(n);
}

int main()
{
	cin >> N >> M;
	v.resize(N + 1);
	while (M--)
	{
		int parent, child;
		cin >> parent >> child;
		v[parent].push_back(child);
	}
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
			dfs(i);
	}

	while (!stk.empty())
	{
		cout << stk.top() << " " ;
		stk.pop();
	}
}