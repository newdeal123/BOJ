//입력
//첫째 줄에 양의 정수 A가 주어진다.
//
//둘째 줄에 연산자 + 또는 *가 주어진다.
//
//셋째 줄에 양의 정수 B가 주어진다.
//
//A와 B는 모두 10의 제곱 형태이고, 길이는 최대 100자리이다.
//
//출력
//첫째 줄에 결과를 출력한다.결과는 A + B 또는 A*B이며, 입력에서 주어지는 연산자에 의해 결정된다.

#include <iostream>
#include <string>

using namespace std;

#define Max 100

int main()
{
	string A, B;
	char c;
	int str_max, str_min;

	cin >> A >> c >> B;

	str_max = A.length() > B.length() ? A.length() : B.length();
	str_min = A.length() > B.length() ? B.length() : A.length();

	if (c == '*')
	{
		cout << "1";
		for (int i = 0; i < A.length() + B.length() - 2; i++)
		{
			cout << "0";
		}
		return 0;
	}
	
	if (c == '+')
	{
		for (int i = 0; i < str_max; i++)
		{
			if (i == 0 && str_max == str_min)
				cout << "2";
			else if (i == 0)
				cout << "1";
			else if (i == str_max - str_min)
				cout << "1";
			else
				cout << "0";
		}
		return 0;
	}

}