#include <iostream>
using namespace std;

const int MAX_N = 102;
int map[MAX_N][MAX_N] = { 0, };
int N;

//가로방향으로 출발, 현재상태에서 경사로놓을수있으면 무조건놓는다
int goX(int y, int x, int L,bool nowHill)
{
	if (x == N)
		return 1;

	//다음 길에 내리막길 놓을수있는가
	bool CanHill = true;
	for (int i = 1; i <= L; i++)
		if (map[y][x] - map[y][x + i] != 1)
			CanHill = false;
	if (CanHill)
	{
		return goX(y, x + L, L, true);
	}
	//지금 길에 오르막길 놓을수있는가
	CanHill = true;
	for (int i = 0; i < L; i++)
		if (map[y][x+L] - map[y][x + i] != 1)
			CanHill = false;
	if (CanHill && !nowHill)
	{
		return goX(y, x + L, L, false);
	}
	//걸어서 지나갈수 있는가
	if (map[y][x] == map[y][x + 1])
		return goX(y, x + 1, L,false);

	return 0;

}

//세로방향으로 출발, 현재상태에서 다음길에 경사로놓을수있으면 무조건놓는다
int goY(int y, int x, int L, bool nowHill)
{
	if (y == N)
		return 1;

	//다음 길에 내리막길 놓을수있는가
	bool CanHill = true;
	for (int i = 1; i <= L; i++)
		if (map[y][x] - map[y + i][x] != 1)
			CanHill = false;
	if (CanHill)
	{
		return goY(y + L, x , L, true);
	}
	//지금 길에 오르막길 놓을수있는가
	CanHill = true;
	for (int i = 0; i < L; i++)
		if (map[y + L][x] - map[y + i][x] != 1)
			CanHill = false;
	if (CanHill && !nowHill)
	{
		return goY(y + L, x, L, false);
	}
	//걸어서 지나갈수 있는가
	if (map[y][x] == map[y + 1][x])
		return goY(y + 1, x, L ,false);

	return 0;

}


int main()
{
	int L, sum = 0;
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == 1)
				sum += goY(i, j, L, false);
			if (j == 1)
				sum += goX(i, j, L, false);
		}

	cout << sum;
}