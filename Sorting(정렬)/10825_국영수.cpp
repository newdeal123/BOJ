#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Student
{
	string name;
	int K, E, M;
	Student(string s, int a, int b, int c) { name = s, K = a, E = b, M = c; };
	Student() { ; };
};
bool compare(Student& s1, Student& s2)
{
	if (s1.K != s2.K)
		return s1.K > s2.K;
	else
	{
		if (s1.E != s2.E)
			return s1.E < s2.E;
		else
		{
			if (s1.M != s2.M)
				return s1.M > s2.M;
			else
			{
				return s1.name < s2.name;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector <Student> v;
	for (int i = 0; i < n; i++)
	{
		string s;
		int a, b, c;
		cin >> s >> a >> b >> c;
		v.push_back(Student(s, a, b, c));
	}
	sort(v.begin(), v.end(), compare);
	for (auto i : v)
		cout << i.name << "\n";
		
}