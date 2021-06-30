#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
int N, M;
int cache[15][15][1 << 15];
char board[15][15];

int check(int y, int x, int bits) {
	int point = 4;
	if (y != 0) {
		if (board[y - 1][x] == '#')point-=2;
		else if (board[y - 1][x] == '?' && (bits&(1 << (M - 1))))point -= 2;
	}
	if (x != 0) {
		if (board[y][x - 1] == '#')point -= 2;
		else if (board[y][x - 1] == '?'&& (bits&(1 << 0)))point -= 2;
	}
	return point;
}

int f(int y, int x, int bits) {
	bits &= ~(1 << M);
	//cout << y << " " << x << " " << bits << endl;
	if (x == M)return f(y + 1, 0, bits);
	if (y == N)return 0;

	int&ret = cache[y][x][bits];
	if (ret != -1)return ret;
	ret = 0;
	if (board[y][x] == '.') return ret = f(y, x + 1, bits << 1);
	if (board[y][x] == '#') return ret = check(y, x, bits) + f(y, x + 1, bits << 1);
	//choose not
	ret = max(ret, f(y, x + 1, bits << 1));
	//choose
	ret = max(ret, f(y, x + 1, (bits << 1) + 1) + check(y, x, bits));

	return ret;
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N >> M;
		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < M; j++)board[i][j] = s[j];
		}
		cout << "Case #" << tc << ": " << f(0, 0, 0) << "\n";
	}
}