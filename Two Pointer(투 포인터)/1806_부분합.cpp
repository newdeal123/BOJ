#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#pragma warning(disable:4996)
typedef long long ll;
using namespace std;
const int MAX_N = (int)1E5 + 1;
const int INF = (int)1E8 + 1;
ll N, S;
ll arr[MAX_N];

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int idx1 = 0, idx2 = 0;
	int minLen = INF;
	ll sum = arr[0];

	while (idx1 <= idx2 && idx2 < N)
	{
		if (sum < S)
			sum += arr[++idx2];
		else if (sum >= S)
		{
			minLen = min(minLen, (idx2 - idx1 + 1));
			sum -= arr[idx1++];
		}
	}
	if (minLen == INF)
		cout << "0";
	else
		cout << minLen;
}
