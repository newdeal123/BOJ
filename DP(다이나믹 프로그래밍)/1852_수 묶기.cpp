#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
const int INF = INT_MAX - 100000;
int N, cache[100000][3][1 << 3][1 << 3], arr[100000][3];

int min_f(int y, int x, int bits, int bits2) {

	if (x == 3) {
		if (bits == (1 << 3) - 1)return min_f(y + 1, 0, bits2, 0);
		else return INF;
	}
	if (y == N) {
		if (bits == 0 && bits2 == 0)return 0;
		else return INF;
	}
	int&ret = cache[y][x][bits][bits2];
	if (ret != -1)return ret;
	ret = INF;
	ret = min(ret, min_f(y, x + 1, bits, bits2));

	if (x != 2 && !(bits&(1 << x)) && !(bits&(1 << (x + 1)))) {
		int nextBits = (bits | (1 << x));
		nextBits |= (1 << (x + 1));
		ret = min(ret, min_f(y, x + 2, nextBits, bits2) + abs(arr[y][x] - arr[y][x + 1]));
	}
	if (y != N - 1 && !(bits&(1 << x)) && !(bits2&(1 << x))) {
		int nextBits = (bits | (1 << x));
		int nextBits2 = (bits2 | (1 << x));
		ret = min(ret, min_f(y, x + 1, nextBits, nextBits2) + abs(arr[y][x] - arr[y + 1][x]));
	}
	return ret;
}
int max_f(int y, int x, int bits, int bits2) {

	if (x == 3) {
		if (bits == (1 << 3) - 1)return max_f(y + 1, 0, bits2, 0);
		else return -INF;
	}
	if (y == N) {
		if (bits == 0 && bits2 == 0)return 0;
		else return -INF;
	}
	int&ret = cache[y][x][bits][bits2];
	if (ret != -1)return ret;
	ret = -INF;
	ret = max(ret, max_f(y, x + 1, bits, bits2));

	//cout << "now " << y << " " << x << "\n";
	if (x != 2 && !(bits&(1 << x)) && !(bits&(1 << (x + 1)))) {
		int nextBits = (bits | (1 << x));
		nextBits |= (1 << (x + 1));
		//cout << "-" << bits << " " << nextBits << "\n";
		ret = max(ret, max_f(y, x + 2, nextBits, bits2) + abs(arr[y][x] - arr[y][x + 1]));
	}
	if (y != N - 1 && !(bits&(1 << x)) && !(bits2&(1 << x))) {
		int nextBits = (bits | (1 << x));
		int nextBits2 = (bits2 | (1 << x));
		//cout << "l" << bits << " " << nextBits << " " << bits2 << " " << nextBits2 << "\n";
		ret = max(ret, max_f(y, x + 1, nextBits, nextBits2) + abs(arr[y][x] - arr[y + 1][x]));
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)cin >> arr[i][j];
	cout << max_f(0, 0, 0, 0) << "\n";
	memset(cache, -1, sizeof(cache));
	cout << min_f(0, 0, 0, 0);
}