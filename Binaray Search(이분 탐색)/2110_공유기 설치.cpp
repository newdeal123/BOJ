#include  <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N, C;
vector <int> home;

bool is_possible(int n)
{
	int cnt = 1;
	int last_idx = 0;
	for(int idx=1 ;idx < N ;idx++)
		if (home[idx] - home[last_idx] >= n)
		{
			cnt++;
			last_idx = idx;
		}
	if (cnt >= C) return true;
	else return false;
}

int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		home.push_back(tmp);
	}
	sort(home.begin(), home.end());
	int left = home.front(), right = home.back();
	int ret = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (is_possible(mid))
		{
			ret = max(ret, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ret;
}