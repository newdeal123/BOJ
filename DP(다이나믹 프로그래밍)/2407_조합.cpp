#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
string cache[101][101];

string stringPlus(string s1, string s2)
{
	ll sum = 0;
	string ret;
	while (!s1.empty() || !s2.empty() || sum)
	{
		if (!s1.empty())
		{
			sum += s1.back() - '0';
			s1.pop_back();
		}
		if (!s2.empty())
		{
			sum += s2.back() - '0';
			s2.pop_back();
		}
		ret+=to_string(sum % 10);
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string C(int n, int m)
{
	if (n == m || m == 0) return "1";
	string&ret = cache[n][m];
	if (ret != "") return ret;
	return ret = stringPlus(C(n - 1, m) , C(n - 1, m - 1));
}


int main()
{
	int  n, m;
	cin >> n >> m;
	cout << C(n, m);
}