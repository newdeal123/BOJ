//크기가 R×C인 목장이 있고, 목장은 1×1 크기의 칸으로 나누어져 있다.각각의 칸에는 비어있거나, 
//양 또는 늑대가 있다.양은 이동하지 않고 위치를 지키고 있고, 늑대는 인접한 칸을 자유롭게 이동할 수 있다.
//두 칸이 인접하다는 것은 두 칸이 변을 공유하는 경우이다.
//
//목장에 울타리를 설치해 늑대가 양이 있는 칸으로 갈 수 없게 하려고 한다.늑대는 울타리가 있는 칸으로는 이동할 수 없다.울타리를 설치해보자.
//
//입력
//첫째 줄에 목장의 크기 R, C가 주어진다.
//
//둘째 줄부터 R개의 줄에 목장의 상태가 주어진다. '.'는 빈 칸, 'S'는 양, 'W'는 늑대이다.
//
//출력
//늑대가 양이 있는 칸으로 갈 수 없게 할 수 있다면 첫째 줄에 1을 출력하고, 
//둘째 줄부터 R개의 줄에 목장의 상태를 출력한다.울타리는 'D'로 출력한다.울타리를 어떻게 설치해도 늑대가 양이 있는 칸으로 갈 수 있다면 첫째 줄에 0을 출력한다.
//
//제한
//1 ≤ R, C ≤ 500
#include <iostream>
#include <string>
using namespace std;
const int MAX_N = 500 + 2;
int R, C;
int map[MAX_N][MAX_N];
enum{Blank, S, W, D};
bool flag = true;
bool isinmap(int y, int x) { if (y<1 || y>R || x<1 || x>C) return false; else return true; };
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

int main()
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= C; j++)
		{
			if (s[j - 1] == 'S')
				map[i][j] = S;
			else if (s[j - 1] == 'W')
				map[i][j] = W;
			else
				map[i][j] = 0;
		}
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (map[i][j] == W)
			{
				for (int k = 0; k < 4; k++)
				{
					int nextY = i + goY[k], nextX = j + goX[k];
					if (isinmap(nextY,nextX))
					{
						if (map[nextY][nextX] == S)
							flag = false;
						else if (map[nextY][nextX] == 0)
							map[nextY][nextX] = D;		
					}
				}

			}
		}

		
	}

	if (flag)
	{
		cout << "1" << "\n";
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				if (map[i][j] == 0)
					cout << ".";
				else if (map[i][j] == W)
					cout << "W";
				else if (map[i][j] == S)
					cout << "S";
				else if (map[i][j] == D)
					cout << "D";
			}
			cout << "\n";
		}
	}
	else
		cout << "0";
}
