#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
const int MAX_V = 50 + 2;
int V, E, dist[MAX_V][MAX_V];

int floyd()
{
	int minN = INF;
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 1; i <= V; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= V; j++)
				tmp = max(tmp, dist[i][j]);
		minN = min(minN, tmp);
	}
	return minN;
}

int main()
{
	for (int i = 0; i < MAX_V; i++)
		for (int j = 0; j < MAX_V; j++)
			dist[i][j] = i == j ? 0 : INF;
	cin >> V;
	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	int ans=floyd();
	vector <int> v;
	for (int i = 1; i <= V; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= V; j++)
				tmp = max(tmp, dist[i][j]);
		if (tmp == ans) v.push_back(i);
	}
	sort(v.begin(), v.end());

	cout << ans << " " << v.size() << endl;
	for (auto i : v) cout << i << " ";
}