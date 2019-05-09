#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 20 + 2;
const int INF = 987654321;
int N, all_sum = 0, ans = INF;
int arr[MAX_N][MAX_N];
int team[MAX_N];

void make_team(int last_select, int n)
{
	if (n == N / 2 )
	{
		int team2[MAX_N], cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			bool overlap = false;
			for (int j = 0; j < n; j++)
				if (team[j] == i)
					overlap = true;
			if (!overlap)
				team2[cnt++] = i;
		}
		int sum1 = 0 , sum2 = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				sum1 += arr[team[i - 1]][team[j - 1]];
				sum2 += arr[team2[i - 1]][team2[j - 1]];
			}
		ans = min(ans, abs(sum1 - sum2));
		return;
	}
	for (int i = last_select+1; i <= N; i++)
	{
		team[n] = i;
		make_team(i, n + 1);
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			all_sum += arr[i][j];
		}
	}
	make_team(0, 0);
	cout << ans;
}