//n×m의 0, 1로 된 배열이 있다.이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.
//
//0	1	0	0
//0	1	1	1
//1	1	1	0
//0	0	1	0
//위와 같은 예제에서는 가운데의 2×2 배열이 가장 큰 정사각형이다.
//
//입력
//첫째 줄에 n, m(1 ≤ n, m ≤ 1, 000)이 주어진다.다음 n개의 줄에는 m개의 숫자로 배열이 주어진다.
//
//출력
//첫째 줄에 가장 큰 정사각형의 넓이를 출력한다.

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_N 1005
int map[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];
int goY[3] = { 1,1,0 };
int goX[3] = { 0,1,1 };
int N, M;

//지금 좌표를 기준으로 검사한다
int isSquare(int y, int x, int size)
{
	//cout << "test : isSquare(" << y << "," << x << "," << size << ")\n";
	bool flag = true;
	//기저사례1 :  맵 안에있는지 검사
	if (y<1 || y>N || x<1 || x>M)
		return 0;

	//기저사례2 : 정사각형 검사후 0이있는지 검사
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (map[y + i][x + j] != 1)
			{
				flag = false;
				break;
			}
	

	int& ret = cache[y][x];

	if (ret != -1)
		return ret;

	if (flag==true)
		return ret= isSquare(y, x, size + 1) + 1;
	else
		return ret =0;
}

int main()
{
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			cache[i][j] = -1;
	int str[MAX_N];
	int count = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = s[j - 1] - 48;
		//	cout << "test : map" << map[i][j] << " ";
		}
		//cout << endl;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			str[count] = isSquare(i, j, 1);
			count++;
		}

	sort(str, str + count);

	cout << str[count - 1] * str[count - 1];
}