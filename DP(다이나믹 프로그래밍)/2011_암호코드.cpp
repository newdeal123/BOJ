//상근이와 선영이가 다른 사람들이 남매간의 대화를 듣는 것을 방지하기 위해서 대화를 서로 암호화 하기로 했다.그래서 다음과 같은 대화를 했다.
//
//상근: 그냥 간단히 암호화 하자.A를 1이라고 하고, B는 2로, 그리고 Z는 26으로 하는거야.
//	선영 : 그럼 안돼.만약, "BEAN"을 암호화하면 25114가 나오는데, 이걸 다시 글자로 바꾸는 방법은 여러 가지가 있어.
//	상근 : 그렇네. 25114를 다시 영어로 바꾸면, "BEAAD", "YAAD", "YAN", "YKD", "BEKD", "BEAN" 총 6가지가 나오는데, BEAN이 맞는 단어라는건 쉽게 알수 있잖아 ?
//	선영 : 예가 적절하지 않았네 ㅠㅠ 만약 내가 500자리 글자를 암호화 했다고 해봐.그 때는 나올 수 있는 해석이 정말 많은데, 그걸 언제 다해봐 ?
//	상근 : 얼마나 많은데 ?
//	선영 : 구해보자!
//	어떤 암호가 주어졌을 때, 그 암호의 해석이 몇 가지가 나올 수 있는지 구하는 프로그램을 작성하시오.
//
//	입력
//	첫째 줄에 5000자리 이하의 암호가 주어진다.
//
//	출력
//	나올 수 있는 해석의 가짓수를 구하시오.정답이 매우 클 수 있으므로, 1000000으로 나눈 나머지를 출력한다.
//
//	암호가 잘못되어 암호를 해석할 수 없는 경우에는 0을 출력한다.
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int MAX_N = 5002;
const int MOD = (int)1e6;
int cache[MAX_N];
int arr[MAX_N];
int Arrsize;

int f(int idx)
{
	if (idx == Arrsize)
		return 1;
	if (arr[idx] == 0)
		return 0;

	int& ret = cache[idx];
	if (ret != -1)
		return ret % MOD;

	if (arr[idx] * 10 + arr[idx + 1] <= 26 && idx != Arrsize - 1)
	{
		return ret = (f(idx + 1) + f(idx + 2)) % MOD;
	}
	else
		return ret = f(idx + 1) % MOD;

}

int main()
{
	memset(cache, -1, sizeof(cache));
	string s;
	cin >> s;
	Arrsize = s.size();
	for (int i = 0; i < Arrsize; i++)
		arr[i] = s[i] - '0';
	
		cout << f(0) % MOD;
}
