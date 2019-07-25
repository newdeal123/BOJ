#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
const int MAX_V = 400 + 2;
int V, E, dist[MAX_V][MAX_V];

void floyd()
{
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
	for (int i = 0; i < MAX_V; i++)
		for (int j = 0; j < MAX_V; j++)
			dist[i][j] = INF;
	cin >> V >> E;
	while (E--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	floyd();
	int ans = INF;
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
				ans = min(ans, dist[i][j] + dist[j][i]);
	if (ans == INF)cout << "-1";
	else cout << ans;
}