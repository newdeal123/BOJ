#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N = 40 + 2;
int N, K;
ll cache[MAX_N][1 << 3][2];

ll f(int idx, int bit, bool chance)
{
	if (idx == N + 1)
		return 1;
	if (idx == K)
		return f(idx + 1, 0, chance);

	ll&ret = cache[idx][bit][chance];
	if (ret != -1)
		return ret;
	ret = 0;
	int add = 0;
	if (bit & (1 << 1))
		add = (1 << 2);

	if (chance)
		ret += f(idx + 1, add, 0);
	//idx-1번 자리를 앉을수 있으면
	if (!(bit & (1 << 2)) && idx != 1 && idx - 1 != K)
		ret += f(idx + 1, add, chance);
	//idx번 자리
	if (!(bit & (1 << 1)) && idx != K)
		ret += f(idx + 1, (1 << 2), chance);
	//idx+1번 자리
	if (!(bit & (1 << 0)) && idx != N && idx + 1 != K)
		ret += f(idx + 1, add | (1 << 1), chance);
	
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> K;
	cout << f(1, 0, 1);	
}