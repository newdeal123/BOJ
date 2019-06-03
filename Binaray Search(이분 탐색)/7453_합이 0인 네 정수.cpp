#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, arr[4000 + 2][4], sum = 0;
	cin >> n;
	vector <ll> v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v.push_back(arr[i][2] + arr[j][3]);
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			ll tmp = arr[i][0] + arr[j][1];
			ll leftIdx = lower_bound(v.begin(), v.end(), -tmp) - v.begin();
			ll rightIdx = upper_bound(v.begin(), v.end(), -tmp) - v.begin();

			if (leftIdx == v.size()) continue;
			if (v[leftIdx]+tmp==0)
				sum += rightIdx - leftIdx;
		}

	cout << sum;
}