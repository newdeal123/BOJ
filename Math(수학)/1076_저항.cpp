//전자 제품에는 저항이 들어간다.저항은 색 3개를 이용해서 그 저항이 몇 옴인지 나타낸다.
//
//처음 색 2개는 저항의 값이고, 마지막 색은 곱해야 하는 값이다.
//
//저항의 값은 다음 표를 이용해서 구한다.
//
//색	값	곱
//black	0	1
//brown	1	10
//red	2	100
//orange	3	1000
//yellow	4	10000
//green	5	100000
//blue	6	1000000
//violet	7	10000000
//grey	8	100000000
//white	9	1000000000
//예를 들어, 저항에 색이 yellow, violet, red였다면 저항의 값은 4, 700이 된다.
//
//입력
//첫째 줄에 첫 번째 색, 둘째 줄에 두 번째 색, 셋째 줄에 세 번째 색이 주어진다.색은 모두 위의 표에 쓰여 있는 색만 주어진다.
//
//출력
//입력으로 주어진 저항의 저항값을 계산하여 첫째 줄에 출력한다.
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string color[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	string t;
	int mem[3];
	long long r = 0;

	for (int i = 0; i < 3; ++i) 
	{
		cin >> t;
		for (int j = 0; j < 10; ++j) 
			if (color[j] == t) mem[i] = j;
		
	}

	r = mem[0] * 10 + mem[1];
	for (int i = 0; i < mem[2]; ++i) r *= 10;
	cout << r << endl;

	return 0;
}