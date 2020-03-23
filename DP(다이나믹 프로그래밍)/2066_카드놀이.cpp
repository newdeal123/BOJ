#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
string card[10][5];
map<vector<int>, double>cache;

bool done(vector<int>&v) {
	for (int i = 1; i < 10; i++)
		if (v[i] != 0)return false;
	return true;
}

double f(vector<int>now) {
	if (done(now))return 1.0;

	if (cache.find(now) != cache.end()) return cache[now];
	double&ret = cache[now];
	ret = 0.0;
	vector<pair<int, int>> canSelect;
	for (int i = 1; i < 10; i++)
		for (int j = i + 1; j < 10; j++)
			if (now[i] != 0 && now[j] != 0 && card[i][now[i]][0] == card[j][now[j]][0]) {
				canSelect.push_back({ i,j });
			}
	if (canSelect.empty()) return ret = 0.0;
	for (auto i : canSelect) {
		int idx1 = i.first, idx2 = i.second;
		vector<int>next = now;
		next[idx1]--, next[idx2]--;
		ret += f(next)*(1.0 / (double)canSelect.size());
	}
	return ret;
}


int main()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 4; j++)cin >> card[i][j];
	vector<int>start(10, 4);
	cout << f(start);
}