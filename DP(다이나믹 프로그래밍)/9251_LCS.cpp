//LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
//
//예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
//
//입력
//첫째 줄과 둘째 줄에 두 문자열이 주어진다.문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
//
//출력
//첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

vector <char> c1, c2;

int cache[1002][1002];

int LCS(int c1_idx, int c2_idx)
{
	if (c1_idx == c1.size() || c2_idx == c2.size())
		return 0;

	int& ret = cache[c1_idx][c2_idx];
	if (ret != -1)
		return ret;

	if (c1[c1_idx] == c2[c2_idx])
		ret = max(ret, LCS(c1_idx + 1, c2_idx + 1) + 1);
	else
		ret = max(LCS(c1_idx + 1, c2_idx), LCS(c1_idx, c2_idx + 1));


	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));

	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < (signed)s1.size(); i++)
	{
		c1.push_back(s1[i]);
	}
	for (int i = 0; i < (signed)s2.size(); i++)
	{
		c2.push_back(s2[i]);
	}

	cout << LCS(0, 0);
}
