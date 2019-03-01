//정육면체 모양의 상자들이 일렬로 늘어서 있다.상자들마다 크기가 주어져 있는데, 
//앞에 있는 상자의 크기가 뒤에 있는 상자의 크기보다 작으면, 앞에 있는 상자를 뒤에 있는 상자 안에 넣을 수가 있다.
//예를 들어 앞에서부터 순서대로 크기가(1, 5, 2, 3, 7)인 5개의 상자가 있다면, 크기 1인 상자를 크기 5인 상자에 넣고, 
//다시 이 상자들을 크기 7인 상자 안에 넣을 수 있다.하지만 이렇게 상자를 넣을 수 있는 방법은 여러 가지가 있을 수 있다.
//앞의 예에서 차례대로 크기가 1, 2, 3, 7인 상자들을 선택하면 총 4개의 상자가 한 개의 상자에 들어가게 된다.
//
//상자들의 크기가 주어질 때, 한 번에 넣을 수 있는 최대의 상자 개수를 출력하는 프로그램을 작성하시오.
//
//입력
//파일의 첫 번째 줄은 상자의 개수 n(1≤n ≤1000)을 나타낸다.두 번째 줄에는 각 상자들의 크기가 순서대로 주어진다.
//
//출력
//첫째 줄에 한 줄에 넣을 수 있는 최대의 상자 개수를 출력한다.
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX_N = 1000 + 2;
int cache[MAX_N][MAX_N];
int Boxsize[MAX_N];
int n;

int Make_Box(int idx, int Last_Boxsize)
{
	if (idx > n)
		return 0;

	int &ret = cache[idx][Last_Boxsize];
	if (ret != -1)
		return ret;

	if (Last_Boxsize < Boxsize[idx])
		return ret = max(Make_Box(idx + 1, Last_Boxsize), Make_Box(idx + 1, Boxsize[idx]) + 1);
	else
		return ret = Make_Box(idx + 1, Last_Boxsize);
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> Boxsize[i];

	cout << Make_Box(1, 0);
}