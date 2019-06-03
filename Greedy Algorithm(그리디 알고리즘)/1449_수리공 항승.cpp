#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int INF = 987654321;

int main()
{
	int N, L;
	cin >> N >> L;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int tape = 1, coverd = arr[0] + L - 1;
	for (int i = 1; i < N; i++)
	{
		if (arr[i] <= coverd)
			continue;
		tape++;
		coverd = arr[i] + L - 1;
	}
	cout << tape;
}