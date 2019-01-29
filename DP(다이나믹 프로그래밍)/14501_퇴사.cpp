//상담원으로 일하고 있는 백준이는 퇴사를 하려고 한다.
//
//오늘부터 N + 1일째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.
//
//백준이는 비서에게 최대한 많은 상담을 잡으라고 부탁을 했고, 비서는 하루에 하나씩 서로 다른 사람의 상담을 잡아놓았다.
//
//각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수 있는 금액 Pi로 이루어져 있다.
//
//상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 N(1 ≤ N ≤ 15)이 주어진다.
//
//둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1, 000)
//
//출력
//첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.

#include <iostream>

using namespace std;

int max_n; // 근무일
int T[20] = { 0, }, P[20] = { 0, };
int cache[20];


int max(int a, int b)
{
	int ret;
	return ret = a > b ? a : b;
}

int consult(int n)
{
	//cout << "test :consult(" << n << ")호출\n";

	//기저사례2: 마지막 근무일인데, 근무일수가 1일치일 경우
	if (n == max_n && T[n] == 1)
		return P[n];

	//기저사례3: 마지막 근무일인데, 근무일수가 1일치를 초과할경우
	if (n == max_n && T[n] > 1)
		return 0;

	//기저사례4: n이max_n을 초과했을경우
	if (n > max_n)
		return 0;

	//기저사례1: n일에 상담을 받을때 근무일수를 초과할때
	if (n + T[n] > max_n + 1)
		return consult(n + 1);


	int &ret = cache[n];

	if (ret != -1)
		return ret;

	return ret = max(consult(n + 1), consult(n + T[n]) + P[n]);
}

int main()
{
	for (int i = 0; i < 20; i++)
		cache[i] = -1;

	cin >> max_n;
	for (int i = 1; i <= max_n; i++)
		cin >> T[i] >> P[i];

	cout << consult(1);


}
