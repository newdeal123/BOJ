#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1000 + 2;
const ll INF = (long long)1E9 + 5; //1,000,000*1,000 + 5  (성격*사람의 수) MAX값
int N, M;
ll cache[MAX_N][MAX_N];
int man[MAX_N], woman[MAX_N];

ll  f(int idx1, int idx2)
{
	if (N > M && idx2 == M)
		return 0;
	if (M > N && idx1 == N)
		return 0;

	ll &ret = cache[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = INF;
	if (N > M)
		for (int i = 0; i + idx1 < N; i++)
		{
			//최적화: 남자의수>여자의수 일때 i+idx1번째 남자를 고를 차례인데,
			//선택해야할 여자의수를 더했을때 남자의수를 넘겼을경우
			//즉, 여자를 전부선택하지 못할경우 빠져나온다.
			if (i + idx1 + M - idx2 > N)
				break;
			ret = min(ret, f(idx1 + i + 1, idx2 + 1) + abs(man[idx1 + i] - woman[idx2]));
		}
	else if (M > N)
		for (int i = 0; i + idx2 < M; i++)
		{
			//최적화 동일
			if (i + idx2 + N - idx1 > M)
				break;
			ret = min(ret, f(idx1 + 1, idx2 + i + 1) + abs(man[idx1] - woman[idx2 + i]));
		}
	else
		ret = min(ret, f(idx1 + 1, idx2 + 1) + abs(man[idx1] - woman[idx2]));

	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> man[i];
	for (int i = 0; i < M; i++)
		cin >> woman[i];
	sort(man, man + N);
	sort(woman, woman + M);
	cout << f(0, 0);
}