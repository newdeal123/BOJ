//지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N크기의 보드를 찾았다.
//어떤 정사각형은 검정색으로 칠해져있고, 나머지는 흰색으로 칠해져 있다.지민이는 이 보드를 잘라서 8 * 8크기의 체스판으로 만들려고 한다.
//
//하지만 지민이는 이 보드가 체스판처럼 검정 / 흰색 패턴이 번갈아가며 색칠해져있지 않기 때문에 고민에 빠졌다.
//따라서 지민이는 8 * 8크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야 겠다고 생각했다.당연히 8 * 8크기는 아무데서나 골라도 된다.
//
//현재 보드의 색이 어떤지 상태가 주어질 때, 지민이가 8 * 8크기로 자른 뒤에 다시 칠해야하는 정사각형 개수의 최솟값을 구하는 프로그램을 작성하시오.
//
//체스판은 각 정사각형이 검정 또는 흰색이며, 변을 공유하는 두 개의 사각형이 같은 색이 아닐 때 이다.
//따라서 위 정의에 의하면 체스판의 색은 항상 두 가지가 가능한데, 하나는 왼쪽 위 코너가 흰색인 것, 검정색인 것 두가지이다.
//
//입력
//첫째 줄에 N과 M이 주어진다.M과 N은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
//둘째 줄부터 N개 줄에는 체스판의 색 상태가 주어진다.B는 검정색이며, W는 흰색이다.
//
//출력
//첫째 줄에 지민이가 8 * 8크기로 자른 뒤에 다시 칠해야하는 정사각형 개수의 최솟값을 출력한다.
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 87654321;
const int MAX_N = 52;
char map[MAX_N][MAX_N];

int f(int y, int x, char color)
{
	int count = 0;
	char C1, C2;
	if (color == 'B')
	{
		C1 = 'B';
		C2 = 'W';
	}
	else
	{
		C1 = 'W';
		C2 = 'B';
	}

	for(int i=y;i<y+8;i++)
		for (int j = x; j < x + 8; j++)
		{
			if ((i % 2 == 1 && j % 2 == 1) || (i % 2 == 0 && j % 2 == 0))
			{
				if (map[i][j] != C1)
					count++;
			}
			else
				if (map[i][j] != C2)
					count++;
		}
	return count;
}

int main()
{
	int count = INF;
	int M, N;
	cin >> M >> N;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	for (int i = 1; i <= M-7; i++)
		for (int j = 1; j <= N - 7; j++)
		{
			count = min(count, f(i, j, 'B'));
			count = min(count, f(i, j, 'W'));
		}
	cout << count;
}