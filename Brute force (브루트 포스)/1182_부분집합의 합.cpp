//N개의 정수로 이루어진 집합이 있을 때, 이 집합의 공집합이 아닌 부분집합 중에서 그 집합의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1≤N≤20, | S | ≤1, 000, 000) 
//둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다.주어지는 정수의 절댓값은 100, 000을 넘지 않는다.같은 수가 여러 번 주어질 수도 있다.
//
//출력
//첫째 줄에 합이 S가 되는 부분집합의 개수를 출력한다.
#include <iostream>
using namespace std;

int target;
int N;
int arr[20 + 2];

int f(int idx, int sum)
{
	if (idx > N)
	{
		if (sum == target)
			return 1;
		else
			return 0;
	}

	return f(idx + 1, sum + arr[idx]) + f(idx + 1, sum) ;
}

int main()
{
	int cnt = 0;
	cin >> N >> target;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	//공집합 제거
	if (target == 0)
		cnt++; 
	cout << f(1, 0) - cnt;

}
