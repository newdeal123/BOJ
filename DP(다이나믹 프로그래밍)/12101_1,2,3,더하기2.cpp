//정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다.합을 나타낼 때는 수를 1개 이상 사용해야 한다.
//
//1 + 1 + 1 + 1
//1 + 1 + 2
//1 + 2 + 1
//2 + 1 + 1
//2 + 2
//1 + 3
//3 + 1
//이를 사전순으로 정렬하면 다음과 같이 된다.
//
//1 + 1 + 1 + 1
//1 + 1 + 2
//1 + 2 + 1
//1 + 3
//2 + 1 + 1
//2 + 2
//3 + 1
//정수 n과 k가 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법 중에서 k번째로 오는 식을 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 정수 n과 k가 주어진다.n은 양수이며 11보다 작고, k는 231 - 1보다 작거나 같은 자연수이다.
//
//출력
//n을 1, 2, 3의 합으로 나타내는 방법 중에서 사전 순으로 k번째에 오는 것을 출력한다.k번째 오는 식이 없는 경우에는 - 1을 출력한다.
#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int K, Kcount = 0;

void f(int n)
{
	if (n == 0)
	{
		Kcount++;
		if (K == Kcount)
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (i == v.size() - 1)
					cout << v[i];
				else
					cout << v[i] << "+";
			}
		}
		return;
	}

	v.push_back(1);
	f(n - 1);
	v.pop_back();
	if (n - 2 >= 0)
	{
		v.push_back(2);
		f(n - 2);
		v.pop_back();
	}
	if (n - 3 >= 0)
	{
		v.push_back(3);
		f(n - 3);
		v.pop_back();
	}
}

int main()
{
	int n;
	cin >> n >> K;
	f(n);
	if (Kcount < K)
		cout << "-1";
}