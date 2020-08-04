#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
int P, K;
int cache[1001];

int f(int idx, vector<int>&v) {
	if (idx == -1)return 0;

	int&ret = cache[idx];
	if (ret != -1)return ret;

	bool visited[102] = { 0, };

	for (int i = 0; i <= K; i++) {
		if (idx - i < 0)break;
		int toRemove = v[idx - i];
		if (idx - i - toRemove >= -1)
			visited[f(idx - i - toRemove, v)] = true;
	}

	for (int i = 0; i < 102; i++)
		if (!visited[i])return ret = i;
	//error
	return -1;
}


int main()
{
	cin >> P >> K;
	int k = 0;
	while (P--) {
		int N;
		cin >> N;
		vector<int>v(N);
		for (auto&i : v)cin >> i;

		memset(cache, -1, sizeof(cache));
		k ^= f(N - 1, v);
	}
	cout << (k ? "Alice can win." : "Bob will win.") << "\n";
}