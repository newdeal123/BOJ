#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 250 + 2, INF = 987654321;
int N, cache[MAX_N][MAX_N*MAX_N][2];
vector<pair<int, int>>v;

int f(int idx, int time,bool A)
{
	if (idx == N)return time;

	int&ret = cache[idx][time][A];
	if (ret != -1)return ret;
	ret = INF;

	if (A)
	{
		//A machine
		ret = min(ret, f(idx + 1, time + v[idx].first, true));
		//B machine
		if (time > v[idx].second) ret = min(ret, f(idx + 1, time - v[idx].second, true) + v[idx].second);
		else ret = min(ret, f(idx + 1, v[idx].second - time, false) + time);
	}
	else
	{
		//A machine
		if (time > v[idx].first)ret = min(ret, f(idx + 1, time - v[idx].first, false) + v[idx].first);
		else ret = min(ret, f(idx + 1, v[idx].first-time, true) + time);
		//B machine
		ret = min(ret, f(idx + 1, time + v[idx].second, false));
	}

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i<N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	cout << f(0, 0, 0);
}

