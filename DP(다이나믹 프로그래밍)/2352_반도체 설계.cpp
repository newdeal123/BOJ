#include<iostream>
#include<algorithm>
using namespace std;
int arr[40001];
int LIS[40001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, ans = 0, size = 1, tmp;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	

	LIS[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		if (LIS[size] < arr[i])
		{
			size++;
			LIS[size] = arr[i];
			continue;
		}

		tmp = lower_bound(LIS + 1, LIS + size + 1, arr[i]) - LIS;
		LIS[tmp] = arr[i];
	}
	ans = size;
	cout << ans << "\n";
	return 0;

}