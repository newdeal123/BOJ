//준민이가 현재 가지고 있는 빈 병의 수와 길에서 발견한 빈 병의 수, 
//새 병으로 바꾸는데 필요한 빈 병의 수가 주어졌을 때, 준민이가 탄산 음료를 몇 개 먹을 수 있는지 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 준민이가 가지고 있는 빈 병의 수 e, 그날 발견한 빈 병의 수 f, 
//새 병으로 바꾸는데 필요한 빈 병의 개수 c가 주어진다. (e < 1000, f < 1000, 1 < c < 2000) e, f, c는 모두 음이 아닌 정수이다.
//
//출력
////첫째 줄에 준민이가 탄산 음료를 몇 개나 먹을 수 있는지를 출력한다.

#include <iostream>

using namespace std;

int main()
{
	int blank_B = 0, full_B = 0, drinking = 0;
	int e, f, need_change;

	cin >> e >> f >> need_change;

	blank_B = e + f;

	while (true)
	{
		if (need_change <= blank_B)
		{
			blank_B -= need_change;
			++full_B;
		}
		
		while (full_B)
		{
			full_B--;
			blank_B++;
			drinking++;
		}

		if (need_change > blank_B && full_B == 0)
			break;
			
	}

	cout << drinking;
}