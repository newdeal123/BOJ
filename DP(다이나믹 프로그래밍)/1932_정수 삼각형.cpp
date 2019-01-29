//맨 위층부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 
//이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라.아래층에 있는 수는 
//현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
//
//삼각형의 크기는 1 이상 500 이하이다.삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.
//
//입력
//첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n + 1번째 줄까지 정수 삼각형이 주어진다.
//
//출력
//첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

#include <iostream>

using namespace std;

int n;		//삼각형의 크기
int triangle[501][501];
int cache[501][501];

int max(int a, int b)
{
	int ret;
	return ret = a > b ? a : b;
}


int path(int y, int x)
{
	//기저사례
	if (y == n-1)
		return  triangle[y][x] ;
	int &ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int main()
{
	cin >> n;

	//캐쉬 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cache[i][j] = -1;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];
	}

	
	cout << path(0, 0);
}