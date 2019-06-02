#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int INF = 987654321;
const int MAX_N = 100 + 2;
bool Bvisited[MAX_N] = { 0, }, Svisited[MAX_N] = { 0, };
int N, M, ans = 0;

struct Marble
{
	vector <int> bigger, smaller;
}marble[MAX_N];

int bigger_DFS(int n)
{
	int ret = 0;
	for (auto i : marble[n].bigger)
		if (!Bvisited[i])
		{
			Bvisited[i] = true;
			ret += bigger_DFS(i) + 1;
		}
	
	return ret;
}

int smaller_DFS(int n)
{
	int ret = 0;
	for (auto i : marble[n].smaller)
	if(!Svisited[i])
	{
		Svisited[i] = true;
		ret += smaller_DFS(i) + 1;
	}
	
	return ret;
}
int main()
{
	cin >> N >> M;
	
	while (M--)
	{
		int big, small;
		cin >> big >> small;
		marble[big].smaller.push_back(small);
		marble[small].bigger.push_back(big);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(Bvisited, 0, sizeof(Bvisited));
		memset(Svisited, 0, sizeof(Svisited));
		if (bigger_DFS(i) > N / 2)
		{
			ans++;
			continue;
		}
		if (smaller_DFS(i) > N / 2)
			ans++;
	}
	cout << ans;
}