//1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.
//
//1234567891011121314151617181920212223...
//
//이렇게 만들어진 새로운 수는 몇 자리 수일까 ? 이 수의 자릿수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 N(1≤N≤100, 000, 000)이 주어진다.
//
//출력
//첫째 줄에 새로운 수의 자릿수를 출력한다.

#include <iostream>
#define N_MAX 100000000

using namespace std;


int main()
{
	int n;
	int num = 0; // 합계
	cin >> n;
	for (int i = 1; i <= n; )
	{
		int length = 0; // 자릿수

		for (int j = 1; j <= N_MAX; j *= 10)
		{
			length++;
			if (i / j < 10)
			{
				while (i < j * 10 && i<=n)
				{
					num += length;
					i++;
				}
				
				break;
			}
		}

	
	}

	cout << num;
}