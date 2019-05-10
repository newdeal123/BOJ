#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int INF = 987654321;
const int MAX_N = 50 + 2;
string s;
vector <string> chance;
int N;
int cache[MAX_N];

int get_cost(int idx, int n)
{
	if (idx + chance[n].size() > s.size())
		return -1;
	int visited1[MAX_N] = { 0, }, visited2[MAX_N] = { 0, };
	for (int i = idx; i < idx + chance[n].size(); i++)
		visited1[s[i] - 'a']++;
	for (int i = 0; i < chance[n].size(); i++)
		visited2[chance[n][i] - 'a']++;
	for (int i = 0; i < 'z' - 'a'; i++)
		if (visited1[i] != visited2[i])
			return -1;
	int cnt = 0;
	for (int i = 0; i < chance[n].size(); i++)
	{
		if (s[idx + i] != chance[n][i])
			cnt++;
	}
	return cnt;
}

int f(int idx)
{
	if (idx == s.size())
		return 0;

	int&ret = cache[idx];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i < N; i++)
	{
		int cost = get_cost(idx, i);
		if (cost == -1)
			continue;
		ret = min(ret, f(idx + chance[i].size()) + cost);
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> s;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		chance.push_back(tmp);
	}
	int ans= f(0);
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;
}