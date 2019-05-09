#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, K, max_know = 0;
bool know['z' - 'a' + 1] = { 0, };
bool existence['z' - 'a' + 1] = { 0, };
string s[51];

int how_many_know()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		bool flag = true;
		for (auto c : s[i])
			if (!know[c - 'a'])
				flag = false;
		if (flag)
			sum++;
	}
	return sum;
}

void search(int n, int last_use)
{
	if (n == K - 5)
	{
		max_know = max(max_know, how_many_know());
		return;
	}

	max_know = max(max_know, how_many_know());

	for (int i = last_use + 1 ; i < 'z' - 'a' + 1; i++)
	{
		if (!existence[i])
			continue;
		if (!know[i])
		{
			know[i] = true;
			search(n + 1, i);
			know[i] = false;
		}
	}

}

int main()
{
	know['a' - 'a'] = 1, know['n' - 'a'] = 1, know['t' - 'a'] = 1, know['i' - 'a'] = 1, know['c' - 'a'] = 1;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		s[i] = tmp.substr(4, tmp.size() - 8);
		for (int j = 0; j < tmp.size(); j++)
			existence[tmp[j] - 'a'] = true;
	}
	if (K < 5)
	{
		cout << "0";
		return 0;
	}
	search(0, -1);
	cout << max_know;
}