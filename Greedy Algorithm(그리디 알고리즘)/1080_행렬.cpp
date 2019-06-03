#include <iostream>
using namespace std;
const int MAX_N = 50 + 2;
#pragma warning(disable:4996)

int main()
{
	int N, M, cnt = 0;
	cin >> N >> M;
	int board1[MAX_N][MAX_N], board2[MAX_N][MAX_N];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &board1[i][j]);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &board2[i][j]);

	for (int i = 1; i <= N - 2; i++)
		for (int j = 1; j <= M - 2; j++)
		{
			if (board1[i][j] == board2[i][j])
				continue;
			cnt++;
			for (int y = i; y < i + 3; y++)
				for (int x = j; x < j + 3; x++)
					board1[y][x] = abs(1 - board1[y][x]);
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (board1[i][j] != board2[i][j])
			{
				cout << "-1";
				return 0;
			}
	cout << cnt;
}