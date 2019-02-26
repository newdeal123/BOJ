//2차원 배열이 주어졌을 때(i, j) 위치부터(x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오.배열의(i, j) 위치는 i행 j열을 나타낸다.
//
//입력
//첫째 줄에 배열의 크기 N, M(1 ≤ N, M ≤ 300)이 주어진다.다음 N개의 줄에는 M개의 정수로 배열이 주어진다.
//배열에 포함되어 있는 수는 절댓값이 10, 000보다 작거나 같은 정수이다.
//그 다음 줄에는 합을 구할 부분의 개수 K(1 ≤ K ≤ 10, 000)가 주어진다.
//다음 K개의 줄에는 네 개의 정수로 i, j, x, y가 주어진다(i ≤ x, j ≤ y).
//
//출력
//K개의 줄에 순서대로 배열의 합을 출력한다.배열의 합은 32bit - int 범위를 초과하지 않는다.
#include <iostream>
using namespace std;
#define MAX_N 300

int main()
{
	int map[MAX_N + 2][MAX_N + 2];
	int N, M, t;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	cin >> t;

	while (t--)
	{
		int sum = 0;
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int i = y1; i <= y2; i++)
			for (int j = x1; j <= x2; j++)
				sum += map[i][j];

		cout << sum << endl;
	}


}