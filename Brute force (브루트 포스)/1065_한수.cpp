//  어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
// 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
//  N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

// 입력
// 첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

// 출력
// 첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.

#include <iostream>
#include <string>

using namespace std;

bool Check(string s, int n)
{
	if (n <= 2 && n>0)
		return true;

	//차이 변수 선언
	int n_d = s[1] - s[0];
	
	for (int i = 0; i<n - 1; i++)
	{
		
		if (s[i + 1] - s[i] != n_d)
			return false;
	}

	return true;



}

int main()
{
	string n;
	cin >> n;
	int n_length = n.length();
	int n_copy = atoi(n.c_str());
	int num = 0;

	for (int i = 1; i <= n_copy; i++)
	{
		string str = to_string(i);
		int str_length = str.length();
		if (Check(str, str_length) == true)
			num++;
	}

	cout << num;



}