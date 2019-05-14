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
const int MAX_N = 100000 + 1;
int cache[MAX_N][320]; //sqrt(100000)=317
int visited[MAX_N] = { 0, };
int N;
vector <int> node[MAX_N];

int f(int n, int lastColor)
{
	visited[n] = true;
	int&ret = cache[n][lastColor];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int color = 1; color <= 5; color++)
	{
		if (color == lastColor)
			continue;
		int tmp = color;
		for (auto next : node[n])
			if (!visited[next])
			{
				visited[next] = true;
				tmp += f(next, color);
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

	cout << f(1, 0);
}