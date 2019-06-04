#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
string s;
int cache[16 + 2][1 << 10][51][2], N;
vector <pair<int, string>> book;

int f(int idx, int bit, int book_idx,  bool payment)
{
	if (idx == N)
	{
		if (bit == (1 << s.size()) - 1)
			return 0;
		return INF;
	}

	if (book_idx == book[idx].second.size())
		return f(idx + 1, bit, 0, 0);

	int&ret = cache[idx][bit][book_idx][payment];
	if (ret != -1) return ret;

	ret = INF;
	ret = min(ret, f(idx + 1, bit, 0 , 0));
	ret = min(ret, f(idx, bit, book_idx + 1, payment));
	for (int i = 0; i < s.size(); i++)
	{
		if (bit & (1 << i)) continue;
		int add = 0;
		if (!payment) add = book[idx].first;

		if (book[idx].second[book_idx] == s[i])
			ret = min(ret, f(idx, bit | (1 << i), book_idx + 1, 1) + add);
		
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> s >> N;
	for (int i = 0; i < N; i++)
	{
		int cost;
		string name;
		cin >> cost >> name;
		book.push_back(make_pair(cost, name));
	}
	int ans = f(0, 0, 0, 0);
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;
}