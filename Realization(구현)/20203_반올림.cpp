#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int main()
{
	string s;
	cin >> s;
	for (int i = s.size() - 1; i > 0; i--)
	{
		if (s[i] - '0' >= 5)
			s[i - 1]++;
		s[i] = '0';
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '9' + 1)
			cout << "10";
		else
			cout << s[i];
	}
}