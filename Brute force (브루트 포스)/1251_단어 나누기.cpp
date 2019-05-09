#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector <string> v;
string s;

void turn_string(string s[])
{
	for (int i = 0; i < 3; i++)
	{
		string tmp;
		for (int j = s[i].size() - 1; j >= 0; j--)
			tmp.push_back(s[i][j]);
		s[i] = tmp;
	}
}

void get_string(int a, int b)
{
	string tmp[3];
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (i == a)
			tmp[0] = s.substr(0, a+1);
		if (i == b)
		{
			tmp[1] = s.substr(a + 1, b - a);
			tmp[2] = s.substr(b + 1, s.size() - b + 1);
		}
	}
	turn_string(tmp);
	v.push_back(tmp[0] + tmp[1] + tmp[2]);
}

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size()-1; j++)
				get_string(i, j);
	}
	sort(v.begin(), v.end());
	cout << v[0];
}