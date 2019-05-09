#include <iostream>
#include <algorithm>
using namespace std;
int N;
double prob[4];
bool visited[31][31] = { 0, };
int goY[4] = { 0,0,1,-1 };
int goX[4] = { 1,-1,0,0 };

double search(int n, int y, int x)
{
	if (n == N)
		return 1.0;

	double sum = 0.0;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + goY[i], nextX = x + goX[i];
		if (!visited[nextY][nextX])
		{
			visited[nextY][nextX] = 1;
			sum += search(n + 1, nextY, nextX) * prob[i];
			visited[nextY][nextX] = 0;
		}
	}
	return sum;
}

int main()
{
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		int tmp;
		cin >> tmp;
		prob[i] = (double)tmp / 100.0;
	}
	visited[15][15] = 1;
	cout << fixed;
	cout.precision(11);
	cout << search(0, 15, 15);
}