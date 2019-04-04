//오민식은 오늘이 크리스마스라고 생각해서, 크리스마스 트리를 만들려고 한다.트리는 N개의 레벨로 이루어져 있다.
//위에서부터 레벨1, ... 레벨 N이다.또, 민식이는 빨강, 파랑, 초록색의 장난감을 가지고 있다.그리고 민식이는 이 장난감을 일정한 규칙에 의해서 장식하려고 한다.
//
//레벨 K에는 딱 K개의 장난감이 있어야 한다.또, 각 레벨에 놓으려고 선택한 색이 있으면, 그 색의 장난감의 수는 서로 같아야 한다.
//예를 들어, 레벨 3에 장난감을 놓으려고 할 때, 빨강 2, 파랑 1과 같이 놓으면, 빨강과 파랑의 수가 다르기 때문에 안된다.
//하지만, 레벨 4에 빨강 2, 파랑 2와 같이 놓으면, 가능하다.
//
//N과, 장난감의 수가 주어질 때, 트리를 장식하는 경우의 수를 출력하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 트리의 크기 N, 빨강의 개수, 초록의 개수, 파랑의 개수가 주어진다.N은 10보다 작거나 같다.빨강, 초록, 파랑의 개수는 0보다 크거나 같고, 100보다 작거나 같다.
//
//출력
//첫째 줄에 경우의 수를 출력한다.이 값은 int범위를 넘어가는 long long범위이고, 만약 주어진 장난감으로 트리를 장식할 수 없으면 0을 출력한다.

#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
ll cache[11][101][101][101];

bool canPlace(int a, int b, int c)
{
	if (a == 0)
	{
		if (b == 0 || c == 0)
			return true;
		if (b == c)
			return true;
	}
	else if (b == 0)
	{
		if (a == 0 || c == 0)
			return true;
		if (a == c)
			return true;
	}
	else if (c == 0)
	{
		if (a == 0 || b == 0)
			return true;
		if (a == b)
			return true;
	}
	else if (a == b  && b== c)
		return true;

	return false;
}

int factorial(int n)
{
	int sum = 1;
	while (n>1)
	{
		sum *= n;
		n--;
	}
	return sum;
}

int select(int a, int b, int c)
{
	return factorial(a + b + c) / factorial(a) / factorial(b) / factorial(c);
}

ll f(int level, int r, int g, int b)
{
	if (level  == 0)
		return 1;

	ll& ret = cache[level][r][g][b];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i <= r; i++)
	{
		for (int j = 0; j <= g; j++)
		{
			for (int k = 0; k <= b; k++)
			{
				if ((i + j + k) == level && canPlace(i, j, k))
					ret += f(level - 1, r - i, g - j, b - k) * select(i, j, k);
			}
		}
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int  r, g, b, N;
	cin >> N >> r >> g >> b;
	cout << f(N, r, g, b);
}