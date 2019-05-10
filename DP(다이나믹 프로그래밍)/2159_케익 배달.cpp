#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)1E10 + 2;
const int MAX_N = (int)1E5 + 2;
int N;
pair <int, int > arr[MAX_N];
ll cache[MAX_N][5];
int goY[5] = { 0,0,0,1,-1 };
int goX[5] = { 0,1,-1,0,0 };

ll get_dist(int idx1, int state1, int idx2, int state2)
{
	int y1 = arr[idx1].first + goY[state1], x1 = arr[idx1].second + goX[state1];
	int y2 = arr[idx2].first + goY[state2], x2 = arr[idx2].second + goX[state2];
	return abs(y2 - y1) + abs(x2 - x1);
}

ll f(int idx, int state)
{
	if (idx == N)
		return 0;
	ll& ret = cache[idx][state];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i < 5; i++)
		ret = min(ret, f(idx + 1, i) + get_dist(idx, state, idx + 1, i));
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		int y, x;
		cin >> y >> x;
		arr[i] = make_pair(y, x);
	}
	cout << f(0, 0);
}