//자두는 자두를 좋아한다.그래서 집에 자두나무를 심어두고, 여기서 열리는 자두를 먹고는 한다.하지만 자두는 키가 작아서 자두를 따먹지는 못하고, 
//자두가 떨어질 때까지 기다린 다음에 떨어지는 자두를 받아서 먹고는 한다.자두를 잡을 때에는 자두가 허공에 있을 때 잡아야 하는데, 
//이는 자두가 말랑말랑하여 바닥에 떨어지면 못 먹을 정도로 뭉개지기 때문이다.
//
//매 초마다, 두 개의 나무 중 하나의 나무에서 열매가 떨어지게 된다.
//만약 열매가 떨어지는 순간, 자두가 그 나무의 아래에 서 있으면 자두는 그 열매를 받아먹을 수 있다.
//두 개의 나무는 그다지 멀리 떨어져 있지 않기 때문에, 자두는 하나의 나무 아래에 서 있다가 다른 나무 아래로 빠르게(1초보다 훨씬 짧은 시간에) 움직일 수 있다.
//하지만 자두는 체력이 그다지 좋지 못해서 많이 움직일 수는 없다.
//
//자두는 T(1≤T≤1, 000)초 동안 떨어지게 된다.자두는 최대 W(1≤W≤30)번만 움직이고 싶어 한다.
//매 초마다 어느 나무에서 자두가 떨어질지에 대한 정보가 주어졌을 때, 자두가 받을 수 있는 자두의 개수를 구해내는 프로그램을 작성하시오.
//자두는 1번 자두나무 아래에 위치해 있다고 한다.
//
//입력
//첫째 줄에 두 정수 T, W가 주어진다.다음 T개의 줄에는 각 순간에 자두가 떨어지는 나무의 번호가 1 또는 2로 주어진다.
//
//출력
//첫째 줄에 자두가 받을 수 있는 자두의 최대 개수를 출력한다.
#include <iostream>
using namespace std;
#define MAX_TIME 1005
#define MAX_W 32
int P[MAX_TIME]; //매시간마다 떨어지는자두의 나무배열
int T, W;			  //자두가 떨어지는시간,자두의 최대움직임수
int cache[MAX_TIME][MAX_W][3];

int max(int a, int b)
{
	int ret;
	return ret = a > b ? a : b;
}

int plum(int sec, int w, int nowtree)
{
	//기저사례1 : 시간이 다되었을때
	if (sec == T && P[sec] == nowtree)
		return 1;
	else if (sec == T && P[sec] != nowtree)
		return 0;

	int&ret = cache[sec][w][nowtree];
	if (ret != -1)
		return ret;

	if (P[sec] == nowtree)
		ret = 1;
	else
		ret = 0;

	if (w > 0 && nowtree == 1)
		ret += max(plum(sec + 1, w, nowtree), plum(sec + 1, w - 1, 2));
	else if (w > 0 && nowtree == 2)
		 ret += max(plum(sec + 1, w, nowtree), plum(sec + 1, w - 1, 1));
	else if (w == 0)
		 ret += plum(sec + 1, w, nowtree);

	//cout << "plum(" << sec << "," << w << "," << nowtree << ")=" << ret << endl;
	return ret;
}

int main()
{
	for (int i = 0; i < MAX_TIME; i++)
		for (int j = 0; j < MAX_W; j++)
			for (int k = 0; k < 3; k++)
				cache[i][j][k] = -1;

	cin >> T >> W;
	
	for (int i = 1; i <= T; i++)
		cin >> P[i];
	P[0] = 0;

	cout << plum(0, W, 1);
}