//배열을 정렬하는 것은 쉽다.수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
//
//입력
//첫째 줄에 정렬하고자하는 수 N이 주어진다.N은 1, 000, 000, 000보다 작거나 같은 자연수이다.
//
//출력
//첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int arr[100], size=0;
	string s;
	cin >> s;
	for (int i = 0; i < (signed)s.size(); i++)
	{
		arr[i] = s[i] - '0';
		size++;
	}

	sort(arr, arr + size);

	for (int i = size-1; i >= 0; i--)
	{
		cout << arr[i];
	}
}