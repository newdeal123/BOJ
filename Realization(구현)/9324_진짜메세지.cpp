//알고리즘대로 정확하게 변형된 메시지는 각 문자가 세 번 등장할 때 한 번 더 문자가 삽입된다.
//예를 들면 요원이 "HELLOTHEREWELLBEFINE" 라는 메시지를 보내고 싶어 했다면
//"HELLOTHEREEWELLLBEFINEE" 는 정확한 변형이다.
//이 작업을 자동으로 처리해주는 프로그램을 작성하라.
//
//입력
//첫째 줄에 100 이하의 테스트 케이스의 개수가 주어진다.그리고 각 테스트 케이스마다
//
//대문자로만 이루어진 10만자 이하의 문자열 M이 한 줄에 주어진다.이 문자열은 검사해야할 메시지다.
//출력
//테스트 케이스마다
//
//메시지 M이 진짜 메시지면 “OK”를, 가짜 메시지면 “FAKE”를 한 줄에 출력한다.

#include <iostream>
#include <string>
#define AIP_NUM 26
using namespace std;


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int acc[AIP_NUM] = { 0, };
		
		bool flag = true;
		string s;
		cin >> s;

		int length = s.length();
		
		for (int j = 0; j < length; j++)
		{
			acc[s[j] - 65]++;

			if (acc[s[j] - 65]  %  3 == 0 && acc[s[j] - 65] != 0)
			{
				//끝이나버리면
				if( j+1 == length)
				{
					cout << "FAKE" << endl;
					flag = false;
					break;
				}

				//암호가 안걸려져있으면
				if (s[j+1] != s[j])
				{
					flag = false;
					break;
				}
				else
					j++;		  // j+1은 암호임을 확인했으므로 건너뛴다.
					
			}

		/*	cout << "test " << j << endl;
			for (int j = 0; j < 26; j++)
			{
				char c = j + 65;
				cout << c << " " << acc[j] << endl;
			}*/
		}

		if (flag)
			cout << "OK" << endl;
	}
}