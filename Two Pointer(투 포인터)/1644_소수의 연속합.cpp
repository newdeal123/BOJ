#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#pragma warning(disable:4996)
typedef long long ll;
using namespace std;
const int MAX_N = (int)4E6;
ll N;
vector <ll> arr;
bool is_Prime[MAX_N + 1];

void getPrime()
{
	for (int i = 2; i <= N; i++)
	{
		if (is_Prime[i])
			for (int j = i + i; j <= N; j += i)
				is_Prime[j] = false;
	}
}


int main()
{
	memset(is_Prime, 1, sizeof(is_Prime));
	cin >> N;
	if (N == 1)
	{
		cout << "0";
		return 0;
	}
	getPrime();
	for (ll i = 2; i <= N; i++)
	{
		if (is_Prime[i])
			arr.push_back(i);
	}
	int idx1 = 0, idx2 = 0, cnt = 0;
	ll sum = arr[0];
	while (true)
	{
		if (idx1 == idx2 && idx1 == arr.size() - 1)
		{
			if (sum == N)
				cnt++;
			break;
		}

		if (sum == N)
			cnt++;

		if (idx1 == idx2)
		{
			sum += arr[idx2 + 1];
			idx2++;
		}
		else if (idx2 + 1 < arr.size() && sum + arr[idx2 + 1] <= N)
		{
			sum += arr[idx2 + 1];
			idx2++;
		}
		else
		{
			sum -= arr[idx1];
			idx1++;
		}
	}
	cout << cnt;
}
