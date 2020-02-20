#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	vector<pair<int, int>>v;
	cin >> N >> M;
	while (N--)
	{
		int s, e;
		cin >> s >> e;
		if (s > e)v.push_back({ e,s });
	 }
	sort(v.begin(), v.end()); 

	ll sum = 0;
	int left = v.front().first, right = v.front().second;
	for (int i = 1; i < v.size(); i++)
	{
		int s = v[i].first, e = v[i].second;
		if (right < s)
		{
			sum += (right - left);
			left = s, right = e;
		}
		else right = max(e, right);
	}
	sum += (right - left);
	cout << sum * 2 + M;
}

