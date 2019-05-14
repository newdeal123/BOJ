#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#pragma warning(disable:4996)
typedef long long ll;
using namespace std;
const int INF = 987654321;
const int MAX_N = (int)1E5 + 1;
int cache[MAX_N][2];
int N, M;
int board[MAX_N];

bool is_in_board(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

int f(int y, int x, bool hadEat)
{
	if (!is_in_board(y, x))
		return 0;

	int&ret = cache[(y - 1)*M + x][hadEat];
	if (ret != -1)
		return ret;

	if (!hadEat)
	{
		//안먹고 옆으로 가기
		ret = max(ret, f(y, x + 1, 0));
		//안먹고 내려가기
		ret = max(ret, f(y + 1, 1, 0));

	}
	else
	{
		//안먹고 옆으로 가기
		ret = max(ret, f(y, x + 1, 1));
		//안먹고 내려가기
		ret = max(ret, f(y + 2, 1, 0));
	}

	//먹고 옆으로 가기
	ret = max(ret, f(y, x + 2, 1) + board[(y - 1)*M + x]);
	//먹고 내려가기
	ret = max(ret, f(y + 2, 1, 0) + board[(y - 1)*M + x]);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		memset(cache, -1, sizeof(cache));
		cin >> N >> M;
		if (!N && !M)
			break;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				cin >> board[(i - 1)*M + j];
		cout << f(1, 1, 0) << "\n";
	}
}