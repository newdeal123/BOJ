#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;
int cache[1 << 16], N, mafia;
int r[16][16];
bool findAns = false;
int ans = 0;

void f(int dieBits, vector<int>v,int alive,int round) {
	if (alive == 1 || (dieBits&(1 << mafia))) {
		ans = max(ans, round);
		if (alive == 1)findAns = true;
		return;
	}
	if (alive % 2 == 0) {
		for (int i = 0; i < N; i++)
			if (i!=mafia && !(dieBits&(1 << i))) {
				for (int j = 0; j < N; j++)v[j] += r[i][j];
				f(dieBits | (1 << i), v, alive - 1, round + 1);
				for (int j = 0; j < N; j++)v[j] -= r[i][j];
			}
	}
	else {
		int maxN = -INF, idx;
		for (int i = 0; i < N; i++)
			if (!(dieBits&(1 << i)) && maxN < v[i]) {
				maxN = v[i];
				idx = i;
			}
		f(dieBits | (1 << idx), v, alive - 1, round);
	}
}

int main()
{
	cin >> N;
	vector<int>v(N);
	for (auto&i : v)cin >> i;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)cin >> r[i][j];
	cin >> mafia;
	f(0, v, N, 0);
	cout << ans;
}