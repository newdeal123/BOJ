//n개의 같은 크기의 벽장들이 일렬로 붙어져 있고 벽장의 문은 n - 2개만이 있다.
//한 벽장 앞에 있는 문은 이웃 벽장 앞에 문이 없다면(즉, 벽장이 열려있다면) 그 벽장 앞으로 움직일 수 있다.
//
//풀어야 할 문제는 입력으로 주어지는 사용할 벽장의 순서에 따라서 벽장문을 이동하는 순서를 찾는 것이다.
//이때 벽장문의 이동횟수를 최소로 하여야 한다.입력은 다음과 같이 주어지며, 열려있는 벽장의 개수는 항상 2개이다.
//
//입력
//첫 번째 줄에 벽장의 개수를 나타내는 3보다 크고 20보다 작거나 같은 하나의 정수, 
//두 번째 줄에 초기에 열려있는 두 개의 벽장을 나타내는 두 개의 정수, 그리고 세 번째 줄에는 사용할 벽장들의 순서의 길이(최대 20),
//그리고 그 다음줄부터 사용할 벽장의 번호가 한줄에 하나씩 순서대로 주어진다.
//
//출력
//벽장문의 최소 이동횟수를 화면에 출력한다.
#include <iostream>
#include <vector>
using namespace std;
#define INF 87654321
int n, door_n, door1, door2;
int arr[22];
// int cache[22][22][22];

int min(int a, int b)
{
	return a > b ? b : a;
}

int movedoor(int idx, int d1, int d2)
{
	//기저사례 : 배열 모두 살펴봤을때 종료
	if (idx > door_n)
		return 0;

	int ret;
	return ret = min(movedoor(idx + 1, arr[idx], d2) + abs(d1 - arr[idx]), movedoor(idx + 1, d1, arr[idx]) + abs(d2 - arr[idx]));

}

int main()
{
	cin >> n >> door1 >> door2 >> door_n;
	for (int i = 1; i <= door_n; i++)
		cin >> arr[i];

	cout << movedoor(1, door1, door2);
}