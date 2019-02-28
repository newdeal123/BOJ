//N개의 정수로 이루어진 배열 A가 주어진다.이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.
//
//| A[0] - A[1] | +| A[1] - A[2] | +... + | A[N - 2] - A[N - 1] |
//
//입력
//첫째 줄에 N(3 ≤ N ≤ 8)이 주어진다.둘째 줄에는 배열 A에 들어있는 정수가 주어진다.배열에 들어있는 정수는 - 100보다 크거나 같고, 100보다 작거나 같다.
//
//출력
//첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.
#include <iostream>
#include <vector>
using namespace std;

int N;
int maxN = 0;
int arr[10];
int visited[10] = { 0, };
vector <int> v;
vector <int> v_idx;

void makeMAX()
{
	int sum = 0;
	for (int i = 0; i < (signed) v.size() - 1; i++)
		sum += abs(v[i] - v[i + 1]);

	maxN = maxN > sum ? maxN : sum;
}

void makeArr()
{
	if (v.size() == N)
	{
		makeMAX();
		return;
	}

	for (int i = 0; i < N; i++)
	{	
		if (!visited[i])
		{
			visited[i] = 1;
			v.push_back(arr[i]);
			makeArr();
			visited[i] = 0;
			v.pop_back();
		}

	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	makeArr();
	cout << maxN;
}