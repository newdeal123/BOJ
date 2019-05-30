#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, sum = 0, start, fin;
	cin >> N;
	vector <pair<int, int>> v;
	while (N--)
	{
		int tmp_start, tmp_fin;
		cin >> tmp_start >> tmp_fin;
		v.push_back(make_pair(tmp_start, tmp_fin));
	}
	sort(v.begin(), v.end());
	start = v[0].first, fin = v[0].second;
	for (auto i : v)
	{
		if (i.first > fin)
		{
			sum += fin - start;
			start = i.first, fin = i.second;
		}
		else
			fin = max(fin, i.second);
		
	}
	sum += fin - start;
	cout << sum;
}