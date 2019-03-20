//상근이는 기숙사 생활을 한다.상근이의 방의 크기는 L*W 이다.
//
//수업시간에 타일 채우기 경우의 수를 계산하던 상근이는 자신의 방도 1 * 1크기 타일로 채우려고 한다.
//이때, 가장자리는 빨간색으로, 나머지는 갈색으로 채우려고 한다.
//
//
//어느날 상근이네 방에 하근이가 놀러왔다.하근이는 아름다운 타일 배치에 감동받았다.
//다시 방으로 돌아온 하근이는 빨간색과 갈색 타일의 개수는 기억했지만, 방의 크기는 기억해내지 못했다.
//
//빨간색과 갈색 타일의 개수가 주어졌을 때, 상근이 방의 크기를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 빨간색 타일의 수 R과 갈색 타일의 수 B가 주어진다. (8 ≤ R ≤ 5000, 1 ≤ B ≤ 2, 000, 000)
//
//출력
//첫째 줄에 상근이네 방의 크기 L과 W을 공백으로 구분하여 출력한다.만약, 두 수가 다르다면, 
//큰 수가 L이 되고 작은 수가 W이 된다.항상 정답이 유일한 경우만 입력으로 주어진다.
#include <iostream>
using namespace std;
int R, B;

int main()
{
	int a, b;
	cin >> a >> b;

	for (int i = 3; i <= 10000; i++)
	{
		for (int j = 3; j <= 10000; j++)
		{
			R = i*j - (i - 2)*(j - 2);
			B = (i - 2)*(j - 2);
			if (R == a && B == b)
			{
				if (i > j)
					cout << i << " " << j;
				else
					cout << j << " " << i;
				return 0;
			}
		}
	}
}