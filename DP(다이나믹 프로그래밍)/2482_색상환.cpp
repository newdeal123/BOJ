//색을 표현하는 기본 요소를 이용하여 표시할 수 있는 모든 색 중에서 대표적인 색을 고리 모양으로 연결하여 
//나타낸 것을 색상환이라고 한다.미국의 화가 먼셀(Munsell)이 교육용으로 고안한 20색상환이 널리 알려져 있다.
//
//색상환에서 인접한 두 색은 비슷하여 언뜻 보면 구별하기 어렵다.위 그림의 20색상환에서 다홍은 빨강과 인접하
//고 또 주황과도 인접하다.풀색은 연두, 녹색과 인접하다.시각적 대비 효과를 얻기 위하여 인접한 두 색을 동시에 사용하지 않기로 한다.
//
//주어진 색상환에서 시각적 대비 효과를 얻기 위하여 서로 이웃하지 않은 색들을 선택하는 경우의 수를 생각해 보자.
//먼셀의 20색상환에서 시각적 대비 효과를 얻을 수 있게 10개의 색을 선택하는 경우의 수는 2이지만, 
//시각적 대비 효과를 얻을 수 있게 11개 이상의 색을 선택할 수 없으므로 이 경우의 수는 0이다.
//
//주어진 정수 N과 K에 대하여, N개의 색으로 구성되어 있는 색상환(N색상환)에서 
//어떤 인접한 두 색도 동시에 선택하지 않으면서 서로 다른 K개의 색을 선택하는 경우의 수를 구하는 프로그램을 작성하시오.
//
//입력
//입력 파일의 첫째 줄에 색상환에 포함된 색의 개수를 나타내는 양의 정수 N(4≤N≤1, 000)이 주어지고, 
// 둘째 줄에 N색상환에서 선택할 색의 개수 K(1≤K≤N)가 주어진다.
//
//출력
//첫째 줄에 N색상환에서 어떤 인접한 두 색도 동시에 선택하지 않고 K개의 색을 고를 수 있는 경우의 수를 1, 000, 000, 003 (10억 3) 으로 나눈 나머지를 출력한다.
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 1000 + 2;
const int MOD = 1000000003;
int cache[MAX_N][2][MAX_N];
int N;
bool FinalColorUsed;

int f(int idx, bool lastUsed, int n)
{
	//cout << "f(" << idx << "," << lastUsed << "," << n << ")\n";
	//색깔을 다골랐으면 1반환
	if (n == 0)
		return 1;
	//색깔을 다못채우고 idx가 N에 도달하면 0반환
	if (idx == N)
		return 0;

	int& ret = cache[idx][lastUsed][n];
	if (ret != -1)
		return ret;

	if ((idx == 1 || idx == N - 1) && FinalColorUsed)
		return ret = f(idx + 1, lastUsed, n) % MOD;

	else
	{
		if (lastUsed)
			return ret = f(idx + 1, !lastUsed, n) % MOD;
		else
			return ret = (f(idx + 1, !lastUsed, n - 1) + f(idx + 1, lastUsed, n)) % MOD;
	}
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int k, sum = 0;
	cin >> N >> k;

	FinalColorUsed = true;
	sum += f(1, false, k-1) % MOD;

	memset(cache, -1, sizeof(cache));

	FinalColorUsed = false;
	sum += f(1, false, k) % MOD;

	cout << sum % MOD;
}