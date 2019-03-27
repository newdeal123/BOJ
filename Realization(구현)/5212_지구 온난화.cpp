#include <iostream>
#include <vector>
#include <string>
using namespace std;
char board[11][11];
int R, C;
vector <pair<int, int>> v;
vector <int> dontprintY;
vector <int> dontprintX;
int goY[4] = { 1,-1,0,0 };
int goX[4] = { 0,0,1,-1 };

bool isinboard(int y, int x)
{
	if (y<1 || y>R || x < 1 || x>C)
		return false;
	return true;
}

void findBeach()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (board[i][j] == '.')
				continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nextY = i + goY[k];
				int nextX = j + goX[k];
				if (!isinboard(nextY, nextX) || board[nextY][nextX] == '.')
					cnt++;
			}
			if (cnt >= 3)
				v.push_back(make_pair(i, j));
		}
	}
}

void dontprint()
{
	for (int i = 1; i <= R; i++)
	{
		bool flag = true;
		for (int j = 1; j <= C; j++)
			if (board[i][j] == 'X')
				flag = false;
		if (flag)
			dontprintY.push_back(i);
		else
			break;
	}
	for (int i = R; i >= 1; i--)
	{
		bool flag = true;
		for (int j = 1; j <= C; j++)
			if (board[i][j] == 'X')
				flag = false;
		if (flag)
			dontprintY.push_back(i);
		else
			break;
	}

	for (int i = 1; i <= C; i++)
	{
		bool flag = true;
		for (int j = 1; j <= R; j++)
			if (board[j][i] == 'X')
				flag = false;
		if (flag)
			dontprintX.push_back(i);
		else
			break;
	}
	for (int i = C; i >= 1; i--)
	{
		bool flag = true;
		for (int j = 1; j <= R; j++)
			if (board[j][i] == 'X')
				flag = false;
		if (flag)
			dontprintX.push_back(i);
		else
			break;
	}
}

bool find_dontprintY(int y)
{
	for (int i = 0; i < dontprintY.size(); i++)
		if (y == dontprintY[i])
			return true;
	return false;
}
bool find_dontprintX(int x)
{
	for (int i = 0; i < dontprintX.size(); i++)
		if (x == dontprintX[i])
			return true;
	return false;
}


int main()
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= C; j++)
			board[i][j] = s[j - 1];
	}

	findBeach();

	for (int i = 0; i < v.size(); i++)
		board[v[i].first][v[i].second] = '.';

	dontprint();

	for (int i = 1; i <= R; i++)
	{
		if (find_dontprintY(i))
			continue;
		for (int j = 1; j <= C; j++)
		{
			if (find_dontprintX(j))
				continue;
			cout << board[i][j];
		}
		cout << endl;
	}
}