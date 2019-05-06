#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 500 + 2;
const int INF = 987654321;
string s;
int cache[MAX_N][MAX_N];

bool is_DNA(int a, int b)
{
	if (s[a] == 'a'&&s[b] == 't')
		return true;
	else if (s[a] == 'g'&&s[b] == 'c')
		return true;
	else
		return false;
}

int f(int start, int fin)
{
	if (fin - start <= 0)
		return 0;
	

	int&ret = cache[start][fin];
	if (ret != -1)
		return ret;

	ret = max(f(start + 1, fin), f(start, fin - 1));
	for (int mid = start + 1; mid <= fin ; mid++)
		if (is_DNA(start, mid))
			ret = max(ret, f(start + 1, mid - 1) + f(mid + 1, fin) + 2);
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> s;
	int ans = f(0, s.size() - 1);
	if (ans <= 0)
		cout << "0";
	else
		cout << ans;
		
}