#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int n, arr['z' - 'a' + 1] = { 0, };
string answer;

void dfs(int idx)
{
	if (idx > n)
	{
		cout << answer << "\n";
		return;
	}
	for (int i = 0; i < 'z' - 'a' + 1; i++)
	{
		if (arr[i] > 0)
		{
			arr[i]--;
			answer[idx - 1] = i + 'a';
			dfs(idx + 1);
			arr[i]++;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(arr, 0, sizeof(arr));
		string s;
		cin >> s;
		for (auto c : s)
			arr[c - 'a']++;
		n = s.size();
		answer.resize(n);
		dfs(1);
	}
}