#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#pragma warning(disable:4996)
typedef long long ll;
using namespace std;
int targetS, s[500500], cnt, s1[1001], s2[1001], N, M;
ll ans;
int main()
{
	cin >> targetS >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> s1[i];
		s1[i] += s1[i - 1];
		for (int j = 0; j < i; j++)
			s[cnt++] = s1[i] - s1[j];
	}
	sort(s, s + cnt);
	cin >> M;
	for (int i = 1; i <= M; i++) 
	{
		cin >> s2[i];
		s2[i] += s2[i - 1];
		for (int j = 0; j < i; j++)
			ans += upper_bound(s, s + cnt, targetS - s2[i] + s2[j]) - lower_bound(s, s + cnt, targetS - s2[i] + s2[j]);
	}
	cout << ans;
	return 0;
}