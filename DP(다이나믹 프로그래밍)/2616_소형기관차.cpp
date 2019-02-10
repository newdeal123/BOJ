//기차는 맨 앞에 있는 기관차 1대가 손님이 탄 객차 여러 칸을 끌고 간다.기관차가 고장나면 기차를 운행할 수 없게 되므로 
//최근 철도청은 기관차 고장에 대비하여 몇몇 역에 소형 기관차 3대를 배치하기로 결정하였다.
//소형 기관차는 평소에 이용하는 기관차보다 훨씬 적은 수의 객차만을 끌 수 있다.
//
//기관차가 고장났을 때 끌고 가던 객차 모두를 소형 기관차 3대가 나누어 끌 수 없기 때문에, 
//소형 기관차들이 어떤 객차들을 끌고 가는 것이 좋을까하는 문제를 고민하다가 다음과 같이 하기로 결장하였다.
//
//소형 기관차가 최대로 끌 수 있는 객차의 수를 미리 정해 놓고, 그보다 많은 수의 객차를 절대로 끌게 하지 않는다. 3
//대의 소형 기관차가 최대로 끌 수 있는 객차의 수는 서로 같다.
//소형 기관차 3대를 이용하여 최대한 많은 손님을 목적지까지 운송하도록 한다.각 객차 마다 타고 있는 손님의 수는 미리 알고 있고,
//다른 객차로 손님들이 이동하는 것은 허용하지 않는다.
//각 소형 기관차는 번호가 연속적으로 이어진 객차를 끌게 한다.객차는 기관차 바로 뒤에 있는 객차부터 시작하여 1번 부터 차례로 번호가 붙어있다.
//
//기관차가 끌고 가던 객차의 수와 각 객차에 타고 있던 손님의 수, 그리고 소형 기관차가 최대로 끌수 있는 객차의 수가 주어질 때, 
//소형 기관차 3대를 이용하여 최대로 운송할 수 있는 손님 수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 기관차가 끌고 가던 객차의 수가 입력된다.그 수는 50, 000 이하이다.
//둘째 줄에는 기관차가 끌고 가던 객차에 타고 있는 손님의 수가 1번 객차부터 차례로 입력된다.
//한 객차에 타고 있는 손님의 수는 100명 이하이고, 입력되는 숫자들 사이에 빈칸이 하나씩 있다.
//셋째 줄에는 소형 기관차가 최대로 끌 수 있는 객차의 수가 입력된다.그 수는 기관차가 끌고 가던 객차 수의 1 / 3보다 적다.
//
//출력
//한 줄에 소형 기관차 3대를 이용하여 최대로 운송할 수 있는 손님 수를 출력한다.
#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;

#define MAX  50000 + 1
int trainum;
int passenger[MAX];
int maxCarry;
int cache[3][MAX]; //몇번째 소형 기차, 현재 객차 번호

int maxPassenger(int trainNum, int idx)
{
	//기저 사례 : 소형기차는 0, 1, 2 이렇게 세개이다
	//기저 사례 : 객차 칸 수를 벗어날 경우
	if (trainNum == 3 || idx >= trainum)
		return 0;

	int &result = cache[trainNum][idx];
	if (result != -1)
		return result;
	result = 0;

	if (idx + maxCarry - 1 <= trainum) 
		result = max(maxPassenger(trainNum, idx + 1), (passenger[idx + maxCarry - 1] - passenger[idx - 1]) + maxPassenger(trainNum + 1, idx + maxCarry));
	return result;

}

int main(void)
{
	cin >> trainum;
	for (int i = 1; i <= trainum; i++)
	{
		int temp;
		cin >> temp;
		passenger[i] = passenger[i - 1] + temp;
	}

	cin >> maxCarry;

	memset(cache, -1, sizeof(cache));
	cout << maxPassenger(0, 1) << endl;
	return 0;
}