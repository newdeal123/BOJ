#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
#include <string>
#pragma warning(disable:4996)
using namespace std;
const int INF = 987654321;
const int MAX_N = 10000 + 2;
int cache[MAX_N][150 + 2];
set <int> st;
int N, M;
int go[3] = { -1,0,1 };

int f(int now, int last_jump)
{
	if (now == N)
		return 0;

	int& ret = cache[now][last_jump];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i < 3; i++)
	{
		int jump = last_jump + go[i];
		int next = now + jump;
		if (jump <= 0 || next > N)
			continue;
		if (st.find(next) == st.end())
			ret = min(ret, f(next, jump) + 1);
	}
	return ret;
}


int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		st.insert(tmp);
	}
	int ans = f(1, 0);
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;
}