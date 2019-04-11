#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_N = 2500 + 2;
int cache[MAX_N];
int N;
string S;

bool is_palindrom(string s)
{
	if (s.size() % 2 == 0)
	{
		for (int i = 0; i < s.size() / 2; i++)
		{
			int j = s.size() - i - 1;
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
	else
	{
		for (int i = 0; i < s.size() / 2 ; i++)
		{
			int j = s.size() - i - 1;
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
}

int f(int idx)
{
	if (idx == N)
		return 0;
	
	int&ret = cache[idx];
	if (ret != -1)
		return ret;
		
	ret = INF;
	for (int i = N - idx ; i  >= 1; i--)
	{
		if (is_palindrom(S.substr(idx, i)))
			ret = min(ret, f(idx + i) + 1);
			
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> S;
	N = S.size();
	cout << f(0);
}