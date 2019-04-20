#include <iostream>
#include <string.h>
#include <string>
const int MAX_N = 2000 + 2;
using namespace std;
int N;
int arr[MAX_N];
int cache[MAX_N][MAX_N];

int f(int start, int end)
{
	if (end < start)
		return 0;
	if (end == start)
		return 1;

	int&ret = cache[start][end];
	if (ret != -1)
		return ret;
	ret = 0;

	if (arr[start] == arr[end])
		return ret = f(start + 1, end - 1) + 2;
	else
		return ret = f(start + 1, end - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	int t;
	cin >> t;
	while (t--)
	{
		int start, end;
		cin >> start >> end;
		if (f(start, end) == end - start + 1)
			cout << "1\n";
		else
			cout << "0\n";
	}
}