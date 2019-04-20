#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
const int INF = 987654321;
const int MAX_N = 300 + 2;
int N, M, K;
vector <pair<int, int>> route[MAX_N]; //도착도시,기내식 점수
int cache[MAX_N][MAX_N];

int f(int n, int m)
{
	if (n == N)
		return 0;
	if (m == 0)
		return -INF;

	int& ret = cache[n][m];
	if (ret != -1)
		return ret;

	for (auto i : route[n])
		ret = max(ret, f(i.first, m - 1) + i.second);
	
	return ret;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int maxScore[MAX_N][MAX_N];
	memset(maxScore, -1, sizeof(maxScore));
	memset(cache, -1, sizeof(cache));

	cin >> N >> M >> K;
	while (K--)
	{
		int start, fin, score;
		cin >> start >> fin >> score;
		if (start > fin)
			continue;
		maxScore[start][fin] = max(maxScore[start][fin], score);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (maxScore[i][j] != -1)
				route[i].push_back(make_pair(j, maxScore[i][j]));

	cout << f(1, M - 1);
}