#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
int N, M, Jam[300000 + 2];

bool is_possible(int len)
{
	int sum = 0;
	for (int i = 0; i < M; i++)
	{
		sum += Jam[i] / len;
		if (Jam[i] % len)
			sum++;
	}
	return sum <= N;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> Jam[i];
	
	int left = 0, right = (int)1E9 + 1, minN = INF;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (is_possible(mid))
		{
			minN = min(minN, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << minN;
}