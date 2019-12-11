#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Word
{
	string name;
	double cost;
	int order;
	Word(string s, double a, int b) { name = s, cost = a, order = b; };
	Word() { ; };
};

bool compare(Word&a, Word&b)
{
	if (a.cost != b.cost)
		return a.cost > b.cost;
	else
		return a.order < b.order;
}

int main()
{
	vector <Word> v;
	string s;
	cin >> s;
	int sArr['Z' - 'A' + 1] = { 0, };
	int n;
	for (auto c : s)
		sArr[c - 'A']++;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		int to_fix = 0, cost;
		int tmpArr['Z' - 'A' + 1] = { 0, };
		cin >> tmp >> cost;
		for (auto c : tmp)
			tmpArr[c - 'A']++;
		bool flag = true;
		for (int j = 0; j < 'z' - 'a' + 1; j++)
		{
			if (sArr[j] > tmpArr[j])
				flag = false;
			else
				to_fix += tmpArr[j] - sArr[j];
		}
		if (!flag)
			continue;
		v.push_back(Word(tmp, ((double)cost / (double) to_fix), i));
	}
	sort(v.begin(), v.end(), compare);
	if (v.size() == 0)
		cout << "No Jam";
	else
		cout << v[0].name;
}