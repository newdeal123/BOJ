//1부터 34까지 수가 적힌 카드가 충분히 많이 있다.이들 중 몇 장을 일렬로 늘어놓고, 그 숫자를 차례로 적었다.
//예를 들어 아래와 같이 카드가 놓인 경우 숫자를 차례로 적으면 27123이 된다.
//
//나중에, 적어 놓은 것에 맞게 다시 카드를 늘어놓으려고 보니, 방법이 여러 가지일 수 있다는 것을 알았다.
//예를 들어 27123의 경우 아래와 같이 여섯 가지 다른 방법이 있다.
//
//카드의 숫자를 차례로 적어 놓은 것이 주어질 때, 위와 같이 그것을 가지고 
//거꾸로 카드의 배열을 찾으려고 한다.가능한 카드의 배열이 모두 몇 개인지 구하는 프로그램을 작성하시오.
//
//입력
//첫 줄에 카드의 숫자를 차례로 적어 놓은 것이 주어지며, 이것은 최대 40자 이하의 숫자로 이루어진다.
//
//출력
//첫 줄에 가능한 카드 배열이 몇 개인지를 출력한다
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int MAX_N = 40;
int arr[MAX_N + 1];
int cache[MAX_N + 1];
int N;

int f(int idx)
{
	if (idx >= N)
		return 1;
	if (arr[idx] == 0)
		return 0;
	int& ret = cache[idx];
	if (ret != -1)
		return ret;

	if (arr[idx] * 10 + arr[idx + 1] <= 34 && idx + 1 < N)
		return ret = f(idx + 1) + f(idx + 2);
	else
		return ret = f(idx + 1);
}

int main()
{
	memset(cache, -1, sizeof(cache));
	string s;
	cin >> s;
	N = s.size();
	for (int i = 0; i < s.size(); i++)
		arr[i] = s[i] - '0';
	cout << f(0);
}