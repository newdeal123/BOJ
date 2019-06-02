#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int MAX_N = 1000 + 2;
int N;
vector <int> arr[MAX_N];
int answer[MAX_N];
int visited[MAX_N][10] = { 0, };
bool doit = false;

void dfs(int days, int lastuse)
{
	if (days == N)
	{
		for (int i = 0; i < N; i++)
			cout << answer[i] << "\n";
		doit = true;
		exit(0);
	}

	for (int i = 0; i < arr[days].size(); i++)
	{   
		if (days == 0)
		{
			answer[days] = arr[days][i];
			visited[days][answer[days]] = 1;
			dfs(days + 1, answer[days]);
		}
		else if (arr[days][i] != answer[days - 1] && !visited[days][arr[days][i]])
		{
			visited[days][arr[days][i]] = 1;
			answer[days] = arr[days][i];
			dfs(days + 1, answer[days]);
		}

	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		while (n--)
		{
			int tmp;
			cin >> tmp;
			arr[i].push_back(tmp);
		}

		if (i != 0)
		{
			bool flag = false;
			for (auto j : arr[i - 1])
			{
				for (auto k : arr[i])
					if (j != k)
						flag = true;
			}
			if (!flag)
			{
				cout << "-1";
				return 0;
			}
		}
	}
	dfs(0, 0);
	if (!doit)
		cout << "-1";
}
