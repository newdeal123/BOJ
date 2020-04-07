#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(7);
	int t;
	cin >> t;
	while (t--)
	{
		int h, m, s;
		cin >> h >> m >> s;
		vector<double>v;
		v.push_back((double)s / 60.0);
		v.push_back((double)m / 60.0 + (double)s / (60.0*60.0));
		v.push_back((double)h / 12.0 + (double)m / (12.0*60.0) + (double)s / (12.0*60.0*60.0));
		sort(v.begin(), v.end());
		double minN = 1.0 - v.back() + v.front();
		for (int i = 0; i < 2; i++)
			minN = min(minN, v[i + 1] - v[i]);
		cout << minN*360.0 << "\n";
	}

}