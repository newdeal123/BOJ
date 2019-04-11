#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_N = 10 + 5;
int N;
int arr[MAX_N];
int cache[MAX_N][5][81001]; 
//why 81001? max answer is(pow(5,7)+5*3=78140)

int f(int idx, int groupN, int tmp)
{
	if (idx > N)
	{
		if (groupN == 4)
			return 0;
		else
			return -INF;
	}
    //pruning
	if (idx + 4 - groupN > N + 1)
		return -INF;

	int&ret = cache[idx][groupN][tmp];
	if (ret != -1)
		return ret;

	return ret = max(f(idx + 1, groupN, tmp*arr[idx]), f(idx + 1, groupN + 1, 1) + tmp * arr[idx]);
}


int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cout << f(1, 0, 1);
}