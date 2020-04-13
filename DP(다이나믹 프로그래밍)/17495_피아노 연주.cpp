#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N, cache[1003][1003];
vector<string>v;

inline int getDist(string s)
{
	//cout << s << ":";
	if (s.size() == 3 && s[0] == 'E'&&s[2] == '#')
	{
		char num = s[1];
		s.clear();
		s.push_back('F');
		s.push_back(num);
	}
	if (s.size() == 3 && s[0] == 'B'&&s[2] == '#')
		return  (s[1] - '0' + 1) * 12;
	
	int ret = 0;
	ret += (s[1] - '0') * 12;
	if (s.size() == 3)
	{
		if (s[0] == 'A') ret += 9;
		else if (s[0] >= 'C'&&s[0] <= 'D') ret += (s[0] - 'C') * 2 + 1;
		else ret += (s[0] - 'C' - 1) * 2 + 1;

		if (s[0] != 'C'&&s[0] != 'D')ret += 1;
	}
	else
	{
		if (s[0] == 'A' || s[0] == 'B')ret += (s[0] - 'A') * 2 + 10;
		else ret += (s[0] - 'C') * 2;

		if (s[0] != 'C'&&s[0] != 'D'&&s[0] != 'E')ret -= 1;
	}
	//cout << ret << endl;
	return ret;
}

int f(int leftIdx, int rightIdx)
{
	if (v[leftIdx] == v[rightIdx])return INF;

	int idx = max(leftIdx, rightIdx) + 1;
	if (idx == N)return 0;


	int&ret = cache[leftIdx][rightIdx];
	if (ret != -1)return ret;
	ret = INF;

	return ret = min(f(idx, rightIdx)+abs(getDist(v[idx])-getDist(v[leftIdx]))
		, f(leftIdx, idx) + abs(getDist(v[idx]) - getDist(v[rightIdx])));
}

void output(int leftIdx, int rightIdx)
{
	int idx = max(leftIdx, rightIdx) + 1;
	if (idx == N)return ;

	int left = f(idx, rightIdx) + abs(getDist(v[idx]) - getDist(v[leftIdx]));
	int right = f(leftIdx, idx) + abs(getDist(v[idx]) - getDist(v[rightIdx]));

	if (left <= right)
	{
		cout << 1 << " ";
		output(idx, rightIdx);
	}
	else
	{
		cout << 2 << " ";
		output(leftIdx, idx);
	}
}

int main()
{
	string left, right;
	cin >> left >> right;
	cin >> N;
	memset(cache, -1, sizeof(cache));
	N += 2;
	v.resize(N);
	v[0] = left, v[1] = right;
	for (int i = 2; i < N; i++)cin >> v[i];

	cout << f(0, 1)<<"\n";
	output(0, 1);
}
