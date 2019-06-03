#include <iostream>
using namespace std;
int N;
char arr[12];
int ans1[12], ans2[12];
void getMin(int idx);

bool is_overlap(int idx, int n, int tmp[])
{
	for (int i = 0; i < idx; i++)
	{
		if (tmp[i] == n)
			return true;
	}
	return false;
}

void getMax(int idx)
{
	if (idx == N+1)
	{
		for (int i = 0; i <= N; i++)
			cout << ans1[i];
		cout << "\n";
		getMin(0);
	}

	if (idx == 0)
		for (int i = 9; i >= 0; i--)
		{
			ans1[idx] = i;
			getMax(idx + 1);
			ans1[idx] = -1;
		}
	
	else
		for (int i = 9; i >= 0; i--)
		{
			if (is_overlap(idx, i, ans1))
				continue;
			if (arr[idx - 1] == '>' && ans1[idx - 1] < i)
				continue;
			if (arr[idx - 1] == '<' && ans1[idx - 1] > i)
				continue;
			ans1[idx] = i;
			getMax(idx + 1);
			ans1[idx] = -1;
		}
	return;
}

void getMin(int idx)
{
	if (idx == N + 1)
	{
		for (int i = 0; i <= N; i++)
			cout << ans2[i];
		exit(0);
	}

	if (idx == 0)
		for (int i = 0; i <= 9; i++)
		{
			ans2[idx] = i;
			getMin(idx + 1);
			ans2[idx] = -1;
		}

	else
		for (int i = 0; i <= 9; i++)
		{
			if (is_overlap(idx, i, ans2))
				continue;
			if (arr[idx - 1] == '>' && ans2[idx - 1] < i)
				continue;
			if (arr[idx - 1] == '<' && ans2[idx - 1] > i)
				continue;
			ans2[idx] = i;
			getMin(idx + 1);
			ans2[idx] = -1;
		}
	return;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	getMax(0);
}