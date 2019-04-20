#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 1000 + 2;
const int INF = 987654321;
int cache[MAX_N][MAX_N];
int answer[MAX_N];
int N, W;
pair<int,int> arr[MAX_N];

int dist(int y, int x, int y2, int x2)
{
	return abs(y2 - y) + abs(x2 - x);
}

//두 경찰차가 마지막으로 해결한 사건이 idx1,idx2일때, 최단거리 반환
//사건 idx: 1~W
int f(int idx1, int idx2)
{
	if (idx1 == W || idx2 == W)
		return 0;

	int& ret = cache[idx1][idx2];
	if (ret != -1)
		return ret;
	ret = INF;

	int now_case = max(idx1, idx2) + 1;	
	//1경찰차 출동
	if (idx1 == 0)
		ret = min(ret, f(now_case, idx2) + dist(1, 1, arr[now_case].first, arr[now_case].second));
	else
		 ret = min(ret, f(now_case, idx2) + dist(arr[idx1].first, arr[idx1].second, arr[now_case].first, arr[now_case].second));
	//2경찰차 출동
	if (idx2 == 0)
		ret = min(ret, f(idx1, now_case) + dist(N, N, arr[now_case].first, arr[now_case].second));
	else
		ret = min(ret, f(idx1, now_case) + dist(arr[idx2].first, arr[idx2].second, arr[now_case].first, arr[now_case].second));
	
	return ret;
}

void output(int idx1, int idx2)
{
	if (idx1 == W || idx2 == W)
		return;

	int dist1 = INF, dist2 = INF;
	int now_case = max(idx1, idx2) + 1;

	//1경찰차 출동
	if (idx1 == 0)
		dist1 = min(dist1, cache[now_case][idx2] + dist(1, 1, arr[now_case].first, arr[now_case].second));
	else
		dist1 = min(dist1, cache[now_case][idx2] + dist(arr[idx1].first, arr[idx1].second, arr[now_case].first, arr[now_case].second));
	//2경찰차 출동
	if (idx2 == 0)
		dist2 = min(dist2, cache[idx1][now_case] + dist(N, N, arr[now_case].first, arr[now_case].second));
	else
		dist2 = min(dist2, cache[idx1][now_case] + dist(arr[idx2].first, arr[idx2].second, arr[now_case].first, arr[now_case].second));

	if (dist1 < dist2)
	{
		answer[now_case] = 1;
		output(now_case, idx2);
	}
	else
	{
		answer[now_case] = 2;
		output(idx1, now_case);
	}
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> W;
	for (int i = 1; i <= W; i++)
	{
		int y, x;
		cin >> y >> x;
		arr[i] = make_pair(y, x);
	}

	cout << f(0, 0) << "\n";
	output(0, 0);

	for (int i = 1; i <= W; i++)
		cout << answer[i] << "\n";
}