//누가 선발인지 기억하기 쉽게 하기 위해 성의 첫 글자가 같은 선수 5명을 선발하려고 한다.만약, 
//성의 첫 글자가 같은 선수가 5명보다 적다면, 상근이는 내일 있을 친선 경기를 기권하려고 한다.
//
//상근이는 내일 경기를 위해 뽑을 수 있는 성의 첫 글자를 모두 구해보려고 한다.
//
//입력
//첫째 줄에 선수의 수 N(1 ≤ N ≤ 150)이 주어진다.다음 N개 줄에는 각 선수의 성이 주어진다. 
//(성은 알파벳 소문자로만 이루어져 있고, 최대 30글자이다)
//
//출력
//상근이가 선수 다섯 명을 선발할 수 없는 경우에는 "PREDAJA" (따옴표 없이)를 출력한다.PREDAJA는 크로아티아어로 항복을 의미한다.
//선발할 수 있는 경우에는 가능한 성의 첫 글자를 사전순으로 공백없이 모두 출력한다.

#include <iostream>

using namespace std;

#define Player_Max 155
#define Name_Max 35
int main()
{
	int n, Check[26];
	char name[Player_Max][Name_Max];
	bool flag = true;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> name[i];
		Check[(int)name[i][0] - 97]++;
	}

	for (int i = 0; i <= 25; i++)
	{
		if (Check[i] >= 5)
		{
			cout << (char)(i + 97);
			flag = false;
		}
	}

	if (flag)
		cout << "PREDAJA";
	return 0;
}