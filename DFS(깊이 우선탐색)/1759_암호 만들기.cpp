#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int L, C;
vector <char> v, ans;

bool is_possible()
{
	char arr[5] = { 'a','e','i','o','u' };
	int arrN = 0;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < 5; j++)
			if (ans[i] == arr[j])
				arrN++;
	}
	if (arrN >= 1 && arrN <= L - 2)
		return true;
	else
		return false;
}

void dfs(int n, int last_idx)
{
	if (n == L)
	{
		if (!is_possible())
			return;
		for (auto i : ans)
			cout << i;
		cout << "\n";
		return;
	}

	for (int i = last_idx + 1; i < C; i++)
	{
		ans[n] = v[i];
		dfs(n + 1, i);
	}
}

int main()
{
	cin >> L >> C;
	ans.resize(L);
	v.resize(C);
	for (int i = 0; i < C; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	dfs(0, -1);
}