#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 100 + 2;
const int MAX_K = 10000 + 2;
const int INF = 987654321;
int N, K;
int cache[MAX_N][MAX_K];
vector<int>arr;

int f(int idx, int sum)
{
	if (idx == arr.size())
	{
		if (sum == 0)
			return 0;
		else
			return INF;
	}

	int& ret = cache[idx][sum];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i*arr[idx] <= sum; i++)
		ret = min(ret, f(idx + 1, sum - i*arr[idx]) + i);

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> K;
	bool visited[100000+2]={0,};
	for (int i = 1; i <= N; i++){
        int tmp;
        cin>>tmp;
        visited[tmp]=true;
	}
	for(int i=1;i<100000+2;i++)
        if(visited[i])arr.push_back(i);
	int ans= f(0, K);
	if (ans >= INF)
		cout << "-1";
	else
		cout << ans;
}
