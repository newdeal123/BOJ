#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 987654321;
pair<int,int> arr[1001];
int cnt = 0;
int cache[1001][16][16];

int f(int idx, int aTeam, int bTeam)
{
	if (aTeam == 0 && bTeam == 0)
		return 0;
	if (aTeam < 0 || bTeam < 0 || idx == cnt)
		return -INF;

	int&ret = cache[idx][aTeam][bTeam];
	if (ret != -1)
		return ret;

	 ret = max(f(idx + 1, aTeam - 1, bTeam) + arr[idx].first, f(idx + 1, aTeam, bTeam - 1) + arr[idx].second);
	 ret = max(ret, f(idx + 1, aTeam, bTeam));
	 return ret;
}


int main()
{
	memset(cache, -1, sizeof(cache));
	while (true)
	{
		int a, b;
		string s;
		getline(cin, s);
		if (s == "")
			break;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				a = stoi(s.substr(0, i));
				b = stoi(s.substr(i, s.size() - i));
				break;
			}
		}
		arr[cnt].first = a, arr[cnt].second = b;
		cnt++;
	}
	cout << f(0, 15, 15);
}