#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 5000 + 2;
int n, cache[MAX_N][MAX_N];
char arr[MAX_N];

int f(int start, int fin)
{
	if (start >= fin)
		return 0;

	int& ret = cache[start][fin];
	if (ret != -1) 
		return ret;

	if (arr[start] == arr[fin])
		return ret = f(start + 1, fin - 1);
	else
		return ret = 1 + min(f(start, fin - 1), f(start + 1, fin));
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << f(0, n - 1);
}