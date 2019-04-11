#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 3000 + 2;
const int INF = 987654321;
int A, B, C;
string s1, s2; // s1:bigger, s2:smaller
int cache[MAX_N][MAX_N];

//써야하는 숫자가 s1_idx,s2_idx일때
int f(int s1_idx, int s2_idx)
{
	if (s1_idx == s1.size() && s2_idx == s2.size())
		return 0;
	
	int&ret = cache[s1_idx][s2_idx];
	if (ret != -INF)
		return ret;
	//두개 다 사용
	if (s1_idx < s1.size() && s2_idx < s2.size())
	{
		if (s1[s1_idx] == s2[s2_idx])
			ret = max(ret, f(s1_idx + 1, s2_idx + 1) + A);
		else
			ret = max(ret, f(s1_idx + 1, s2_idx + 1) + C);
	}
	//s1을 사용,s2는 공백
	if (s1_idx < s1.size())
		ret = max(ret, f(s1_idx + 1, s2_idx) + B);
	//s2를 사용,s1는 공백
	if (s2_idx < s2.size())
		ret = max(ret, f(s1_idx, s2_idx + 1) + B);
	return ret;
}

int main()
{
	for (int i = 0; i < 3001; i++)
		for (int j = 0; j < 3001; j++)
			cache[i][j] = -INF;
	cin >> A >> B >> C;
	getchar();
	cin >> s1 >> s2;
	cout << f(0, 0);
}