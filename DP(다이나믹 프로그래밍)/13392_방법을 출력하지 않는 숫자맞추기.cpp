#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
const int INF = 987654321;
const int MAX_N = 10000 + 2;
int N;
string s, target;
int cache[MAX_N][10];

int f(int idx, int turn)
{
	if (idx == s.size())
		return 0;

	int&ret = cache[idx][turn];
	if (ret != -1)
		return ret;
	ret = INF;
	int now = (s[idx] - '0' + turn) % 10;
	int comp = target[idx] - '0';
	//왼쪽으로 돌리고
	int to_turn;
	if (now > comp)
		to_turn =comp + 10 - now;
	else
		to_turn = comp - now;
	ret = min(ret, f(idx + 1, (turn + to_turn) % 10) + to_turn);

	//오른쪽으로 돌리고
	if (comp > now)
		to_turn = now + 10 - comp;
	else
		to_turn = now - comp;
	ret = min(ret, f(idx + 1, turn) + to_turn);

	return ret;
}


int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cin >> s >> target;
	cout << f(0, 0);
}
