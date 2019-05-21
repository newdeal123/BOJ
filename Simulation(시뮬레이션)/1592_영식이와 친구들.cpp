#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
#include <string>
#pragma warning(disable:4996)
using namespace std;
const int INF = 987654321;

int  main()
{
	int N, M, L, cnt = 0;
	cin >> N >> M >> L;
	vector <int> v(N + 1, M);
	int now = 1;
	v[1]--;
	while (true)
	{
		int next = now;
		if (v[now] == 0)
			break;
		if (v[now] % 2 == 0)
		{
			for (int i = 0; i < L; i++)
			{
				next--;
				if (next < 1)
					next = N;
			}
		}
		else
		{
			for (int i = 0; i < L; i++)
			{
				next++;
				if (next > N)
					next = 1;
			}
		}

		now = next;
		v[now]--;
		cnt++;
	}
	cout << cnt;
}