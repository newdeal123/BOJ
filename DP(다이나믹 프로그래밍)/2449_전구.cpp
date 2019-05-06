#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_N = 200;
const int MAX_K = 20;
const int INF = 987654321;
int N, K;
vector <int> arr;
int cache[MAX_N + 2][MAX_N + 2];

int f(int start, int fin)
{
	if (fin - start == 0)
		return 0;
		
	int&ret = cache[start][fin];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int mid = start; mid < fin; mid++)
	{
		int add = arr[start] != arr[mid + 1] ? 1 : 0;
		ret = min(ret, f(start, mid) + f(mid + 1, fin) + add);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	stack <int> stk;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (stk.empty())
			stk.push(tmp);
		else if (stk.top() == tmp)
			continue;
		else
			stk.push(tmp);
	}
	while (!stk.empty())
	{
		arr.push_back(stk.top());
		stk.pop();
	}

	cout << f(0, arr.size() - 1);

}