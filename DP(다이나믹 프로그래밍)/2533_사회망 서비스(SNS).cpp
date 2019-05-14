#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#pragma warning(disable:4996)
typedef long long ll;
using namespace std;
const int INF = 987654321;
const int MAX_N = (int)1E6 + 1;
int cache[MAX_N][2]; //sqrt(100000)=317
int visited[MAX_N] = { 0, };
int N;
vector <int> node[MAX_N];

int f(int n, bool lastKing)
{
	int&ret = cache[n][lastKing];
	if (ret != -1)
		return ret;

	ret = INF;
	int tmp = 1;
	for (auto next : node[n])
		if (!visited[next])
		{
			visited[next] = true;
			tmp += f(next, 1);
			visited[next] = false;
		}
	ret = min(ret, tmp);
	if(lastKing)
	{
		tmp = 0;
		for (auto next : node[n])
			if (!visited[next])
			{
				visited[next] = true;
				tmp += f(next, 0);
				visited[next] = false;
			}
		ret = min(ret, tmp);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	visited[1] = true;
	cout << f(1, 1);
}