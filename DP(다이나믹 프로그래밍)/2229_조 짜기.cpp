#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 1000 + 2;
const int INF = 987654321;
int N;
int arr[MAX_N];
int cache[MAX_N][MAX_N];

int get_score(int start, int fin)
{
	int minN = INF, maxN = 0;
	for (int i = start; i <= fin; i++)
	{
		minN = min(minN, arr[i]);
		maxN = max(maxN, arr[i]);
	}
	return maxN - minN;
}

int f(int start, int fin)
{
	if (fin == N-1)
		return get_score(start, fin);

	int& ret = cache[start][fin];
	if (ret != -1)
		return ret;

	return ret = max(f(start, fin + 1), f(fin + 1, fin + 1) + get_score(start, fin));
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << f(0, 0);
}